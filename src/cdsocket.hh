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

    static QMap<CDSocket::Position, QString> positionMap;
    static QMap<CDSocket::Position, int> positionIndexMap;

    Position position;

    CDClass *cdClass = nullptr;
    CDSocketItem *item = nullptr;
    QVector<CDEdge *> edges;

    CDSocket(Position position, CDClass *cdClass);
    ~CDSocket();

    QPointF calculateNewPos();
    QPointF getSocketCenter();
    void createEdge();
    void redraw();
    void removeEdge(CDEdge *edge);
};

#endif // CDSOCKET_H
