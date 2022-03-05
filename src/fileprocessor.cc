/**
 * \file fileprocessor.cc
 *
 * \brief Source code for FileProcessor class.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#include "diagram.hh"
#include "fileprocessor.hh"

FileProcessor::FileProcessor(){}

QString *FileProcessor::generateFile(Diagram &diagram)
{
    return new QString("str");
}

Diagram *FileProcessor::parseFile(QString &text)
{
    return new Diagram();
}
