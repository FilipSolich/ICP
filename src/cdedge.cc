#include <QGraphicsScene>

#include "cdedge.hh"
#include "cdedgeitem.hh"
#include "cdeditor.hh"

CDEdge::CDEdge(QString type, CDSocket *s1, CDSocket *s2)
{
    this->type = typeMap[type];

    item = new CDEdgeItem(this);
    s1->item->scene()->addItem(item);

    setSocket(s1, EdgeEndType::Start);
    setSocket(s2, EdgeEndType::End);

    this->startSocket->cdClass->editor->currentEdge = this;
}

CDEdge::~CDEdge()
{
    item->scene()->removeItem(item);
    delete item;
    if (startSocket) {
        startSocket->removeEdge(this);
    }
    if (endSocket) {
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
