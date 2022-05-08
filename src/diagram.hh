/**
 * \file diagram.hh
 *
 * \brief Header file for `Diagram` class.
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
class SDEditor;

/**
 * Diagram class contains pointers on all classes.
 */
class Diagram
{

public:
    bool unsavedChanges = false; // TODO deal with unsaved changes

    CDEditor *cdEditor = nullptr;
    QVector<SDEditor *> *sqEditors = nullptr;
    MainWindow *mainWindow = nullptr;

    QVector<Class *> classes; /** Pointers on all classes */

    Diagram(CDEditor *cdEditor, QVector<SDEditor *> *sqEditors, MainWindow *mainWindow);
    ~Diagram();

    /**
     * Function adds new class to diagram.
     *
     * \param name Name of new class.
     * \param pos New class postion in scene.
     */
    Class *addClass(QString name = "", QPointF pos = {0, 0});
};

#endif // DIAGRAM_HH
