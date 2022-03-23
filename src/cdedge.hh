#ifndef CDEDGE_H
#define CDEDGE_H

#include <QPoint>

#include "cdsocket.hh"
#include "cdedgeitem.hh"

class Diagram;

class CDEdge
{
public:
    enum class Type {Start, End};

    static const int C_DISTANCE = 30;

    CDEdgeItem *item = nullptr;

    CDSocket *startSocket = nullptr;
    CDSocket *endSocket = nullptr;

    QPointF startPoint;
    QPointF endPoint;
    QPointF c1;
    QPointF c2;

    CDEdge(CDSocket *s1, CDSocket *s2 = nullptr);
    ~CDEdge();

    void setSocket(CDSocket *socket, Type type);
    QPointF calculateC(QPointF point, CDSocket::Position socPos);
    void setPoints(Type type, QPointF point, CDSocket::Position socPos = CDSocket::Position::Right);
    void setPath();
    void setMousePos(QPointF pos);
    void socketMoved(CDSocket *s);
};

#endif // CDEDGE_H
