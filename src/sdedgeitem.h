#ifndef SDEDGEITEM_H
#define SDEDGEITEM_H
#include <QGraphicsPathItem>
#include "itemtype.hh"

class SDEdge;
class SDEdgeItem : public QGraphicsPathItem
{
public:
    SDEdge *sdEdge;
    SDEdgeItem(SDEdge *sdEdge);

    int type() const { return ItemTypeSDEdge; };
};

#endif // SDEDGEITEM_H
