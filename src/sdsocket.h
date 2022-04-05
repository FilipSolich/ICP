#ifndef SDSOCKET_H
#define SDSOCKET_H

#include "sdsocketitem.h"
#include "sdedge.h"

class SDClass;

class SDSocket
{

public:
    SDSocket(int position,SDClass *parent_sequence, QGraphicsItem *parentItem);

    int position;
    SDClass *parent_sequence = nullptr;
    SDSocketItem *item = nullptr;
    QVector<SDEdge *> edges;

    QPointF calculateSocketPos();
    void redraw(void);
    void redraw(int x);
    QPointF getSocketCenter(void);
    void CreateEdge();
    //void RemoveEdge(SDEdge *edge);
};

#endif // SDSOCKET_H
