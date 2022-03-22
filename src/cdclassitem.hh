#ifndef CDCLASSITEM_H
#define CDCLASSITEM_H

#include <QGraphicsRectItem>

#include "itemtype.hh"

class CDClass;

class CDClassItem : public QGraphicsRectItem
{
public:
    CDClass *cdClass = nullptr;

    CDClassItem(CDClass *cdClass, QPointF pos);

    int type() const { return ItemTypeCDClass; };

    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);
};

#endif // CDCLASSITEM_H
