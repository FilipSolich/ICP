/**
 * \file cdedge.hh
 *
 * \brief Header file for `CDEdge` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDEDGE_H
#define CDEDGE_H

#include <QPoint>

#include "cdsocket.hh"
#include "cdedgeitem.hh"

class Diagram;

/**
 * This class represent `CDEdge` in class diagram.
 */
class CDEdge
{
public:
    enum class EdgeEndType {Start, End};
    enum class Type {Association, Aggregation, Composition, Generalization};

    static const int C_DISTANCE = 70;

    static QMap<CDEdge::Type, QString> typeMap;

    CDEdgeItem *item = nullptr;

    CDSocket *startSocket = nullptr;
    CDSocket *endSocket = nullptr;
    Type type;

    QPointF startPoint;
    QPointF endPoint;
    QPointF c1;
    QPointF c2;

    /**
     * Constructor create new edge in `CDEditor`.
     *
     * \param type Type of edge (Association, Aggregation, Composition, Generalization).
     * \param s1 Pointer to start socket.
     * \param s2 Pointer to end socket.
     */
    CDEdge(QString type = "Association", CDSocket *s1 = nullptr, CDSocket *s2 = nullptr);

    /** Destructor */
    ~CDEdge();

    /**
     * Set socket `socket` as start or end socket of edge.
     *
     * \param socket Pointer to socket.
     * \param type Type of socket (Start, End).
     */
    void setSocket(CDSocket *socket, EdgeEndType type);

    /**
     * Caculate "C" point for cubic curve.
     *
     * \param point Point of edge.
     * \param socPos Position of socket.
     * \return "C" point for cubic curve.
     */
    QPointF calculateC(QPointF point, CDSocket::Position socPos);

    /**
     * Set points of edge and call `setPath`.
     *
     * \param type Type of socket (Start, End).
     * \param point Point of edge.
     * \param socPos Position of socket.
     */
    void setPoints(EdgeEndType type, QPointF point, CDSocket::Position socPos = CDSocket::Position::Right);

    /**
     * Set path of edge based on points.
     */
    void setPath();

    /**
     * Set current mouse position as end point of edge.
     *
     * \param pos Current mouse position.
     */
    void setMousePos(QPointF pos);

    /**
     * Calculate new edge points based on new socket position.
     *
     * \param s Pointer to socket.
     */
    void socketMoved(CDSocket *s);
};

#endif // CDEDGE_H
