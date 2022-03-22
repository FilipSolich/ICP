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

#include <QVector>

#include "cdclass.hh"
#include "cdedge.hh"
#include "class.hh"

class SequenceDiagram;

class Diagram
{

public:
    bool unsavedChanges = false; // TODO deal with unsaved changes
    CDEdge *currentEdge = nullptr; // TODO move to editor
    QVector<CDClass *> cdClasses; // TODO remove
    QVector<Class *> classes;

    Diagram();

    void createClass(CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors);
};

#endif // DIAGRAM_HH
