#ifndef SDSOCKET_H
#define SDSOCKET_H

#include "sdsocketitem.h"

class Sequence;

class SDSocket
{

public:
    SDSocket(int position,Sequence *parent_sequence, QGraphicsItem *parentItem);

    int position;
    Sequence *parent_sequence = nullptr;
    SDSocketItem *item = nullptr;

    QPointF calculateSocketPos();
    void redraw(void);
};

#endif // SDSOCKET_H
