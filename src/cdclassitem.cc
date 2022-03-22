#include <QGraphicsSceneDragDropEvent>

#include "cdclass.hh"
#include "cdeditor.hh"
#include "cdeditorscene.hh"
#include "cdclassitem.hh"

#include <QDebug>

CDClassItem::CDClassItem(CDClass *cdClass, QPointF pos)
    : cdClass{cdClass}
{
    setRect(0, 0, cdClass->widget->width(), cdClass->widget->height());
    setPos(pos);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

    cdClass->editor->scene->addItem(this);
}

QVariant CDClassItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
        for (CDSocket *s : qAsConst(cdClass->sockets)) {
            if (s->edge) {
                s->edge->socketMoved(s);
            }
        }
    }

    return QGraphicsItem::itemChange(change, value);
}
