#ifndef SOCKETITEM_HH
#define SOCKETITEM_HH

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>

#include "itemtype.hh"

class Socket;

class SocketItem : public QGraphicsEllipseItem
{
    // Q_OBJECT // TODO: Remove if SocketItem doesnt use signal or slots

public:
    static const int _width = 10;
    static const int _heigth = 10;

    SocketItem(Socket *socket, QGraphicsItem *parentItem = nullptr);

    Socket *parentCls = nullptr;

    int type() const { return ItemTypeSocket; };

    void mousePressEvent(QGraphicsSceneMouseEvent *ev);
};

#endif // SOCKETITEM_HH
