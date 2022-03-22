#ifndef CDSOCKET_H
#define CDSOCKET_H

#include "cdsocketitem.hh"

class CDClass;
class CDEdge;

class CDSocket
{
public:
    enum class Position {
        Top,
        Right,
        Bottom,
        Left,
    };

    CDSocket(Position position, CDClass *parentCls, QGraphicsItem *parentItem);

    CDClass *parentCls = nullptr;
    CDSocketItem *item = nullptr;
    Position position;
    CDEdge *edge = nullptr;

    QPointF calculateSocketPos();
    QPointF getSocketCenter();
    void createEdge();
    void redraw(void);
};

#endif // CDSOCKET_H
