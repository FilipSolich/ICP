#include "sequencemsg.h"
#include "sequencediagram.hh"

SequenceMsg::SequenceMsg(SequenceDiagram *parentDiagram)
{
    //this->parentDiagram = nullptr;

}

void SequenceMsg::draw_async()
{
    //todo
}
void SequenceMsg::draw_sync()
{

}
void SequenceMsg::draw_destroy()
{

}

void SequenceMsg::draw_create()
{

}


void SequenceMsg::draw_async_slot(void)
{
    draw_async();
}
void SequenceMsg::draw_sync_slot(void)
{
    draw_sync();
}
void SequenceMsg::draw_create_slot(void)
{
    draw_create();
}
void SequenceMsg::draw_destroy_slot(void)
{
    draw_destroy();
}
