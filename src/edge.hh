#ifndef EDGE_HH
#define EDGE_HH

#include <QGraphicsPathItem>
#include <QPoint>

#include "socket.hh"

class Diagram;

class Edge
{
public:
    enum class Type {START, END};

    static const int MAX_SOCKETS = 2;
    static const int C_DISTANCE = 30;
    Diagram *diagram = nullptr;
    Socket *sockets[2] = {nullptr, nullptr};
    QGraphicsPathItem *item = nullptr;

    QPointF startPoint;
    QPointF endPoint;
    QPointF c1;
    QPointF c2;

    Edge(Diagram *diagram, QGraphicsPathItem *item, Socket *s1 = nullptr, Socket *s2 = nullptr);

    bool setSocket(int idx, Socket *socket);
    QPointF calculateC(QPointF point, Socket::Position socPos);
    void setPoint(Type type, QPointF point, Socket::Position socPos = Socket::Position::Right);
    void setPath();
    void setMousePos(QPoint pos);
};

#endif // EDGE_HH
