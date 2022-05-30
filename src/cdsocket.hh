/**
 * \file cdsocket.hh
 *
 * \brief Header file for `CDSocket` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDSOCKET_H
#define CDSOCKET_H

#include "cdsocketitem.hh"
#include "class.hh"

class CDEdge;

/**
 * This class represent `CDClassItem` socket in class diagram.
 */
class CDSocket
{
public:
    static const int _width = 10;
    static const int _height = 10;

    enum class Position {Top, Right, Bottom, Left };

    static QMap<CDSocket::Position, QString> positionMap;
    static QMap<CDSocket::Position, int> positionIndexMap;

    Position position;

    CDClass *cdClass = nullptr;
    CDSocketItem *item = nullptr;
    QVector<CDEdge *> edges;

    /**
     * Constructor create new socket in `CDEditor`.
     *
     * \param position Position of socket (Top, Right, Bottom, Left).
     * \param cdClass Pointer to `CDClass`.
     */
    CDSocket(Position position, CDClass *cdClass);

    /** Destructor */
    ~CDSocket();

    /**
     * Calculate new position of socket when attribute or method is add or removed from `CDClassWidget`.
     *
     * /return New position of socket.
     */
    QPointF calculateNewPos();

    /**
     * Get center of socket.
     *
     * \return Center of socket.
     */
    QPointF getSocketCenter();

    /**
     * Add edge to `CDSocket`.
     */
    void createEdge();

    /**
     * Redraw socket and all his edges.
     */
    void redraw();

    /**
     * Remove edge from `CDSocket`.
     *
     * \param edge Pointer to `CDEdge` to remove.
     */
    void removeEdge(CDEdge *edge);
};

#endif // CDSOCKET_H
