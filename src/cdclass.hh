/**
 * \file cdclass.hh
 *
 * \brief Header file for `CDClass` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDCLASS_H
#define CDCLASS_H

#include "cdclassitem.hh"
#include "cdclassproperty.hh"
#include "cdclasswidget.hh"
#include "cdsocket.hh"

class CDEditor;
class Class;

/**
 * This class represent class model in Class diagram.
 * Contains pointer on `CDClassWidget` and `CDClassItem` which are used to describe look of class.
 */
class CDClass
{
public:
    CDEditor *editor = nullptr;
    Class *cls = nullptr;

    CDClassItem *item = nullptr;
    CDClassWidget *widget = nullptr;
    QGraphicsProxyWidget *proxy = nullptr;

    QVector<CDSocket *> sockets;
    QVector<CDClass *> inherits;
    QVector<CDClass *> inheritedBy;

    /**
     * Constructor create new class in `CDEditor`.
     *
     * \param cls Pointer to `Class`.
     * \param editor Pointer to `CDEditor`.
     * \param pos Position of class in scene.
     */
    CDClass(Class *cls, CDEditor *editor, QPointF pos);

    /** Destructor */
    ~CDClass();

    /**
     * Set heredity to this `CDClass` when user connect this class to other class using
     * Generalization relation.
     *
     * \param cls Pointer to other `CDClass`.
     * \param parent if `true` other `CDClass` will be add as parent to this `CDClass`.
     */
    void setHeredity(CDClass *cls, bool parent);

    /**
     * Remove heredity from this class when user disconnect this class from other class using
     * Generalization relation.
     *
     * \param cls Pointer to other `CDClass`.
     * \param parent if `true` other `CDClass` will be remove as parent from this `CDClass`.
     */
    void removeHeredity(CDClass *cls, bool parent);

    /**
     * Check heredity recursively and color it's own method if method is overridden.
     */
    void checkHeredity();

    /**
     * Check recursively if some of `child` method are overridden method of this `CDClass`.
     *
     * \param child Pointer to child `CDClass`.
     * \return Set with addresses of overridden methods.
     */
    QSet<CDClassProperty *> compareMethods(CDClass *child);

    /**
     * Set new position to sockets when class model is extended or shrinked
     * by adding or removing property.
     */
    void redrawSockets();
};

#endif // CDCLASS_H
