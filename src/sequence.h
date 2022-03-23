#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QWidget>

#include "sdsocket.h"
#include "sequenceitem.h"
#include "sequencewidget.h"
class SequenceDiagram;

class Sequence
{

public:

    QGraphicsProxyWidget *seq_proxy = nullptr;
    SequenceDiagram *diagram;
    Sequenceitem *item = nullptr;
    SequenceWidget *widget = nullptr;
    SDSocket *sockets[9];
    Sequence(QString name = "Class", SequenceDiagram *diagram = nullptr);
    ~Sequence();

    void redrawSockets(void);


};

#endif // SEQUENCE_H
