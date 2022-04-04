/**
 * \file fileprocessor.cc
 *
 * \brief Source code for FileProcessor class.
 *
 * \date 10. 3. 2022
 * \author Filip Solich
 */

#include <QComboBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSet>
#include <QTextStream>

#include "cdclasswidget.hh"
#include "cdclassproperty.hh"
#include "cdeditor.hh"
#include "cdedge.hh"
#include "diagram.hh"
#include "fileprocessor.hh"
#include "mainwindow.hh"

QString FileProcessor::generateFile(Diagram *diagram)
{
    this->diagram = diagram;

    QJsonObject data;
    data.insert("classDiagram", genCD());
    //data.insert("sequenceDiagram", genSD());

    QJsonDocument doc{data};
    return QString{doc.toJson(QJsonDocument::Indented)};
}

QJsonObject FileProcessor::genCD()
{
    QJsonObject data;

    QSet<CDEdge *> edgesSet;
    QJsonArray classes;
    for (Class *cls : qAsConst(diagram->classes)) {
        classes.push_back(genCDClass(cls->cdClass));

        for (CDSocket *socket : qAsConst(cls->cdClass->sockets)) {
            for (CDEdge *edge : qAsConst(socket->edges)) {
                edgesSet.insert(edge);
            }
        }
    }
    data.insert("classes", classes);

    QJsonArray edges;
    for (CDEdge *edge : edgesSet) {
        edges.push_back(genCDEdge(edge));
    }
    data.insert("edges", edges);

    return data;
}

QJsonObject FileProcessor::genSD() {}

QJsonObject FileProcessor::genCDClass(CDClass *cls)
{
    QJsonObject data;

    data.insert("name", cls->widget->name->text());
    data.insert("x", cls->item->scenePos().x());
    data.insert("y", cls->item->scenePos().y());

    QJsonArray property;
    QVector<CDClassProperty *> vec = cls->widget->attributes + cls->widget->methods;
    for (CDClassProperty *prop: qAsConst(vec)) {
        property.push_back(genCDProperty(prop));
    }
    data.insert("property", property);

    return data;
}

QJsonObject FileProcessor::genCDProperty(CDClassProperty *property)
{
    QJsonObject data;

    data.insert("visibility", property->visibility->currentText());
    data.insert("dt", property->dt->text());
    data.insert("name", property->name->text());
    data.insert("attribute", property->type == CDClassProperty::Type::Attribute);

    return data;
}

QJsonObject FileProcessor::genCDEdge(CDEdge *edge)
{
    QJsonObject data;

    data.insert("type", CDEdge::typeMap[edge->type]);
    data.insert("startClass", edge->startSocket->cdClass->cls->getName());
    data.insert("endClass", edge->endSocket->cdClass->cls->getName());
    data.insert("startSocket", CDSocket::positionMap[edge->startSocket->position]);
    data.insert("endSocket", CDSocket::positionMap[edge->endSocket->position]);

    return data;
}

Diagram *FileProcessor::parseFile(DiagramTabWidget *tabs, QString *text)
{
    QString line;
    QTextStream stream{text};

    CDEditor *classEditor = tabs->classTab;
    QVector<SequenceDiagram *> *sequenceEditors = &(tabs->sequenceTabs);

    ParseState state = ParseState::NoState;
    while (stream.readLineInto(&line)) {
        if (line == "start class" && state == ParseState::NoState) {
            state = ParseState::Classes;
        } else if (line == "end class" && state == ParseState::Classes) {
            state = ParseState::NoState;
        } else if (line == "start sequence" && state == ParseState::Classes) {
            state = ParseState::Sequences;
        } else if (line == "end sequence" && state == ParseState::Sequences) {
            state = ParseState::NoState;
        } else {
            if (state == ParseState::Classes) {
                createClass(classEditor, line); // TODO: check for return
            }
        }
    }

    return new Diagram(nullptr, nullptr, mainWindow); // must be valid editors
}

int FileProcessor::createClass(CDEditor *classEditor, QString &line)
{
    QStringList args = line.split(" ");

    if (args.size() < 4 || args[0] != "class") {
        return 1;
    }

    QString name = args[1].replace("\"", "");
    QString x = args[2];
    QString y = args[3];

    diagram->addClass(QPointF(x.toInt(), y.toInt())); // TODO: check if x and y is interger
    CDClass *cls = diagram->classes.last()->cdClass;
    diagram->classes.last()->setName(name);

    if (args.size() > 4) {
        bool attributes = true;
        for (int i = 4; i < args.size(); i++) {
            if (args[i] == ":") {
                attributes = true;
            } else {
                // Attribute or method is unparsable
                if (i+2 > args.size()) {
                    return 1;
                }
                if (attributes) {
                    if (!cls->addAttribute(args[i], args[++i], args[++i])) {
                        return 1;
                    }
                } else {
                    if (!cls->addMethod(args[i], args[++i], args[++i])) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}
