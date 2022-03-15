/**
 * \file class.hh
 *
 * \brief Header file for Class class.
 *
 * \date 6. 4. 2022
 * \author Filip Solich
 */

#ifndef CLASSWIDGET_H
#define CLASSWIDGET_H

#include <QLineEdit>
#include <QWidget>
#include <QVBoxLayout>

class Class;

class ClassWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout = nullptr;

public:
    QStringList visibility{"+", "-", "#", "~"};

    Class *parentCls = nullptr;
    QLineEdit *name = nullptr;
    QVector<QWidget *> attributes;
    QVector<QWidget *> methods;

    ClassWidget(Class *parentClass, QWidget *parent = nullptr);

    void addAttribute(QString visibility = "+", QString dt = "", QString name = "");
    void delAttribute(void);
    void addMethod(QString visibility = "+", QString dt = "", QString name = "");
    void delMethod(void);

public slots:
    void addAttributeSlot(void);
    void delAttributeSlot(void);
    void addMethodSlot(void);
    void delMethodSlot(void);

};

#endif // CLASSWIDGET_H
