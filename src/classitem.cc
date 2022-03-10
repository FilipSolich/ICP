#include "class.hh"
#include "classdiagrameditor.hh"
#include "classitem.hh"


ClassItem::ClassItem(Class *parentClass, int x, int y)
{
    this->parentClass = parentClass;

    setRect(x, y, this->parentClass->widget->width(), this->parentClass->widget->height());
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    this->parentClass->editor->scene->addItem(this);
}

void ClassItem::setWidgetSize(QRectF rect)
{
    setRect(rect);
}
