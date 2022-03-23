#ifndef CDSOCKET_H
#define CDSOCKET_H

#include "cdsocketitem.hh"
#include "class.hh"

class CDEdge;

class CDSocket
{
public:
    static const int _width = 10;
    static const int _heigth = 10;

    enum class Position {Top, Right, Bottom, Left };

    Position position;

    CDClass *cdClass = nullptr;
    CDSocketItem *item = nullptr;
    CDEdge *edge = nullptr;

    CDSocket(Position position, CDClass *cdClass);
    ~CDSocket();

    QPointF calculateNewPos();
    QPointF getSocketCenter();
    void createEdge();
    void redraw();
};

#endif // CDSOCKET_H
