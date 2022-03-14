/**
 * \file fileprocessor.cc
 *
 * \brief Source code for FileProcessor class.
 *
 * \date 10. 3. 2022
 * \author Filip Solich
 */

#include <QComboBox>
#include <QTextStream>

#include "classwidget.hh"
#include "classdiagrameditor.hh"
#include "diagram.hh"
#include "fileprocessor.hh"
#include "mainwindow.hh"

#include <QDebug>

QString FileProcessor::generateFile(Diagram *diagram)
{
    this->diagram = diagram;

    QString text;
    text += genClasses();
    text += genSequences();
    return text;
}

void FileProcessor::addLine(QString &text, QString const &increment)
{
    text += increment;
    text += "\n";
}

void FileProcessor::addElement(QString &text, QString const &increment, bool leadingSpace)
{
    if (leadingSpace) {
        text += " ";
    }
    text += increment;
}

QString FileProcessor::genClasses()
{
    QString text;

    addLine(text, "start class");

    // Add class
    for (Class *cls : qAsConst(diagram->classes)) {
        QString line;

        // Add keyword
        addElement(line, "class", false);

        // Add class name
        addElement(line, "\"" + cls->getName() + "\"");

        // Add class position
        addElement(line, QString::number(cls->item->pos().x()));
        addElement(line, QString::number(cls->item->pos().y()));

        // Add attributes
        for (QWidget *attr : qAsConst(cls->widget->attributes)) {
            addElement(line, attr->findChild<QComboBox *>()->currentText());
            addElement(line, attr->findChild<QLineEdit *>("dt")->text());
            addElement(line, attr->findChild<QLineEdit *>("name")->text());
        }

        addElement(line, ":");

        // Add methods
        for (QWidget *meth : qAsConst(cls->widget->methods)) {
            addElement(line, meth->findChild<QComboBox *>()->currentText());
            addElement(line, meth->findChild<QLineEdit *>("dt")->text());
            addElement(line, meth->findChild<QLineEdit *>("name")->text());
        }

        addLine(text, line);
    }

    //TODO
    // Add connections

    addLine(text, "end class");

    return text;
}

QString FileProcessor::genSequences()
{
    QString text;

    addLine(text, "start sequence");

    for (Class *cls : qAsConst(diagram->classes)) {
        addLine(text, "participant " + cls->widget->name->text());
    }

    // TODO
    // Add connections

    addLine(text, "end sequence");

    return text;
}

Diagram *FileProcessor::parseFile(DiagramTabWidget *tabs, QString *text)
{
    QString line;
    QTextStream stream{text};

    ClassDiagramEditor *classEditor = tabs->classTab;
    QVector<SequenceDiagram *> *sequenceEditors = &(tabs->sequnceTabs);

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

    return new Diagram();
}

int FileProcessor::createClass(ClassDiagramEditor *classEditor, QString &line)
{
    QStringList args = line.split(" ");

    if (args.size() < 4 || args[0] != "class") {
        return 1;
    }

    QString name = args[1].replace("\"", "");
    QString x = args[2];
    QString y = args[3];

    Class *cls = classEditor->addClass(x.toInt(), y.toInt()); // TODO: check if x and y is interger
    cls->setName(name);

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
