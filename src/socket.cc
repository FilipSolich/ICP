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

QPointF Socket::getSocketPos()
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

// TODO delete old Edge
void Socket::createEdge()
{
    QGraphicsPathItem *item = parentCls->editor->scene->addPath(QPainterPath());
    item->setParentItem(this->item);
    edge = new Edge(parentCls->diagram, item, this);
}

void Socket::redraw(void)
{
    QPointF point = getSocketPos();
    item->setRect(point.x(), point.y(), SocketItem::_width, SocketItem::_heigth);
}
