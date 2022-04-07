#ifndef SEQUENCEITEM_H
#define SEQUENCEITEM_H

#include <QGraphicsRectItem>
#include "itemtype.hh"
class SDClass;

class Sequenceitem : public QGraphicsRectItem
{
public:
    SDClass *parent_sequence = nullptr;

    Sequenceitem(SDClass *parent_sequence);
    int type() const {return ItemTypeSDClass;};

    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);
};

#endif // SEQUENCEITEM_H
