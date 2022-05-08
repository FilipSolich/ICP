/**
 * \file sequenceitem.h
 *
 * \brief `Sequenceitem` class representing sequence item for SDClass.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */


#ifndef SDCLASSITEM_H
#define SDCLASSITEM_H

#include <QGraphicsRectItem>
#include "itemtype.hh"
class SDClass;

class SDClassItem : public QGraphicsRectItem
/**
* QGraphicsItem for `SDClass` representation.
*/
{
public:
    SDClass *parent_sequence = nullptr;
    /**
     * \brief Constructor.
     * \param parent_sequence Pointer to `SDClass` which is represented by this graphics rectitem.
     *
     */
    SDClassItem(SDClass *parent_sequence);
    /**
     * \brief type
     * \return ItemTypeSDClass
     */
    int type() const {return ItemTypeSDClass;};
    /**
     * \brief itemChange
     * \param change
     * \param value
     * \return QVariant
     */
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);
};

#endif // SDCLASSITEM_H
