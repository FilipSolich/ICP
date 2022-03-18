#include "diagram.hh"
#include "edge.hh"

#include <QDebug>

Edge::Edge(Diagram *diagram, QGraphicsPathItem *item, Socket *s1, Socket *s2)
{
    this->diagram = diagram;
    this->diagram->currentEdge = this;

    this->item = item;

    setSocket(0, s1);
    setSocket(1, s2);
}

bool Edge::setSocket(int idx, Socket *socket)
{
    if (idx < 0 || idx > MAX_SOCKETS - 1) {
        return false;
    }

    sockets[idx] = socket;

    if (socket) {
        qDebug() << socket->item->pos();
        qDebug() << socket->item->scenePos();
        qDebug() << socket->item->parentItem()->pos();
        qDebug() << socket->item->parentItem()->scenePos();
        Type type = idx == 0 ? Type::START : Type::END;
        //setPoint(type, socket->item->scenePos(), socket->position);
        setPoint(type, socket->getSocketPos(), socket->position);
    }

    if (idx == MAX_SOCKETS - 1 && socket != nullptr) {
        diagram->currentEdge = nullptr;
    }

    return true;
}

QPointF Edge::calculateC(QPointF point, Socket::Position socPos)
{
    QPointF c{point};
    switch (socPos) {
        case Socket::Position::Top:
            c.setY(c.y() + C_DISTANCE);
            break;
        case Socket::Position::Right:
            c.setX(c.x() + C_DISTANCE);
            break;
        case Socket::Position::Bottom:
            c.setY(c.y() - C_DISTANCE);
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

void Edge::setMousePos(QPoint pos)
{
    setPoint(Type::END, pos);
}
