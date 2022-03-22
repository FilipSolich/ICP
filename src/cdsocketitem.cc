#include <QGraphicsSceneMouseEvent>

#include "diagram.hh"
#include "cdclass.hh"
#include "cdeditor.hh"
#include "cdsocketitem.hh"
#include "class.hh"

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
        if (parentCls->cdClass->cls->diagram->cdEditor->currentEdge) {
            parentCls->edge = parentCls->cdClass->cls->diagram->cdEditor->currentEdge;
            parentCls->cdClass->cls->diagram->cdEditor->currentEdge->setSocket(parentCls, CDEdge::Type::End);
        } else {
            parentCls->createEdge();
        }
    }

    QGraphicsEllipseItem::mousePressEvent(event);
}
