#ifndef CDCLASSITEM_H
#define CDCLASSITEM_H

#include <QGraphicsRectItem>

#include "itemtype.hh"

class CDClass;

class CDClassItem : public QGraphicsRectItem
{
public:
    CDClass *parentCls = nullptr;

    CDClassItem(CDClass *parentCls, int x = 0, int y = 0);

    int type() const { return ItemTypeClass; };
    void setWidgetSize(QRectF rect);

    // Events
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);
};

#endif // CDCLASSITEM_H
