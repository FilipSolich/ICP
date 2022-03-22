#include <QGraphicsSceneMouseEvent>

#include "diagram.hh"
#include "cdeditorscene.hh"
#include "itemtype.hh"

#include <QDebug>

CDEditorScene::CDEditorScene(Diagram *diagram, QObject *parent)
    : QGraphicsScene{parent}
{
    this->diagram = diagram;
}

void CDEditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (diagram->currentEdge) {
        diagram->currentEdge->setMousePos(event->scenePos());
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void CDEditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        bool anotherSocket = false;
        QList<QGraphicsItem *> itemsList = items(event->scenePos());
        for (QGraphicsItem *item : itemsList) {
            if (item->type() == ItemTypeSocket) {
                anotherSocket = true;
            }
        }
        if (!anotherSocket) {
            delete diagram->currentEdge;
            diagram->currentEdge = nullptr;
        }
    }

    QGraphicsScene::mousePressEvent(event);
}
