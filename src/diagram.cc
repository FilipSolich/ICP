/**
 * \file diagram.cc
 *
 * \brief Source code for Diagram class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#include "diagram.hh"

Diagram::Diagram() {}

void Diagram::createClass(CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors)
{
    Class *cls = new Class(this, cdEditor, sqEditors);
    classes.push_back(cls);
}
