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

    Socket(Class *cls, Position position);

    Class *cls = nullptr;
    SocketItem *item = nullptr;
    Position position;

    void moveTo(QPointF point);
};

#endif // SOCKET_HH
