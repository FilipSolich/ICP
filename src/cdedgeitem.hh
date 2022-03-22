#ifndef CDEDGEITEM_H
#define CDEDGEITEM_H

#include <QGraphicsPathItem>

#include "itemtype.hh"

class CDEdge;

class CDEdgeItem : public QGraphicsPathItem
{
public:
    CDEdge *parentCls;

    CDEdgeItem(CDEdge *parentCls);

    int type() const { return ItemTypeCDEdge; };
};

#endif // CDEDGEITEM_H
