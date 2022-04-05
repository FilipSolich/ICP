/**
 * \file cdeditorscene.cc
 *
 * \brief Source code file for `CDEditorScene` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QGraphicsSceneMouseEvent>

#include "diagram.hh"
#include "cdeditorscene.hh"
#include "itemtype.hh"

CDEditorScene::CDEditorScene(CDEditor *editor)
    : editor{editor}
{}

void CDEditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (editor->currentEdge) {
        editor->currentEdge->setMousePos(event->scenePos());
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void CDEditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
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
