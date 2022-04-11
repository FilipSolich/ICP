#include "sequenceitem.h"
#include "sequenceeditor.hh"
#include "sdclass.h"
Sequenceitem::Sequenceitem(SDClass *parent_sequence)
{
    this->parent_sequence = parent_sequence;

    setRect(0,0,100,300);

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    this->parent_sequence->diagram->sequence_scene->addItem(this);

}

QVariant Sequenceitem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange)
    {
        for (SDSocket *s : qAsConst(parent_sequence->sockets))
        {
           for (SDEdge *edge : qAsConst(s->edges))
           {
                edge->socketMoved(s);
           }
        }
    }

    return QGraphicsItem::itemChange(change, value);
}
