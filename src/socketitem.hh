#ifndef SOCKETITEM_HH
#define SOCKETITEM_HH

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>

class Socket;

class SocketItem : public QGraphicsEllipseItem
{
    // Q_OBJECT // TODO: Remove if SocketItem doesnt use signal or slots

public:
    static const int _width = 10;
    static const int _heigth = 10;

    SocketItem(Socket *socket, QGraphicsItem *parentItem = nullptr);

    Socket *socket = nullptr;
};

#endif // SOCKETITEM_HH
