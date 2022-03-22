#include <QGraphicsSceneMouseEvent>

#include "cdsocketitem.hh"
#include "cdeditor.hh"

#include <QDebug>

CDSocketItem::CDSocketItem(CDSocket *socket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem)
{
    this->parentCls = socket;

    QPointF point = socket->calculateSocketPos();
    setRect(0, 0, _width, _heigth);
    setPos(point.x(), point.y());
}

void CDSocketItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (parentCls->parentCls->diagram->currentEdge) {
            parentCls->edge = parentCls->parentCls->diagram->currentEdge;
            parentCls->parentCls->diagram->currentEdge->setSocket(parentCls, CDEdge::Type::End);
        } else {
            parentCls->createEdge();
        }
    }

    QGraphicsEllipseItem::mousePressEvent(event);
}
