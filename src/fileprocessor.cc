/**
 * \file fileprocessor.cc
 *
 * \brief Source code for FileProcessor class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QCoreApplication>
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
    data["classDiagram"] = genCD();
    //data.insert("sequenceDiagram", genSD()); // TODO uncoment

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
    data["classes"] = classes;

    QJsonArray edges;
    for (CDEdge *edge : edgesSet) {
        edges.push_back(genCDEdge(edge));
    }
    data["edges"] = edges;

    return data;
}

QJsonObject FileProcessor::genSD()
{
    // TODO
}

QJsonObject FileProcessor::genCDClass(CDClass *cls)
{
    QJsonObject data;

    data["name"] = cls->widget->name->text();
    data["x"] = cls->item->scenePos().x();
    data["y"] = cls->item->scenePos().y();

    QJsonArray property;
    QVector<CDClassProperty *> vec = cls->widget->attributes + cls->widget->methods;
    for (CDClassProperty *prop: qAsConst(vec)) {
        property.push_back(genCDProperty(prop));
    }
    data["property"] = property;

    return data;
}

QJsonObject FileProcessor::genCDProperty(CDClassProperty *property)
{
    QJsonObject data;

    data["visibility"] = property->visibility->currentText();
    data["dt"] = property->dt->text();
    data["name"] = property->name->text();
    data["attribute"] = property->type == CDClassProperty::Type::Attribute;

    return data;
}

QJsonObject FileProcessor::genCDEdge(CDEdge *edge)
{
    QJsonObject data;

    data["type"] = CDEdge::typeMap[edge->type];
    data["startClass"] = edge->startSocket->cdClass->cls->getName();
    data["endClass"] = edge->endSocket->cdClass->cls->getName();
    data["startSocket"] = CDSocket::positionMap[edge->startSocket->position];
    data["endSocket"] = CDSocket::positionMap[edge->endSocket->position];

    return data;
}

Diagram *FileProcessor::parseFile(DiagramTabWidget *tabs, QString *text)
{
    diagram = new Diagram(tabs->classTab, &tabs->sequenceTabs, mainWindow);

    QJsonObject data = QJsonDocument::fromJson(text->toUtf8()).object();

    parseCD(data["classDiagram"].toObject());

    // TODO add parse SD

    return diagram;
}

void FileProcessor::parseCD(QJsonObject data)
{
    QJsonArray classes = data["classes"].toArray();
    for (QJsonValue const &cls : qAsConst(classes)) {
        createClass(cls.toObject());
    }

    QJsonArray edges = data["edges"].toArray();
    for (QJsonValue const &edge : qAsConst(edges)) {
        createCDEdge(edge.toObject());
    }
}

void FileProcessor::createClass(QJsonObject data)
{
    QString name{data["name"].toString()};
    QPointF pos{data["x"].toDouble(), data["y"].toDouble()};
    CDClass *cls = diagram->addClass(name, pos)->cdClass;

    QCoreApplication::processEvents(QEventLoop::AllEvents);

    QJsonArray property = data["property"].toArray();
    for (QJsonValue const &propVal: qAsConst(property)) {
        QJsonObject prop = propVal.toObject();
        CDClassProperty::Type type = prop["attribute"].toBool() ? CDClassProperty::Type::Attribute : CDClassProperty::Type::Method;
        cls->widget->addProperty(type, prop["visibility"].toString(), prop["dt"].toString(), prop["name"].toString());
    }
}

void FileProcessor::createCDEdge(QJsonObject data)
{
    QString startClsName{data["startClass"].toString()};
    QString endClsName{data["endClass"].toString()};
    CDSocket::Position startPos = CDSocket::positionMap.key(data["startSocket"].toString());
    CDSocket::Position endPos = CDSocket::positionMap.key(data["endSocket"].toString());

    CDSocket *startSocket = nullptr;
    CDSocket *endSocket = nullptr;

    for (Class *cls : qAsConst(diagram->classes)) {
        if (startClsName == cls->getName()) {
            startSocket = cls->cdClass->sockets[CDSocket::positionIndexMap[startPos]];
        } else if (endClsName == cls->getName()) {
            endSocket = cls->cdClass->sockets[CDSocket::positionIndexMap[endPos]];
        }
    }

    if (!startSocket || !endSocket) {
        return;
    }

    CDEdge *edge = new CDEdge(data["type"].toString(), startSocket, endSocket);
    startSocket->edges.push_back(edge);
    endSocket->edges.push_back(edge);
}
