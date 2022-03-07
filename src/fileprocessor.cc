/**
 * \file fileprocessor.cc
 *
 * \brief Source code for FileProcessor class.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#include <QComboBox>

#include "class.hh"
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

    for (Class *cls : diagram->classes) {
        addLine(text, "participant " + cls->name->text());
    }

    addLine(text, "end sequence");

    return text;
}

QString FileProcessor::genClasses()
{
    QString text;

    addLine(text, "start class");

    // Add class
    for (Class *cls : diagram->classes) {
        QString line;

        addElement(line, "class");
        addElement(line, cls->name->text());

        // Add attributes
        for (QWidget *attr : cls->attributes) {
            addElement(line, attr->findChild<QComboBox *>()->currentText());
            addElement(line, attr->findChild<QLineEdit *>("dt")->text());
            addElement(line, attr->findChild<QLineEdit *>("name")->text());
        }

        addElement(line, ":");

        // Add methods
        for (QWidget *meth : cls->methods) {
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
    return new Diagram();
}
