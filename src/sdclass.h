#ifndef SDCLASS_H
#define SDCLASS_H

#include <QWidget>

#include "sdsocket.h"
#include "sequenceitem.h"
#include "sequencewidget.h"
class SequenceEditor;
class Class;

class SDClass
{

public:

    QGraphicsProxyWidget *seq_proxy = nullptr;
    SequenceEditor *diagram;

    Class *cls = nullptr;

    Sequenceitem *item = nullptr;
    SequenceWidget *widget = nullptr;
    SDSocket *sockets[18];
    QPointF position;
    SDClass(SequenceEditor *diagram = nullptr , Class *cls = nullptr);
    ~SDClass();

    void redrawSockets(void);


};

#endif // SDCLASS_H
