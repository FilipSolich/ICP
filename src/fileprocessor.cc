/**
 * \file fileprocessor.cc
 *
 * \brief Source code for FileProcessor class.
 *
 * \date 8. 3. 2022
 * \author Filip Solich
 */

#include <QComboBox>
#include <QTextStream>

#include "classwidget.hh"
#include "diagram.hh"
#include "fileprocessor.hh"

FileProcessor::FileProcessor(){}

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

void FileProcessor::addElement(QString &text, QString const &increment)
{
    text += " ";
    text += increment;
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

QString FileProcessor::genClasses()
{
    QString text;

    addLine(text, "start class");

    // Add class
    for (Class *cls : qAsConst(diagram->classes)) {
        QString line;

        addElement(line, "class");
        addElement(line, cls->widget->name->text());

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

Diagram *FileProcessor::parseFile(QString *text)
{
    QString line;
    QTextStream stream{text};

    while (stream.readLineInto(&line)) {
        // TODO
    }

    return new Diagram();
}
