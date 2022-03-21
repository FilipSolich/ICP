#ifndef EDGEITEM_HH
#define EDGEITEM_HH

#include <QGraphicsPathItem>

#include "itemtype.hh"

class Edge;

class EdgeItem : public QGraphicsPathItem
{
public:
    Edge *parentCls;

    EdgeItem(Edge *parentCls);

    int type() const { return ItemTypeEdge; };
};

#endif // EDGEITEM_HH
