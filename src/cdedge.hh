#ifndef CDEDGE_H
#define CDEDGE_H

#include <QPoint>

#include "cdsocket.hh"
#include "cdedgeitem.hh"

class Diagram;

class CDEdge
{
public:
    enum class EdgeEndType {Start, End};
    enum class Type {Association, Aggregation, Composition, Generalization};

    static const int C_DISTANCE = 70;

    static QMap<CDEdge::Type, QString> typeMap;

    CDEdgeItem *item = nullptr;

    CDSocket *startSocket = nullptr;
    CDSocket *endSocket = nullptr;
    Type type;

    QPointF startPoint;
    QPointF endPoint;
    QPointF c1;
    QPointF c2;

    CDEdge(QString type = "Association", CDSocket *s1 = nullptr, CDSocket *s2 = nullptr);
    ~CDEdge();

    void setSocket(CDSocket *socket, EdgeEndType type);
    QPointF calculateC(QPointF point, CDSocket::Position socPos);
    void setPoints(EdgeEndType type, QPointF point, CDSocket::Position socPos = CDSocket::Position::Right);
    void setPath();
    void setMousePos(QPointF pos);
    void socketMoved(CDSocket *s);
};

#endif // CDEDGE_H
