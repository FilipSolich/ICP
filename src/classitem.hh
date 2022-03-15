#ifndef CLASSITEM_HH
#define CLASSITEM_HH

#include <QGraphicsRectItem>

class Class;

class ClassItem : public QGraphicsRectItem
{
public:
    Class *parentCls = nullptr;

    ClassItem(Class *parentCls, int x = 0, int y = 0);

    void setWidgetSize(QRectF rect);
    // QVariant itemChange(GraphicsItemChange change, const QVariant &value); // TODO: remove
};

#endif // CLASSITEM_HH
