/**
 * \file diagram.cc
 *
 * \brief Source code for Diagram class.
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

void Diagram::addClass(QPointF pos)
{
    Class *cls = new Class(this, cdEditor, sqEditors, QPoint(-500,0));
    classes.push_back(cls);
    cls = new Class(this, cdEditor, sqEditors, QPoint(0,0));
    classes.push_back(cls);
}
