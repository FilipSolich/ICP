/**
 * \file cdedgeitem.hh
 *
 * \brief Header file for `CDEdgeItem` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDEDGEITEM_H
#define CDEDGEITEM_H

#include <QGraphicsPathItem>

#include "itemtype.hh"

class CDEdge;

/**
 * Class represent graphics item for `CDEdge`.
 */
class CDEdgeItem : public QGraphicsPathItem
{
public:
    CDEdge *cdEdge;

    /**
     * Constructor.
     *
     * \param cdEdge Pointer to `CDEdge` object.
     */
    CDEdgeItem(CDEdge *cdEdge);

    /**
     * Returns type of item.
     *
     * \return Type of item.
     */
    int type() const { return ItemTypeCDEdge; };
};

#endif // CDEDGEITEM_H
