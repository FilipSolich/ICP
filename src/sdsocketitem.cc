/**
 * \file sdsocketitem.cpp
 *
 * \brief `SDSocketItem` source code of class.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#include "sdsocketitem.hh"
#include <QGraphicsSceneMouseEvent>
#include <sdeditor.hh>
#include "sdeditorscene.hh"

SDSocketItem::SDSocketItem(SDSocket *socket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem)
{
    this->sd_socket = socket;
    QPointF point_socket = socket->calculateSocketPos();
    setRect(0,0,w,h);
    setPos(point_socket.x(), point_socket.y());

}
SDSocketItem::~SDSocketItem(){};


void SDSocketItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        SDEditor *editor = static_cast<SDEditorScene *>(scene())->editor;
        if (editor->currentEdge) {
            sd_socket->edges.push_back(editor->currentEdge);
            editor->currentEdge->setSocket(sd_socket, SDEdge::EdgeEndType::End);
        } else {
            sd_socket->CreateEdge(); //tady
        }
    }

    QGraphicsEllipseItem::mousePressEvent(event);
}


