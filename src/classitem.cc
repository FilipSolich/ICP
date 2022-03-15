#include "class.hh"
#include "classdiagrameditor.hh"
#include "classitem.hh"

ClassItem::ClassItem(Class *parentCls, int x, int y)
{
    this->parentCls = parentCls;

    setRect(x, y, this->parentCls->widget->width(), this->parentCls->widget->height());
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    this->parentCls->editor->scene->addItem(this);
}

void ClassItem::setWidgetSize(QRectF rect)
{
    setRect(rect);
}

// TODO: remove
// QVariant ClassItem::itemChange(GraphicsItemChange change, const QVariant &value)
// {
//     if (change == ItemPositionChange || change == ItemPositionHasChanged) {
//         parentCls->moved(pos());
//     }
//     return QGraphicsItem::itemChange(change, value);
// }
