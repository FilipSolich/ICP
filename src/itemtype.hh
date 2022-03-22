#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <QGraphicsItem>

enum ItemType {
    ItemTypeCDClass = QGraphicsItem::UserType + 1,
    ItemTypeCDSocket = QGraphicsItem::UserType + 2,
    ItemTypeCDEdge = QGraphicsItem::UserType + 3,
};

#endif // ITEMTYPE_H
