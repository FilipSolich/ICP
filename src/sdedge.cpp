/**
 * \file sdedge.h
 *
 * \brief `SDEdge` source code of class.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#include <QGraphicsScene>
#include "sdedge.h"
#include "sequenceeditor.hh"
#include "sdeditorscene.h"
#include "sdedgeitem.h"

QMap<SDEdge::Type, QString> SDEdge::typeMap = {
    {SDEdge::Type::Async, "Async"},
    {SDEdge::Type::Sync, "Sync"},
    {SDEdge::Type::Destroy, "Destroy"},
    {SDEdge::Type::Create, "Create"},
    {SDEdge::Type::Back, "Back"},
    {SDEdge::Type::Activate, "Activate"},
};

SDEdge::SDEdge(QString type, SDSocket *s1, SDSocket *s2 )
{
    this->type = SDEdge::typeMap.key(type);

    item = new SDEdgeItem(this);
    s1->item->scene()->addItem(item);

    setSocket(s1,EdgeEndType::Start);
    setSocket(s2, EdgeEndType::End);

    if(!s2){
        this->startSocket->parent_sequence->diagram->currentEdge = this;
    }
}

SDEdge::~SDEdge(){
    item->scene()->removeItem(item);
    delete item;
    if(startSocket){
        startSocket->removeEdge(this);
    }
    else{
        endSocket->removeEdge(this);
    }
}

void SDEdge::setSocket(SDSocket *socket, EdgeEndType type)
{
    if( type == EdgeEndType::Start )
    {
        startSocket = socket;
    }
    else
    {
        endSocket = socket;
    }
    if(socket)
    {
        setPoints(type,socket->getSocketCenter());
    }
    if ( type == EdgeEndType::End && socket != nullptr)
    {
        startSocket->parent_sequence->diagram->currentEdge = nullptr;
        this->item->setFlag(QGraphicsItem::ItemIsSelectable);
        this->item->setFlag(QGraphicsItem::ItemIsFocusable);
    }
}
void SDEdge::setMousePosActivate(QPointF pos)
{
    QPointF p = pos;

    setPoints(EdgeEndType::End,p);
}

void SDEdge::setMousePos(QPointF pos)
{
    setPoints(EdgeEndType::End, pos);
}

void SDEdge::setPoints(EdgeEndType type, QPointF point)
{
    if (type == EdgeEndType::Start) {
        startPoint = point;

    } else {
        endPoint = point;
    }
    if(this->type == Type::Activate)
        setActPath();

    else
        setPath();
}

void SDEdge::setPath()
{

    QPainterPath arrow{startPoint};
    arrow.lineTo(endPoint);
    item->setPath(arrow);

}

void SDEdge::setActPath(){
    QPointF s = startPoint;
    QPointF e = endPoint;
    if(this->startSocket->position >= 0)
    {
        s.setX(s.rx()-50);
        e.setX(e.rx()-50);
    }
    else
    {
        s.setX(s.rx()+50);
        e.setX(e.rx()+50);
    }

    QPainterPath act{s};
    act.lineTo(e);
    item->setPath(act);
}

void SDEdge::socketMoved(SDSocket *s){
    if (s == startSocket)
    {
        setPoints(EdgeEndType::End, s->getSocketCenter());
    }
    else
    {
        setPoints(EdgeEndType::Start, s->getSocketCenter());
    }
}
