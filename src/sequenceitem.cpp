#include "sequenceitem.h"
#include "sequencediagram.hh"
#include "sequence.h"
Sequenceitem::Sequenceitem(Sequence *parent_sequence)
{
    this->parent_sequence = parent_sequence;

    setRect(0,0,200,300);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setFlag(QGraphicsItem::ItemIsFocusable);

    this->parent_sequence->diagram->sequence_scene->addItem(this);
}
