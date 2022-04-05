/**
 * \file classproperty.hh
 *
 * \brief Header file for `ClassProperty` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef CDCLASSPROPERTY_H
#define CDCLASSPROPERTY_H

#include <QComboBox>
#include <QLineEdit>
#include <QStringList>
#include <QWidget>

/**
 * CDClassWidget property widget.
 */
class CDClassProperty : public QWidget
{
    Q_OBJECT

public:
    enum class Type {Attribute, Method};

    QStringList visibilityOptions{"+", "-", "#", "~"};

    Type type;
    QComboBox *visibility = nullptr;
    QLineEdit *dt = nullptr;
    QLineEdit *name = nullptr;

    /**
     * Constructor create new property widget.
     *
     * \param type Type of property (attribute or method).
     * \param vis Visibility of property (public, private, protected, ...).
     * \param dataType Data type of property.
     * \param newName Name of property.
     * \param parent Pointer to parent widget.
     */
    CDClassProperty(Type type, QString vis = "+", QString dataType = "", QString newName = "", QWidget *parent = nullptr);

    /**
     * Compare this method with `other` method.
     *
     * \param other Method to compare with.
     * \return `true` if methods are equal, `false` otherwise.
     */
    bool compareMethodOverwrite(CDClassProperty *other);

public slots:
    /**
     * Slot for property changed action.
     * This method checks heredity.
     */
    void propertyChanged();
};

#endif // CDCLASSPROPERTY_H
