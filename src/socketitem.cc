#include <QGraphicsSceneMouseEvent>

#include "socketitem.hh"
#include "classdiagrameditor.hh"

SocketItem::SocketItem(Socket *socket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem)
{
    this->socket = socket;

    setFlag(QGraphicsItem::ItemIsSelectable);

    QPointF point = socket->getSocketPos();
    setRect(point.x(), point.y(), _width, _heigth);
}

void SocketItem::mousePressEvent(QGraphicsSceneMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton) {
        socket->createEdge();
    }
}
