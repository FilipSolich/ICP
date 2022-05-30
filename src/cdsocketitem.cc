/**
 * \file cdsocketitem.cc
 *
 * \brief Source code file for `CDSocketItem` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QGraphicsSceneMouseEvent>

#include "cdeditor.hh"
#include "cdeditorscene.hh"

CDSocketItem::CDSocketItem(CDSocket *cdSocket, QGraphicsItem *parentItem)
    : QGraphicsEllipseItem(parentItem),
      cdSocket{cdSocket}
{
    setRect(0, 0, cdSocket->_width, cdSocket->_height);
    setPos(cdSocket->calculateNewPos());
    setBrush(QBrush(Qt::white));
}

void CDSocketItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        CDEditor *editor = static_cast<CDEditorScene *>(scene())->editor;
        CDEdge *edge = editor->currentEdge;
        if (edge) {
            cdSocket->edges.push_back(edge);
            edge->setSocket(cdSocket, CDEdge::EdgeEndType::End);

            if (edge->type == CDEdge::Type::Generalization) {
                edge->startSocket->cdClass->setHeredity(edge->endSocket->cdClass, true);
                edge->endSocket->cdClass->setHeredity(edge->startSocket->cdClass, false);
            }
        } else {
            cdSocket->createEdge();
        }
    }

    QGraphicsEllipseItem::mousePressEvent(event);
}
