#include <QGraphicsSceneDragDropEvent>

#include "cdclass.hh"
#include "cdeditor.hh"
#include "cdclassitem.hh"

#include <QDebug>

CDClassItem::CDClassItem(CDClass *parentCls, int x, int y)
{
    this->parentCls = parentCls;

    setRect(x, y, this->parentCls->widget->width(), this->parentCls->widget->height());
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

    this->parentCls->editor->scene->addItem(this);
}

void CDClassItem::setWidgetSize(QRectF rect)
{
    setRect(rect);
}

QVariant CDClassItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
        for (CDSocket *s : parentCls->sockets) {
            if (s->edge) {
                s->edge->socketMoved(s);
            }
        }
    }

    return QGraphicsItem::itemChange(change, value);
}
