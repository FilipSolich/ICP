/**
 * \file cdclassitem.hh
 *
 * \brief Header file for `CDClassItem` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDCLASSITEM_H
#define CDCLASSITEM_H

#include <QGraphicsRectItem>

#include "itemtype.hh"

class CDClass;

/**
 * QGraphicsItem for `CDClass` representation.
 */
class CDClassItem : public QGraphicsRectItem
{
public:
    CDClass *cdClass = nullptr;

    /**
     * Constructor.
     *
     * \param cdClass Pointer to `CDClass` which is represented by this graphics item.
     * \param pos Position of class in scene.
     */
    CDClassItem(CDClass *cdClass, QPointF pos);

    /**
     * Function which return graphics item type.
     *
     * \return Type of item.
     */
    int type() const { return ItemTypeCDClass; };

    /**
     * Event handler for `ItemPositionChange` event. Let all edges know that socket has been moved.
     */
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);
};

#endif // CDCLASSITEM_H
