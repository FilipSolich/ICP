#include "class.hh"
#include "classdiagrameditor.hh"
#include "classitem.hh"


ClassItem::ClassItem(Class *parentClass)
{
    this->parentClass = parentClass;

    setRect(0, 0, this->parentClass->widget->width(), this->parentClass->widget->height());
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    this->parentClass->editor->scene->addItem(this);
}

void ClassItem::setWidgetSize(QRectF rect)
{
    setRect(rect);
}
