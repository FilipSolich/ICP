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

class FileProcessor
{
public:
    FileProcessor();

    static QString generateFile(void);
    static void parseFile(QString &text);
};

#endif // FILEPROCESSOR_HH
