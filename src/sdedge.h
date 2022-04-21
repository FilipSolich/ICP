#ifndef SDEDGE_H
#define SDEDGE_H

#include <QPoint>
#include "sdsocket.h"
#include "sdedgeitem.h"

class Diagram;
/**
 *  The SDEdge class represent object which connect Sequence Diagrams
 */
class SDEdge
{
public:
    enum class EdgeEndType {Start, End};
    enum class Type {Async,Sync,Create,Destroy,Activate,Back};

    static QMap<SDEdge::Type, QString> typeMap;
    //SDEdgeItem *item = nullptr;

    SDSocket *startSocket = nullptr;
    SDSocket *endSocket = nullptr;
    Type type;
    SDEdgeItem *item = nullptr;
    QPointF startPoint;
    QPointF endPoint;
    QPointF c1;
    QPointF c2;

    /**
     * \brief SDEdge, consctructor of object.
     * \param type of msg (Async = Asynchronous, Sync = Synchronous, Create, Destroy)
     * \param s1 pointer to start socket.
     * \param s2 pointer to end socket.
     */
    SDEdge(QString type="Async", SDSocket *s1 = nullptr, SDSocket *s2 = nullptr );
    /**
     * Desturcor of object,
    */
    ~SDEdge();
    /**
     * \brief setSocket setting of type socket.
     * \param socket pointer on socket.
     * \param type future type of socket.
     */

    void setSocket(SDSocket *socket, EdgeEndType type);
    /**
     * \brief setPath draw line between set sockets,
     */
    void setPath();
    /**
     * \brief setMousePos current mouse position.
     * \param pos mouse position.
     */
    void setMousePos(QPointF pos);
    /**
     * \brief socketMoved recalculate new positions of sockets between edge,
     * \param s socket pointer.
     */
    void socketMoved(SDSocket *s);
    /**
     * \brief setPoints set of points.
     * \param type type of socket (start, end).
     * \param point of edge.
     */
    void setPoints(EdgeEndType type, QPointF point);

    void setMousePosActivate(QPointF);
    void setActPath();
};

#endif // SDEDGE_H
