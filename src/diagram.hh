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

#include "class.hh"
#include "edge.hh"

class Diagram
{

public:
    bool unsavedChanges = false; // TODO deal with unsaved changes
    Edge *currentEdge = nullptr;
    QVector<Class *> classes;

    Diagram();
};

#endif // DIAGRAM_HH
