#ifndef SOCKET_HH
#define SOCKET_HH

#include "socketitem.hh"

class Class;
class Edge;

class Socket
{
public:
    enum class Position {
        Top,
        Right,
        Bottom,
        Left,
    };

    Socket(Position position, Class *parentCls, QGraphicsItem *parentItem);

    Class *parentCls = nullptr;
    SocketItem *item = nullptr;
    Position position;
    Edge *edge = nullptr;

    QPointF calculateSocketPos();
    QPointF getSocketCenter();
    void createEdge();
    void redraw(void);
};

#endif // SOCKET_HH
