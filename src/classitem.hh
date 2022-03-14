#ifndef CLASSITEM_HH
#define CLASSITEM_HH

#include <QGraphicsRectItem>

class Class;

class ClassItem : public QGraphicsRectItem
{
public:
    ClassItem(Class *parentClass, int x = 0, int y = 0);

    Class *parentClass = nullptr;

    void setWidgetSize(QRectF rect);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // CLASSITEM_HH
