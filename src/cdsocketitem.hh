#ifndef CDSOCKETITEM_H
#define CDSOCKETITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>

#include "itemtype.hh"

class CDSocket;

class CDSocketItem : public QGraphicsEllipseItem
{
public:
    static const int _width = 10;
    static const int _heigth = 10;

    CDSocketItem(CDSocket *socket, QGraphicsItem *parentItem = nullptr);

    CDSocket *parentCls = nullptr;

    int type() const { return ItemTypeCDSocket; };

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CDSOCKETITEM_H
