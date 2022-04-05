#ifndef SDSOCKETITEM_H
#define SDSOCKETITEM_H


#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include "itemtype.hh"

class SDSocket;

class SDSocketItem : public QGraphicsEllipseItem
{
public:
    static const int w = 10;
    static const int h = 10;


    SDSocketItem(SDSocket *socket, QGraphicsItem *parentItem = nullptr);
    ~SDSocketItem();
    SDSocket *sd_socket = nullptr;

    int type() const { return ItemTypeCDSocket; } ;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SDSOCKETITEM_H
