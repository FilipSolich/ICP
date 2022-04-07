#ifndef SDEDITORSCENE_H
#define SDEDITORSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "diagram.hh"
#include "sdedge.h"
#include "itemtype.hh"
#include "sequenceeditor.hh"

class SDEditorScene : public QGraphicsScene
{
public:
    SequenceEditor *editor = nullptr;
    /**
     * \brief SDEditorScene Constructor.
     * \param editor pointer on SequenceEditor
     */
    SDEditorScene(SequenceEditor *editor);;
    /**
     * @brief mouseMoveEvent Mouse MOVE event handler.
     * @param event pointer to mouse event.
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief mousePressEvent Mouse PRESS event handler.
     * @param event pointer to mouse event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SDEDITORSCENE_H
