/**
 * \file sdeditorscene.h
 *
 * \brief `SDEditorScene` class representing editor for scene.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#ifndef SDEDITORSCENE_H
#define SDEDITORSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "diagram.hh"
#include "sdedge.hh"
#include "itemtype.hh"
#include "sdeditor.hh"

class SDEditorScene : public QGraphicsScene
{
public:
    SDEditor *editor = nullptr;

    /**
     * \brief SDEditorScene Constructor.
     * \param editor pointer on SequenceEditor
     */

    SDEditorScene(SDEditor *editor);;
    /**
     * \brief mouseMoveEvent Mouse MOVE event handler.
     * \param event pointer to mouse event.
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /**
     * \brief mousePressEvent Mouse PRESS event handler.
     * \param event pointer to mouse event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SDEDITORSCENE_H
