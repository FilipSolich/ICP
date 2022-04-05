/**
 * \file cdeditor.hh
 *
 * \brief `CDEditor` class representing editor for class diagrams.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDEDITOR_H
#define CDEDITOR_H

#include <QWidget>
#include <QGraphicsView>

#include "cdedge.hh"

class CDEditorScene;

/**
 * Widget for class diagram editor.
 */
class CDEditor : public QWidget
{
public:
    QGraphicsView *view = nullptr;
    CDEditorScene *scene = nullptr;

    CDEdge *currentEdge = nullptr;

    /**
     * Constructor.
     *
     * \param parent Pointer to parent widget.
     */
    CDEditor(QWidget *parent = nullptr);
};

#endif // CDEDITOR_H
