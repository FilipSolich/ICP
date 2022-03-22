#include <QGraphicsScene>

#include "diagram.hh"
#include "cdedge.hh"
#include "cdedgeitem.hh"
#include "cdeditor.hh"

#include <QDebug>

CDEdge::CDEdge(Diagram *diagram, CDSocket *s1, CDSocket *s2)
{
    this->diagram = diagram;
    this->diagram->cdEditor->currentEdge = this;

    this->item = new CDEdgeItem(this);
    s1->item->scene()->addItem(this->item);

    setSocket(s1, Type::Start);
    setSocket(s2, Type::End);
}

CDEdge::~CDEdge()
{
    item->scene()->removeItem(item);
    delete item;
    if (startSocket) {
        startSocket->edge = nullptr;
    }
    if (endSocket) {
        endSocket->edge = nullptr;
    }
}

bool CDEdge::setSocket(CDSocket *socket, Type type)
{
    if (type == Type::Start) {
        startSocket = socket;
    } else {
        endSocket = socket;
    }

    if (socket) {
        setPoint(type, socket->getSocketCenter(), socket->position);
    }

    if (type == Type::End && socket != nullptr) {
        diagram->cdEditor->currentEdge = nullptr;
        this->item->setFlag(QGraphicsItem::ItemIsSelectable);
    }

    return true;
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

void CDEdge::setPoint(Type type, QPointF point, CDSocket::Position socPos)
{
    if (type == Type::Start) {
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
    setPoint(Type::End, pos);
}

void CDEdge::socketMoved(CDSocket *s)
{
    if (s == startSocket) {
        setPoint(Type::Start, s->getSocketCenter(), s->position);
    } else {
        setPoint(Type::End, s->getSocketCenter(), s->position);
    }
}
