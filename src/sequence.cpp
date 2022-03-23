#include "sequence.h"

#include "sdsocket.h"
#include "sdsocketitem.h"
#include "sequenceitem.h"
#include "sequencewidget.h"
#include "sequencediagram.hh"
#include <QGraphicsProxyWidget>
#include "cdclassitem.hh"




Sequence::Sequence(QString name, SequenceDiagram *diagram)
    : diagram{diagram}
{
    item = new Sequenceitem(this);
    widget = new SequenceWidget(this ,name);

    seq_proxy = diagram->sequence_scene->addWidget(widget);
    seq_proxy->setPos(0,0);
    seq_proxy->setParentItem(item);

    sockets[0] = new SDSocket(0,this,item);
    sockets[1] = new SDSocket(1,this,item);
    sockets[2] = new SDSocket(2,this,item);
    sockets[3] = new SDSocket(3,this,item);
    sockets[4] = new SDSocket(4,this,item);
    sockets[5] = new SDSocket(5,this,item);
    sockets[6] = new SDSocket(6,this,item);
    sockets[7] = new SDSocket(7,this,item);
    sockets[8] = new SDSocket(8,this,item);
}

void Sequence::redrawSockets(void)
{
    for (SDSocket *s : sockets)
    {
        s->redraw();
    }
}

Sequence::~Sequence()
{
    diagram->sequence_scene->removeItem(item);
    delete seq_proxy;
    delete item;
}
