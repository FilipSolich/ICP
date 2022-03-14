#include "socketitem.hh"
#include "classdiagrameditor.hh"

SocketItem::SocketItem(Socket *socket)
{
    this->socket = socket;
    QPointF point = socket->cls->getSocketPos(socket->position);

    setRect(point.x(), point.y(), _width, _heigth);

    this->socket->cls->editor->scene->addItem(this);
}
