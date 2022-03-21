#include "class.hh"
#include "classdiagrameditor.hh"
#include "socket.hh"
#include "socketitem.hh"

Socket::Socket(Position position, Class *parentCls, QGraphicsItem *parentItem)
{
    this->position = position;
    this->parentCls = parentCls;
    this->item = new SocketItem(this, parentItem);
}

QPointF Socket::calculateSocketPos()
{
    int x, y;

    switch (position) {
        case Socket::Position::Top:
            x = parentCls->item->rect().width() / 2;
            y = 0 - (SocketItem::_heigth / 2);
            break;
        case Socket::Position::Right:
            x = parentCls->item->rect().width() - (SocketItem::_width / 2);
            y = parentCls->item->rect().height() / 2;
            break;
        case Socket::Position::Bottom:
            x = parentCls->item->rect().width() / 2;
            y = parentCls->item->rect().height() - (SocketItem::_heigth / 2);
            break;
        case Socket::Position::Left:
            x = 0 - (SocketItem::_width / 2);
            y = parentCls->item->rect().height() / 2;
            break;
    }

    return QPointF(x, y);
}

QPointF Socket::getSocketCenter()
{
    QPointF point = item->scenePos();
    point.setX(point.x() + SocketItem::_width / 2);
    point.setY(point.y() + SocketItem::_heigth/ 2);
    return point;
}

void Socket::createEdge()
{
    edge = new Edge(parentCls->diagram, this);
}

void Socket::redraw(void)
{
    QPointF point = calculateSocketPos();
    item->setPos(point.x(), point.y());
}
