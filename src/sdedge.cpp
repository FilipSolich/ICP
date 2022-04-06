#include <QGraphicsScene>

#include "sdedge.h"
#include <sequenceeditor.hh>
#include "sdeditorscene.h"
#include "sdedgeitem.h"
#include <math.h>
#include <QPainter>
SDEdge::SDEdge(QString type, SDSocket *s1, SDSocket *s2 )
{
    this->type = typeMap[type];
    item = new SDEdgeItem(this);
    s1->item->scene()->addItem(item);

    setSocket(s1,EdgeEndType::Start);
    setSocket(s2, EdgeEndType::End);

    this->startSocket->parent_sequence->diagram->currentEdge = this;
}

SDEdge::~SDEdge(){
    item->scene()->removeItem(item);
    delete item;
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

    setPath();
}

void SDEdge::setPath()
{
   /* const qreal Pi = 3.14;
    double angle = 30.0;
    QPointF p1 = startPoint + QPointF(sin(angle + Pi/3) * 20,cos(angle +Pi/3)*20);
    QPointF p2 = startPoint + QPointF(sin(angle + Pi - Pi / 3) * 20,
                                           cos(angle + Pi - Pi / 3) * 20);
*/

    QPainterPath path{startPoint};
    path.lineTo(endPoint);
    item->setPath(path);


}

void SDEdge::socketMoved(SDSocket *s){
    if (s)
    {
        setPoints(EdgeEndType::Start, s->calculateSocketPos());
    }
    else
    {
        setPoints(EdgeEndType::End, s->calculateSocketPos());
    }
}
