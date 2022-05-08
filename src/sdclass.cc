/**
 * \file sdclass.h
 *
 * \brief `SDClass` source code of class.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#include "sdclass.hh"
#include "sdsocket.hh"
#include "sdsocketitem.hh"
#include "sdclassitem.hh"
#include "sdclasswidget.hh"
#include "sdeditor.hh"
#include <QGraphicsProxyWidget>
#include "cdclassitem.hh"

#include "class.hh"

SDClass::SDClass(SDEditor *diagram,Class *cls,QPointF position)
    : diagram{diagram}, cls{cls}
{
    item = new SDClassItem(this);
    widget = new SequenceWidget(this ,cls->name);

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
    for(SDSocket *socket : qAsConst(sockets))
    {
        if(socket != nullptr)
            delete socket;
    }
    diagram->sequence_scene->removeItem(item);
    delete seq_proxy;
    delete item;
}
