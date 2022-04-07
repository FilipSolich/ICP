#ifndef SDEDGEITEM_H
#define SDEDGEITEM_H
#include <QGraphicsPathItem>
#include "itemtype.hh"

class SDEdge;
/**
 * \brief The SDEdgeItem class
 */
class SDEdgeItem : public QGraphicsPathItem
{
public:
    SDEdge *sdEdge;
    /**
     * \brief SDEdgeItem Construcotr.
     * \param sdEdge pointer on the edge.
     */
    SDEdgeItem(SDEdge *sdEdge);
    /**
     * @brief type
     * @return ItemTypeSDEdge
     */
    int type() const { return ItemTypeSDEdge; };
};

#endif // SDEDGEITEM_H
