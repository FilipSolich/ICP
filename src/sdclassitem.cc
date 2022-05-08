/**
 * \file sequenceitem.cpp
 *
 * \brief `Sequenceitem` source code of that class.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#include "sdclassitem.hh"
#include "sdeditor.hh"
#include "sdclass.hh"
SDClassItem::SDClassItem(SDClass *parent_sequence)
{
    this->parent_sequence = parent_sequence;

    setRect(0,0,100,300);

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    this->parent_sequence->diagram->sequence_scene->addItem(this);

}

QVariant SDClassItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
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
