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
