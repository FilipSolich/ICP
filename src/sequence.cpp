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

    for (int i = 0 ; i < 9; ++i)
    {
        sockets[i] = new SDSocket(i,this,item);
        sockets[i] = new SDSocket(i-18,this,item);
    }
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
