#include "socketitem.hh"
#include "classdiagrameditor.hh"

SocketItem::SocketItem(Socket *socket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem)
{
    this->socket = socket;
    QPointF point = socket->getSocketPos();

    setRect(point.x(), point.y(), _width, _heigth);

    //this->socket->parentCls->editor->scene->addItem(this); // TODO: remove
}
