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

QPointF CDSocket::calculateNewPos()
{
    QPointF pos;

    switch (position) {
        case CDSocket::Position::Top:
            pos.setX(cdClass->item->rect().width() / 2);
            pos.setY(0 - (_heigth / 2));
            break;
        case CDSocket::Position::Right:
            pos.setX(cdClass->item->rect().width() - (_width / 2));
            pos.setY(cdClass->item->rect().height() / 2);
            break;
        case CDSocket::Position::Bottom:
            pos.setX(cdClass->item->rect().width() / 2);
            pos.setY(cdClass->item->rect().height() - (_heigth / 2));
            break;
        case CDSocket::Position::Left:
            pos.setX(0 - (_width / 2));
            pos.setY(cdClass->item->rect().height() / 2);
            break;
    }

    return pos;
}

QPointF CDSocket::getSocketCenter()
{
    QPointF point = item->scenePos();
    point.setX(point.x() + _width / 2);
    point.setY(point.y() + _heigth / 2);
    return point;
}

void CDSocket::createEdge()
{
    edge = new CDEdge(cdClass->cls->diagram, this);
}

void CDSocket::redraw()
{
    QPointF pos = calculateNewPos();
    item->setPos(pos);

    if (edge) {
        edge->socketMoved(this);
    }
}
