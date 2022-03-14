#include "socket.hh"
#include "socketitem.hh"

Socket::Socket(Class *cls, Position position)
{
    this->cls = cls;
    this->position = position;
    this->item = new SocketItem(this);
}

void Socket::moveTo(QPointF point)
{
    item->setRect(point.x(), point.y(), SocketItem::_width, SocketItem::_heigth);
}
