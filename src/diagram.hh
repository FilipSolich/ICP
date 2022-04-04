/**
 * \file diagram.hh
 *
 * \brief Diagram is top class for evry open diagrams.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#ifndef DIAGRAM_HH
#define DIAGRAM_HH

#include <QPointF>
#include <QVector>

#include "mainwindow.hh"

class Class;
class CDEditor;
class SequenceDiagram;

class Diagram
{

public:
    bool unsavedChanges = false; // TODO deal with unsaved changes

    CDEditor *cdEditor = nullptr;
    QVector<SequenceDiagram *> *sqEditors = nullptr;
    MainWindow *mainWindow = nullptr;

    QVector<Class *> classes;

    Diagram(CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors, MainWindow *mainWindow);
    ~Diagram();

    Class *addClass(QString name = "", QPointF pos = {0, 0});
};

#endif // DIAGRAM_HH
