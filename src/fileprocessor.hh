/**
 * \file fileprocessor.hh
 *
 * \brief Class for reading diagram content from file or
 *        writing diagram content into file.
 *
 * \date 8. 3. 2022
 * \author Filip Solich
 */

#ifndef FILEPROCESSOR_HH
#define FILEPROCESSOR_HH

#include <QString>

#include "diagram.hh"
#include "diagramtabwidget.hh"

class FileProcessor
{
    Diagram *diagram = nullptr;
    MainWindow *mainWindow = nullptr;

    QString genSequences();
    QString genClasses();
    void addLine(QString &text, QString const &increment);
    void addElement(QString &text, QString const &increment, bool leadingSpace = true);
    int createClass(CDEditor *classEditor, QString &line);

public:
    FileProcessor(MainWindow *mainWindow) : mainWindow{mainWindow} {};

    enum class ParseState {
        NoState,
        Classes,
        Sequences,
    };

    QString generateFile(Diagram *diagram);
    Diagram *parseFile(DiagramTabWidget *tabs, QString *text);
};

#endif // FILEPROCESSOR_HH
