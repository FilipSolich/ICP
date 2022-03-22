#include <QGraphicsSceneMouseEvent>

#include "cdeditor.hh"
#include "cdeditorscene.hh"

CDSocketItem::CDSocketItem(CDSocket *cdSocket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem),
      cdSocket{cdSocket}
{
    setRect(0, 0, cdSocket->_width, cdSocket->_heigth);
    setPos(cdSocket->calculateNewPos());
}

void CDSocketItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        CDEditor *editor = static_cast<CDEditorScene *>(scene())->editor;
        if (editor->currentEdge) {
            cdSocket->edge = editor->currentEdge;
            editor->currentEdge->setSocket(cdSocket, CDEdge::Type::End);
        } else {
            cdSocket->createEdge();
        }
    }

    QGraphicsEllipseItem::mousePressEvent(event);
}
