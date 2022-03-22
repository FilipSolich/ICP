#ifndef CDSOCKET_H
#define CDSOCKET_H

#include "cdsocketitem.hh"
#include "class.hh"

class CDEdge;

class CDSocket
{
public:
    enum class Position {Top, Right, Bottom, Left };

    Position position;

    CDClass *cdClass = nullptr;
    CDSocketItem *item = nullptr;
    CDEdge *edge = nullptr;

    CDSocket(Position position, CDClass *cdClass, QGraphicsItem *parentItem);

    QPointF calculateSocketPos();
    QPointF getSocketCenter();
    void createEdge();
    void redraw();
};

#endif // CDSOCKET_H
