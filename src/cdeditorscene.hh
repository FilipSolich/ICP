/**
 * \file cdeditorscene.hh
 *
 * \brief Header file for `CDEditorScene` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDEDITORSCENE_H
#define CDEDITORSCENE_H

#include <QGraphicsScene>

#include "cdeditor.hh"

/**
 * Class represent graphic scene for `CDEditor`.
 */
class CDEditorScene : public QGraphicsScene
{
public:
    CDEditor *editor = nullptr;

    /**
     * Constructor.
     *
     * \param editor Pointer to `CDEditor` object.
     */
    CDEditorScene(CDEditor *editor);

    /**
     * Mouse move event handler.
     * Draw line if mouse was pressed on socket.
     *
     * \param event Pointer to mouse event.
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /**
     * Mouse press event handler.
     * Create new line if mouse was pressed on socket.
     *
     * \param event Pointer to mouse event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CDEDITORSCENE_H
