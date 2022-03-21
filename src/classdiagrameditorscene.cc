#include <QGraphicsSceneMouseEvent>

#include "diagram.hh"
#include "classdiagrameditorscene.hh"

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
