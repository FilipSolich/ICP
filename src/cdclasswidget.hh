/**
 * \file classwidget.hh
 *
 * \brief Header file for `ClassWidget` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDCLASSWIDGET_H
#define CDCLASSWIDGET_H

#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "cdclassproperty.hh"

class CDClass;

/*
 * This class represent class widget in Class diagram.
 */
class CDClassWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout = nullptr;

public:
    QStringList visibility{"+", "-", "#", "~"};

    CDClass *cdClass = nullptr;
    QLineEdit *name = nullptr;
    QVector<CDClassProperty *> attributes;
    QVector<CDClassProperty *> methods;

    /**
     * Constructor create new class widget in `CDEditor`.
     *
     * \param cdClass Pointer to `CDClass`.
     * \param parent Pointer to parent widget.
     */
    CDClassWidget(CDClass *cdClass, QWidget *parent = nullptr);

    /**
     * Add property to this widget.
     *
     * \param type Type of property (attribute or method).
     * \param visibility Visibility of property (public, private, protected, ...).
     * \param dtype Data type of property.
     * \param name Name of property.
     */
    void addProperty(CDClassProperty::Type type, QString visibility = "+", QString dt = "", QString name = "");
    
    /**
     * Remove property from this widget.
     *
     * \param type Type of property (attribute or method).
     */
    void delProperty(CDClassProperty::Type type);

public slots:

    /**
     * Slot for adding new attribute to this widget.
     */
    void addAttributeSlot();

    /**
     * Slot for removing attribute from this widget.
     */
    void delAttributeSlot();

    /**
     * Slot for adding new method to this widget.
     */
    void addMethodSlot();

    /**
     * Slot for removing method from this widget.
     */
    void delMethodSlot();

    /**
     * Slot for updating name of class.
     */
    void nameUpdateSlot(const QString &text);
};

#endif // CDCLASSWIDGET_H
