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
    ClassWidget(Class *parentClass, QWidget *parent = nullptr);

    QStringList visibility{"+", "-", "#", "~"};

    QLineEdit *name = nullptr;
    QVector<QWidget *> attributes;
    QVector<QWidget *> methods;

    Class *parentClass = nullptr;

    void addAttribute(void);
    void delAttribute(void);
    void addMethod(void);
    void delMethod(void);

signals:

};

#endif // CLASSWIDGET_H
