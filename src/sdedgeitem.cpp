#include "sdedgeitem.h"
#include "sdsocket.h"
#include <math.h>
#include <QPen>
#include <QPainter>


SDEdgeItem::SDEdgeItem(SDEdge *sdEdge,QPointF start_point)
    :sdEdge(sdEdge)
{

    QPen pen;
    pen.setWidth(4);
    setPen(pen);

}
