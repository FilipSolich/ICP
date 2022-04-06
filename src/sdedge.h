#ifndef SDEDGE_H
#define SDEDGE_H

#include <QPoint>
#include "sdsocket.h"
#include "sdedgeitem.h"

class Diagram;

class SDEdge
{
public:
    enum class EdgeEndType {Start, End};
    enum class Type {Async,Sync,Create,Destroy};

    std::map<QString, Type> typeMap = {
        {"Async", Type::Async},
        {"Sync", Type::Sync},
        {"Create", Type::Create},
        {"Destroy", Type::Destroy},
    };

    //SDEdgeItem *item = nullptr;

    SDSocket *startSocket = nullptr;
    SDSocket *endSocket = nullptr;
    Type type;
    SDEdgeItem *item = nullptr;
    QPointF startPoint;
    QPointF endPoint;
    QPointF c1;
    QPointF c2;

    SDEdge(QString type="async", SDSocket *s1 = nullptr, SDSocket *s2 = nullptr );
    ~SDEdge();
    void setSocket(SDSocket *socket, EdgeEndType type);
    void setPath();
    void setMousePos(QPointF pos);
    void socketMoved(SDSocket *s);
    void setPoints(EdgeEndType type, QPointF point);


};

#endif // SDEDGE_H
