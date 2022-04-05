/**
 * \file itemtype.hh
 *
 * \brief Header file for `ItemType` enum.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <QGraphicsItem>

/** Enum for custom graphics item types */
enum ItemType {
    ItemTypeCDClass  = QGraphicsItem::UserType + 1,
    ItemTypeCDSocket = QGraphicsItem::UserType + 2,
    ItemTypeCDEdge   = QGraphicsItem::UserType + 3,
};

#endif // ITEMTYPE_H
