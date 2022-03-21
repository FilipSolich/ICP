#ifndef EDGE_HH
#define EDGE_HH

#include <QPoint>

#include "socket.hh"
#include "edgeitem.hh"

class Diagram;

class Edge
{
public:
    enum class Type {Start, End};

    static const int MAX_SOCKETS = 2;
    static const int C_DISTANCE = 30;

    Diagram *diagram = nullptr;
    Socket *startSocket = nullptr;
    Socket *endSocket = nullptr;
    EdgeItem *item = nullptr;

    QPointF startPoint;
    QPointF endPoint;
    QPointF c1;
    QPointF c2;

    Edge(Diagram *diagram, Socket *s1, Socket *s2 = nullptr);
    ~Edge();

    bool setSocket(Socket *socket, Type type);
    QPointF calculateC(QPointF point, Socket::Position socPos);
    void setPoint(Type type, QPointF point, Socket::Position socPos = Socket::Position::Right);
    void setPath();
    void setMousePos(QPointF pos);
    void socketMoved(Socket *s);
};

#endif // EDGE_HH
