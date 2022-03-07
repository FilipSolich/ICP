/**
 * \file fileprocessor.hh
 *
 * \brief Header file for FileProcessor class.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#ifndef FILEPROCESSOR_HH
#define FILEPROCESSOR_HH

#include <QString>

#include "diagram.hh"

class FileProcessor
{
    Diagram *diagram = nullptr;

    QString genSequences();
    QString genClass();

public:
    FileProcessor();

    QString generateFile(Diagram *diagram);
    Diagram *parseFile(QString *text);

};

#endif // FILEPROCESSOR_HH
