/**
 * \file cdsocket.cc
 *
 * \brief Source code file for `CDSocket` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include "cdclass.hh"
#include "cdedge.hh"
#include "cdsocket.hh"
#include "cdsocketitem.hh"
#include "diagram.hh"


QMap<CDSocket::Position, QString> CDSocket::positionMap = {
    {CDSocket::Position::Top, "Top"},
    {CDSocket::Position::Right, "Right"},
    {CDSocket::Position::Bottom, "Bottom"},
    {CDSocket::Position::Left, "Left"},
};

QMap<CDSocket::Position, int> CDSocket::positionIndexMap = {
    {CDSocket::Position::Top, 0},
    {CDSocket::Position::Right, 1},
    {CDSocket::Position::Bottom, 2},
    {CDSocket::Position::Left, 3},
};

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
            pos.setY(0 - (_height / 2));
            break;
        case CDSocket::Position::Right:
            pos.setX(cdClass->item->rect().width() - (_width / 2));
            pos.setY(cdClass->item->rect().height() / 2);
            break;
        case CDSocket::Position::Bottom:
            pos.setX(cdClass->item->rect().width() / 2);
            pos.setY(cdClass->item->rect().height() - (_height / 2));
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
    point.setY(point.y() + _height / 2);
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
