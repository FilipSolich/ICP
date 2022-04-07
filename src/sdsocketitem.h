#ifndef SDSOCKETITEM_H
#define SDSOCKETITEM_H


#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include "itemtype.hh"

class SDSocket;

/**
 * \brief The SDSocketItem class
 */
class SDSocketItem : public QGraphicsEllipseItem
{
public:
    static const int w = 10;
    static const int h = 10;

    /**
     * \brief SDSocketItem Constructor
     * \param socket pointer on SDSocket
     * \param parentItem pointer on parent graphics item.
     */
    SDSocketItem(SDSocket *socket, QGraphicsItem *parentItem = nullptr);
    /**
     * Destructor
     */
    ~SDSocketItem();
    SDSocket *sd_socket = nullptr;
    /**
     * \brief type
     * \return information about which type object is it
     */
    int type() const { return ItemTypeCDSocket; } ;
    /**
     * \brief mousePressEvent press event handler.
     * \param event event Pointer to event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SDSOCKETITEM_H
