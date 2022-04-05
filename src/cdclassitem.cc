/**
 * \file cdclassitem.cc
 *
 * \brief Source code file for `CDClassItem` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include "cdclass.hh"
#include "cdclassitem.hh"
#include "cdeditor.hh"
#include "cdeditorscene.hh"

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
            for (CDEdge *edge : qAsConst(s->edges)) {
                edge->socketMoved(s);
            }
        }
    }

    return QGraphicsItem::itemChange(change, value);
}
