#ifndef SEQUENCEITEM_H
#define SEQUENCEITEM_H

#include <QGraphicsRectItem>

class SDClass;

class Sequenceitem : public QGraphicsRectItem
{
public:
    SDClass *parent_sequence = nullptr;
    Sequenceitem(SDClass *parent_sequence);
};

#endif // SEQUENCEITEM_H
