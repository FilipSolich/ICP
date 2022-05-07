/**
 * \file sdsocket.h
 *
 * \brief `SDSocket` class representing sdsocket.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#ifndef SDSOCKET_H
#define SDSOCKET_H

#include "sdsocketitem.h"
#include "sdedge.h"

class SDClass;
class SDEdge;
/**
 * \brief The SDSocket class
 */
class SDSocket
{

public:
    /**
     * \brief SDSocket Constructor.
     * \param position number of position in SequenceItem
     * \param parent_sequence parent class
     * \param parentItem
     */
    SDSocket(int position,SDClass *parent_sequence, QGraphicsItem *parentItem);

    int position;
    SDClass *parent_sequence = nullptr;
    SDSocketItem *item = nullptr;
    QVector<SDEdge *> edges;

    /**
     * \brief calculateSocketPos
     * \return QPoint of the socket position .
     */
    QPointF calculateSocketPos();
    /**
     * \brief redraw socket
     */
    void redraw(void);
    void redraw(int x);
    /**
     * \brief getSocketCenter
     * \return QPoint of the center position.
     */
    QPointF getSocketCenter(void);
    /**
     * \brief CreateEdge add edge to SDSocket object.
     */
    void CreateEdge();
    //void RemoveEdge(SDEdge *edge);
};

#endif // SDSOCKET_H
