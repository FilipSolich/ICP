/**
 * \file diagram.cc
 *
 * \brief Source code for `Diagram` class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#include "class.hh"
#include "diagram.hh"

Diagram::Diagram(CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors, MainWindow *mainWindow)
    : cdEditor{cdEditor},
      sqEditors{sqEditors},
      mainWindow{mainWindow}
{}

Diagram::~Diagram()
{
    QVector<Class *> test = classes;
    for (Class *cls : qAsConst(test)) {
        delete cls;
    }
}

Class *Diagram::addClass(QString name, QPointF pos)
{
    Class *cls = new Class(this, cdEditor, sqEditors, name, pos);
    classes.push_back(cls);
    return cls;
}
