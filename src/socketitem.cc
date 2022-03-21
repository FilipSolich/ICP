#include <QGraphicsSceneMouseEvent>

#include "socketitem.hh"
#include "classdiagrameditor.hh"

#include <QDebug>

SocketItem::SocketItem(Socket *socket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem)
{
    this->parentCls = socket;

    QPointF point = socket->calculateSocketPos();
    setRect(0, 0, _width, _heigth);
    setPos(point.x(), point.y());
}

void SocketItem::mousePressEvent(QGraphicsSceneMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton) {
        if (parentCls->parentCls->diagram->currentEdge) {
            parentCls->edge = parentCls->parentCls->diagram->currentEdge;
            parentCls->parentCls->diagram->currentEdge->setSocket(parentCls, Edge::Type::End);
        } else {
            parentCls->createEdge();
        }
    }
}
