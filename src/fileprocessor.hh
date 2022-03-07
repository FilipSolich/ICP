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
    QString genClasses();
    void addLine(QString &text, QString const &increment);
    void addElement(QString &text, QString const &increment);

public:
    FileProcessor();

    QString generateFile(Diagram *diagram);
    Diagram *parseFile(QString *text);

};

#endif // FILEPROCESSOR_HH
