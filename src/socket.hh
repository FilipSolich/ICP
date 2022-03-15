#ifndef SOCKET_HH
#define SOCKET_HH

#include "socketitem.hh"

class Class;

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

    QPointF getSocketPos();
    void redraw(void);
};

#endif // SOCKET_HH
