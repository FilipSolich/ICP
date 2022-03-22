#include "cdclass.hh"
#include "cdeditor.hh"
#include "cdsocket.hh"
#include "cdsocketitem.hh"

CDSocket::CDSocket(Position position, CDClass *cdClass, QGraphicsItem *parentItem)
    : position{position},
      cdClass{cdClass}
{
    item = new CDSocketItem(this, parentItem);
}

QPointF CDSocket::calculateSocketPos()
{
    int x, y;

    switch (position) {
        case CDSocket::Position::Top:
            x = cdClass->item->rect().width() / 2;
            y = 0 - (CDSocketItem::_heigth / 2);
            break;
        case CDSocket::Position::Right:
            x = cdClass->item->rect().width() - (CDSocketItem::_width / 2);
            y = cdClass->item->rect().height() / 2;
            break;
        case CDSocket::Position::Bottom:
            x = cdClass->item->rect().width() / 2;
            y = cdClass->item->rect().height() - (CDSocketItem::_heigth / 2);
            break;
        case CDSocket::Position::Left:
            x = 0 - (CDSocketItem::_width / 2);
            y = cdClass->item->rect().height() / 2;
            break;
    }

    return QPointF(x, y);
}

QPointF CDSocket::getSocketCenter()
{
    QPointF point = item->scenePos();
    point.setX(point.x() + CDSocketItem::_width / 2);
    point.setY(point.y() + CDSocketItem::_heigth/ 2);
    return point;
}

void CDSocket::createEdge()
{
    edge = new CDEdge(cdClass->cls->diagram, this);
}

void CDSocket::redraw(void)
{
    QPointF point = calculateSocketPos();
    item->setPos(point.x(), point.y());
}
