/**
 * \file fileprocessor.cc
 *
 * \brief Source code for FileProcessor class.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#include "class.hh"
#include "diagram.hh"
#include "fileprocessor.hh"

FileProcessor::FileProcessor(){}

QString FileProcessor::generateFile(Diagram *diagram)
{
    this->diagram = diagram;

    QString text;
    text += genClass();
    text += genSequences();
    return text;
}

QString FileProcessor::genSequences()
{
    QString text;
    text += "start sequence";

    for (Class *w: diagram->classes) {
        text += "participant " + w->name->text();
    }

    text += "end sequence";
}

QString FileProcessor::genClass() {}

Diagram *FileProcessor::parseFile(QString *text)
{
    return new Diagram();
}
