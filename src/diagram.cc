/**
 * \file diagram.cc
 *
 * \brief Source code for Diagram class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#include "diagram.hh"

Diagram::Diagram(CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors)
    : cdEditor{cdEditor},
      sqEditors{sqEditors}
{}

void Diagram::addClass(QPointF pos)
{
    Class *cls = new Class(this, cdEditor, sqEditors, pos);
    classes.push_back(cls);
}
