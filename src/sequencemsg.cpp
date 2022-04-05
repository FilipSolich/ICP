#include "sequencemsg.h"
#include "sequenceeditor.hh"
#include <QPainter>
#include <QPoint>

#include <math.h>
SequenceMsg::SequenceMsg(SequenceEditor *parentDiagram)
{
    this->parentDiagram = parentDiagram;
    //todo sockets
}

void SequenceMsg::draw_async()
{
    //todo
}
void SequenceMsg::draw_sync()
{
    /*QPainter paint(this);
    paint.setPen(Qt::black);
    paint.setFont(QFont("Arial", 30));
    paint.drawText(rect(), Qt::AlignCenter, "Qt");*/

   // draw_arrow(paint,QPoint(0,0), QPoint(0,0));
}
void SequenceMsg::draw_destroy()
{

}

void SequenceMsg::draw_create()
{

}


void SequenceMsg::draw_async_slot(void)
{
    draw_async();
}
void SequenceMsg::draw_sync_slot(void)
{
    draw_sync();
}
void SequenceMsg::draw_create_slot(void)
{
    draw_create();
}
void SequenceMsg::draw_destroy_slot(void)
{
    draw_destroy();
}
/*
void SequenceMsg::draw_arrow(QPainter& painter, QPoint start, QPoint end)
{

  painter.setRenderHint(QPainter::Antialiasing, true);

  qreal arrowSize = 40; // size of head
  painter.setPen(Qt::black);
  painter.setBrush(Qt::black);

  QLineF line(end, start);

  double angle = std::atan2(-line.dy(), line.dx());
  QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                        cos(angle + M_PI / 3) * arrowSize);
  QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                        cos(angle + M_PI - M_PI / 3) * arrowSize);

  QPolygonF arrowHead;
  arrowHead.clear();
  arrowHead << line.p1() << arrowP1 << arrowP2;
  painter.drawLine(line);
  painter.drawPolygon(arrowHead);

}*/
