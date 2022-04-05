#include "sdsocket.h"
#include "sdclass.h"


SDSocket::SDSocket(int position, SDClass *parent_sequence, QGraphicsItem *parentItem)
{
    this->position = position;
    this->parent_sequence = parent_sequence;
    this->item = new SDSocketItem(this, parentItem);
}

QPointF SDSocket::calculateSocketPos()
{

    int x = 0,y = 0;
    int x_tmp = (parent_sequence->item->rect().width() +22) ;
    int y_tmp = ((parent_sequence->item->rect().height() / 9 ) );
    switch(position)
    {

        case 0:
            x = x_tmp;
            y = 9*y_tmp;
            break;
        case 1:
            x = x_tmp;
            y = 8*y_tmp;
            break;
        case 2:
            x = x_tmp;
            y = 7*y_tmp;
            break;
        case 3:
            x = x_tmp;
            y = 6*y_tmp;
            break;
        case 4:
            x = x_tmp;
            y = 5*y_tmp;
            break;
        case 5:
            x = x_tmp;
            y = 4*y_tmp;
            break;
        case 6:
            x = x_tmp;
            y = 3*y_tmp;
            break;
        case 7:
            x = x_tmp;
            y = 2*y_tmp;
            break;
        case 8:
            x = x_tmp;
            y = 1*y_tmp;
            break;
        default:
            x = x_tmp -130 ;
            y = (abs(position)%10) * y_tmp +40;
            break;
    }
    return QPointF(x,y);

}
QPointF SDSocket::getSocketCenter(void)
{
    QPointF center_point = item->scenePos();
    center_point.setX(center_point.x() + 10/2 );
    center_point.setY(center_point.y() +10/2);

    return center_point;
}

void SDSocket::CreateEdge()
{
    edges.push_back(new SDEdge(parent_sequence->cls))
}
/*void RemoveEdge(SDEdge *edge){

}*/

void SDSocket::redraw(void)
{
    QPointF seq_point = calculateSocketPos();
    item->setPos(seq_point.x(), seq_point.y());
}

