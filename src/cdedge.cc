/**
 * \file cdedge.cc
 *
 * \brief Source code file for `CDEdge` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QGraphicsScene>

#include "cdedge.hh"
#include "cdedgeitem.hh"
#include "cdeditor.hh"

QMap<CDEdge::Type, QString> CDEdge::typeMap = {
    {CDEdge::Type::Association, "Association"},
    {CDEdge::Type::Aggregation, "Aggregation"},
    {CDEdge::Type::Composition, "Composition"},
    {CDEdge::Type::Generalization, "Generalization"},
};

CDEdge::CDEdge(QString type, CDSocket *s1, CDSocket *s2)
{
    this->type = CDEdge::typeMap.key(type);

    item = new CDEdgeItem(this);
    s1->item->scene()->addItem(item);

    setSocket(s1, EdgeEndType::Start);
    setSocket(s2, EdgeEndType::End);

    if (!s2) {
        this->startSocket->cdClass->editor->currentEdge = this;
    }
}

CDEdge::~CDEdge()
{
    item->scene()->removeItem(item);
    delete item;
    if (startSocket) {
        if (type == Type::Generalization) {
            startSocket->cdClass->removeHeredity(endSocket->cdClass, true);
        }
        startSocket->removeEdge(this);
    }
    if (endSocket) {
        if (type == Type::Generalization) {
            endSocket->cdClass->removeHeredity(startSocket->cdClass, false);
        }
        endSocket->removeEdge(this);
    }
}

void CDEdge::setSocket(CDSocket *socket, EdgeEndType type)
{
    if (type == EdgeEndType::Start) {
        startSocket = socket;
    } else {
        endSocket = socket;
    }

    if (socket) {
        setPoints(type, socket->getSocketCenter(), socket->position);
    } else if (type == EdgeEndType::End) {
        setPoints(type, startSocket->getSocketCenter(), startSocket->position);
    }

    if (type == EdgeEndType::End && socket != nullptr) {
        startSocket->cdClass->editor->currentEdge = nullptr;
        this->item->setFlag(QGraphicsItem::ItemIsSelectable);
    }
}

QPointF CDEdge::calculateC(QPointF point, CDSocket::Position socPos)
{
    QPointF c{point};
    switch (socPos) {
        case CDSocket::Position::Top:
            c.setY(c.y() - C_DISTANCE);
            break;
        case CDSocket::Position::Right:
            c.setX(c.x() + C_DISTANCE);
            break;
        case CDSocket::Position::Bottom:
            c.setY(c.y() + C_DISTANCE);
            break;
        case CDSocket::Position::Left:
            c.setX(c.x() - C_DISTANCE);
            break;
    }

    return c;
}

void CDEdge::setPoints(EdgeEndType type, QPointF point, CDSocket::Position socPos)
{
    if (type == EdgeEndType::Start) {
        startPoint = point;
        c1 = calculateC(point, socPos);
    } else {
        endPoint = point;
        c2 = calculateC(point, socPos);
    }

    setPath();
}

void CDEdge::setPath()
{
    QPainterPath path{startPoint};
    path.cubicTo(c1, c2, endPoint);
    item->setPath(path);
}

void CDEdge::setMousePos(QPointF pos)
{
    setPoints(EdgeEndType::End, pos);
}

void CDEdge::socketMoved(CDSocket *s)
{
    if (s == startSocket) {
        setPoints(EdgeEndType::Start, s->getSocketCenter(), s->position);
    } else {
        setPoints(EdgeEndType::End, s->getSocketCenter(), s->position);
    }
}
