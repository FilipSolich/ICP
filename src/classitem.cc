#include <QGraphicsSceneDragDropEvent>

#include "class.hh"
#include "classdiagrameditor.hh"
#include "classitem.hh"

#include <QDebug>

ClassItem::ClassItem(Class *parentCls, int x, int y)
{
    this->parentCls = parentCls;

    setRect(x, y, this->parentCls->widget->width(), this->parentCls->widget->height());
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

    this->parentCls->editor->scene->addItem(this);
}

void ClassItem::setWidgetSize(QRectF rect)
{
    setRect(rect);
}

QVariant ClassItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
        for (Socket *s : parentCls->sockets) {
            if (s->edge) {
                s->edge->socketMoved(s);
            }
        }
    }

    return QGraphicsItem::itemChange(change, value);
}
