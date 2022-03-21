#include <QGraphicsSceneMouseEvent>

#include "socketitem.hh"
#include "classdiagrameditor.hh"

#include <QDebug>

SocketItem::SocketItem(Socket *socket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem)
{
    this->socket = socket;

    QPointF point = socket->calculateSocketPos();
    setRect(0, 0, _width, _heigth);
    setPos(point.x(), point.y());
}

void SocketItem::mousePressEvent(QGraphicsSceneMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton) {
        if (socket->parentCls->diagram->currentEdge) {
            socket->edge = socket->parentCls->diagram->currentEdge;
            socket->parentCls->diagram->currentEdge->setSocket(socket, Edge::Type::END);
        } else {
            socket->createEdge();
        }
    }
}
