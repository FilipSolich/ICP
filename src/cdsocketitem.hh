#ifndef CDSOCKETITEM_H
#define CDSOCKETITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>

#include "itemtype.hh"

class CDSocket;

class CDSocketItem : public QGraphicsEllipseItem
{
public:
    CDSocket *cdSocket = nullptr;

    CDSocketItem(CDSocket *cdSocket, QGraphicsItem *parentItem = nullptr);

    int type() const { return ItemTypeCDSocket; };

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CDSOCKETITEM_H
