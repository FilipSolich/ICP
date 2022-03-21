#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <QGraphicsItem>

enum ItemType {
    ItemTypeClass = QGraphicsItem::UserType + 1,
    ItemTypeSocket = QGraphicsItem::UserType + 2,
    ItemTypeEdge = QGraphicsItem::UserType + 3,
};

enum class DiagramType {
    ClassDiagram,
    SequenceDiagram,
};

#endif // ITEMTYPE_H
