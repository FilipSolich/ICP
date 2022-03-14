#ifndef SOCKETITEM_HH
#define SOCKETITEM_HH

#include <QGraphicsEllipseItem>

class Socket;

class SocketItem : public QGraphicsEllipseItem
{
    // Q_OBJECT // TODO: Remove if SocketItem doesnt use signal or slots

    int _width = 10;
    int _heigth = 10;

public:
    SocketItem(Socket *socket);

    Socket *socket = nullptr;
};

#endif // SOCKETITEM_HH
