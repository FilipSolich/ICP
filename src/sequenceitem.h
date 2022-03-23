#ifndef SEQUENCEITEM_H
#define SEQUENCEITEM_H

#include <QGraphicsRectItem>
class Sequence;

class Sequenceitem : public QGraphicsRectItem
{
public:
    Sequence *parent_sequence = nullptr;
    Sequenceitem(Sequence *parent_sequence);
};

#endif // SEQUENCEITEM_H
