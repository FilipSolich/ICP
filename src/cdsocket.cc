#include "cdclass.hh"
#include "cdedge.hh"
#include "cdsocket.hh"
#include "cdsocketitem.hh"
#include "diagram.hh"

CDSocket::CDSocket(Position position, CDClass *cdClass)
    : position{position},
      cdClass{cdClass}
{
    item = new CDSocketItem(this, cdClass->item);
}

CDSocket::~CDSocket()
{
    for (CDEdge *edge : qAsConst(edges)) {
        delete edge;
    }
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
    edges.push_back(new CDEdge(cdClass->cls->diagram->mainWindow->edgeComboBox->currentText(), this));
}

void CDSocket::redraw()
{
    QPointF pos = calculateNewPos();
    item->setPos(pos);

    for (CDEdge *edge : qAsConst(edges)) {
        edge->socketMoved(this);
    }
}

void CDSocket::removeEdge(CDEdge *edge)
{
    edges.remove(edges.indexOf(edge));
}
