#include "sdsocketitem.h"
#include <QGraphicsSceneMouseEvent>
#include <sequencediagram.hh>

SDSocketItem::SDSocketItem(SDSocket *socket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem)
{
    this->parent_sequence = socket;
    QPointF point_socket = socket->calculateSocketPos();
    setRect(0,0,w,h);
    setPos(point_socket.x(), point_socket.y());

}
SDSocketItem::~SDSocketItem(){};

/*
void SDSocketItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(parrent_sequecne->parent_sequence->sequence->currentEdge)
        {
            parent_sequence->edge = parent_sequence->parent_sequence->sequence->currentEdge;
            parent_sequence->parent_sequence->sequence->currentEdge->setSocket(parent_sequence, EDge::Type::End);

        }
        else
        {
            parent_sequence->createEdge();
        }

    }
}

*/
