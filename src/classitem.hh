#ifndef CLASSITEM_HH
#define CLASSITEM_HH

#include <QGraphicsRectItem>

class Class;

class ClassItem : public QGraphicsRectItem
{
public:
    ClassItem(Class *parentClass);

    Class *parentClass = nullptr;
};

#endif // CLASSITEM_HH
