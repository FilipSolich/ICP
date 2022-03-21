#include <QGraphicsSceneMouseEvent>

#include "diagram.hh"
#include "classdiagrameditorscene.hh"
#include "itemtype.hh"

#include <QDebug>

ClassDiagramEditorScene::ClassDiagramEditorScene(Diagram *diagram, QObject *parent)
    : QGraphicsScene{parent}
{
    this->diagram = diagram;
}

void ClassDiagramEditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *ev)
{
    if (diagram->currentEdge) {
        diagram->currentEdge->setMousePos(ev->scenePos());
    }

    QGraphicsScene::mouseMoveEvent(ev);
}

void ClassDiagramEditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
        if (!item || (item && item->type() != ItemTypeSocket)) {
            delete diagram->currentEdge;
            diagram->currentEdge = nullptr;
        }
    }

    QGraphicsScene::mousePressEvent(event);
}
