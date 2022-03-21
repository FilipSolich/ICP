#include "diagram.hh"
#include "edge.hh"

#include <QDebug>

Edge::Edge(Diagram *diagram, QGraphicsPathItem *item, Socket *s1, Socket *s2)
{
    this->diagram = diagram;
    this->diagram->currentEdge = this;

    this->item = item;
    //this->item->setFlag(QGraphicsItem::ItemIsSelectable);

    setSocket(s1, Type::START);
    setSocket(s2, Type::END);
}

bool Edge::setSocket(Socket *socket, Type type)
{
    if (type == Type::START) {
        startSocket = socket;
    } else {
        endSocket = socket;
    }

    if (socket) {
        setPoint(type, socket->getSocketCenter(), socket->position);
    }

    if (type == Type::END && socket != nullptr) {
        diagram->currentEdge = nullptr;
        this->item->setFlag(QGraphicsItem::ItemIsSelectable);
    }

    return true;
}

QPointF Edge::calculateC(QPointF point, Socket::Position socPos)
{
    QPointF c{point};
    switch (socPos) {
        case Socket::Position::Top:
            c.setY(c.y() - C_DISTANCE);
            break;
        case Socket::Position::Right:
            c.setX(c.x() + C_DISTANCE);
            break;
        case Socket::Position::Bottom:
            c.setY(c.y() + C_DISTANCE);
            break;
        case Socket::Position::Left:
            c.setX(c.x() - C_DISTANCE);
            break;
    }

    return c;
}

void Edge::setPoint(Type type, QPointF point, Socket::Position socPos)
{
    if (type == Type::START) {
        startPoint = point;
        c1 = calculateC(point, socPos);
    } else {
        endPoint = point;
        c2 = calculateC(point, socPos);
    }

    setPath();
}

void Edge::setPath()
{
    QPainterPath path{startPoint};
    path.cubicTo(c1, c2, endPoint);
    item->setPath(path);
}

void Edge::setMousePos(QPointF pos)
{
    setPoint(Type::END, pos);
}

void Edge::socketMoved(Socket *s)
{
    if (s == startSocket) {
        setPoint(Type::START, s->getSocketCenter(), s->position);
    } else {
        setPoint(Type::END, s->getSocketCenter(), s->position);
    }
}
