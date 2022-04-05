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
    SDEditorScene(SequenceEditor *editor);;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SDEDITORSCENE_H
