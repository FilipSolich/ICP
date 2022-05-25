/**
 * \file cdedgeitem.cc
 *
 * \brief Source code file for `CDEdgeItem` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QPen>
#include <QPainter>
#include <QWidget>
#include "cdedge.hh"
#include "cdedgeitem.hh"

CDEdgeItem::CDEdgeItem(CDEdge *cdEdge)
    : cdEdge{cdEdge}
{
    QPen pen;
    pen.setWidth(3);

    QPainter painter;
    QFont font = painter.font();
    font.setPixelSize(48);
    painter.setFont(font);

    const QRect rectangle = QRect(0, 0, 100, 50);
    QRect boundingRect;
    painter.drawText(rectangle, 0,("Hello"), &boundingRect);
    painter.setPen(pen);


    switch(cdEdge->type) {
    case CDEdge::Type::Association:
        pen.setColor(Qt::black);
        pen.setStyle(Qt::SolidLine);
        break;
    case CDEdge::Type::Aggregation:
        pen.setColor(Qt::black);
        pen.setStyle(Qt::DashLine);
        break;
    case CDEdge::Type::Composition:
        pen.setColor(Qt::green);
        pen.setStyle(Qt::SolidLine);
        break;
    case CDEdge::Type::Generalization:
        pen.setColor(Qt::green);
        pen.setStyle(Qt::DashLine);
        break;
    }

    setPen(pen);
}
