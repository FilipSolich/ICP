#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <QGraphicsItem>

enum ItemType {
    ItemTypeCDClass = QGraphicsItem::UserType + 1,
    ItemTypeCDSocket = QGraphicsItem::UserType + 2,
    ItemTypeCDEdge = QGraphicsItem::UserType + 3,

    ItemTypeSDClass = QGraphicsItem::UserType + 4,
    ItemTypeSDSocket = QGraphicsItem::UserType + 5,
    ItemTypeSDEdge = QGraphicsItem::UserType + 6,
};

#endif // ITEMTYPE_H
