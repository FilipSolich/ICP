#include "sdclass.h"

#include "sdsocket.h"
#include "sdsocketitem.h"
#include "sequenceitem.h"
#include "sequencewidget.h"
#include "sequenceeditor.hh"
#include <QGraphicsProxyWidget>
#include "cdclassitem.hh"




SDClass::SDClass(QString name, SequenceEditor *diagram, QPointF position,Class *cls)
    : diagram{diagram}, cls{cls}
{
    item = new Sequenceitem(this);
    widget = new SequenceWidget(this ,name);

    this->position = position;
    seq_proxy = diagram->sequence_scene->addWidget(widget);
    seq_proxy->setParentItem(item);
    item->setPos(position);

    for (int i = 0 ; i < 18; ++i)
    {
        if( i > 8){
            sockets[i] = new SDSocket(i-27,this,item);
        }
        else{
            sockets[i] = new SDSocket(i,this,item);
        }
    }
}

void SDClass::redrawSockets(void)
{

    for (SDSocket *s : sockets)
    {
        s->redraw();
    }
}





SDClass::~SDClass()
{
    diagram->sequence_scene->removeItem(item);
    delete seq_proxy;
    delete item;
}
