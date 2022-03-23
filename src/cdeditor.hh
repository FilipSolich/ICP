/**
 * \file classdiagrameditor.hh
 *
 * \brief ClassDiagramEditor class representing editor for class diagrams.
 *
 * \date 8. 4. 2022
 * \author Filip Solich
 */

#ifndef CDEDITOR_H
#define CDEDITOR_H

#include <QWidget>
#include <QGraphicsView>

#include "cdedge.hh"

class CDEditorScene;

class CDEditor : public QWidget
{
public:
    QGraphicsView *view = nullptr;
    CDEditorScene *scene = nullptr;

    CDEdge *currentEdge = nullptr;

    CDEditor(QWidget *parent = nullptr);
};

#endif // CDEDITOR_H
