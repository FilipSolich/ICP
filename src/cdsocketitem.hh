/**
 * \file cdsocketitem.hh
 *
 * \brief Header file for `CDSocketItem` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDSOCKETITEM_H
#define CDSOCKETITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>

#include "itemtype.hh"

class CDSocket;

/**
 * This class represent `CDClassSocket` graphic item in scene.
 */
class CDSocketItem : public QGraphicsEllipseItem
{
public:
    CDSocket *cdSocket = nullptr;

    /**
     * Constructor create new socket graphics item in `CDEditor`.
     *
     * \param cdSocket Pointer to `CDSocket`.
     * \param parentItem Pointer to parent item.
     */
    CDSocketItem(CDSocket *cdSocket, QGraphicsItem *parentItem = nullptr);

    /**
     * Get type of item.
     *
     * \return Type of item.
     */
    int type() const { return ItemTypeCDSocket; };

    /**
     * Mouse press event handler.
     * Create new edges or connect this socket to currentry created edge.
     *
     * \param event Pointer to event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CDSOCKETITEM_H
