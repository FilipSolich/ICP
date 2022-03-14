#ifndef SOCKETITEM_HH
#define SOCKETITEM_HH

#include <QGraphicsEllipseItem>

class Socket;

class SocketItem : public QGraphicsEllipseItem
{
    // Q_OBJECT // TODO: Remove if SocketItem doesnt use signal or slots


public:
    SocketItem(Socket *socket);

    static const int _width = 10;
    static const int _heigth = 10;

    Socket *socket = nullptr;
};

#endif // SOCKETITEM_HH
