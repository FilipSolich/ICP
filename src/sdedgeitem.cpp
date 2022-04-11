#include "sdedgeitem.h"
#include "sdsocket.h"
#include <math.h>
#include <QPen>
#include <QPainter>
#include <QGraphicsScene>

SDEdgeItem::SDEdgeItem(SDEdge *sdEdge)
    :sdEdge(sdEdge)
{

    QPen pen;
    pen.setWidth(4);

    switch(sdEdge->type)
    {
        case SDEdge::Type::Async:
            pen.setColor(Qt::black);
            pen.setStyle(Qt::DashDotDotLine);
        break;

        case SDEdge::Type::Sync:
            pen.setColor(Qt::black);
            pen.setStyle(Qt::DotLine);;
        break;

        case SDEdge::Type::Create:
             pen.setColor(Qt::green);
        break;

        case SDEdge::Type::Destroy:
             pen.setColor(Qt::red);
        break;
    }

    setPen(pen);

}
