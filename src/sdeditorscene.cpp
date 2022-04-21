#include "sdeditorscene.h"
#include "sdedge.h"

SDEditorScene::SDEditorScene(SequenceEditor *editor)
    : editor {editor}
{}

void SDEditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (editor->currentEdge) {
        if(editor->currentEdge->type == SDEdge::Type::Activate)
        {
             editor->currentEdge->setMousePosActivate(event->scenePos());
        }
        else{
            editor->currentEdge->setMousePos(event->scenePos());
        }
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void SDEditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        bool anotherSocket = false;
        QList<QGraphicsItem *> itemsList = items(event->scenePos());
        for (QGraphicsItem *item : itemsList) {
            if (item->type() == ItemTypeCDSocket) {
                anotherSocket = true;
            }
        }
        if (!anotherSocket) {
            delete editor->currentEdge;
            editor->currentEdge = nullptr;
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

