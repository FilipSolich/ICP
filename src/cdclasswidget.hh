/**
 * \file class.hh
 *
 * \brief Header file for Class class.
 *
 * \date 6. 4. 2022
 * \author Filip Solich
 */

#ifndef CDCLASSWIDGET_H
#define CDCLASSWIDGET_H

#include <QLineEdit>
#include <QWidget>
#include <QVBoxLayout>

class CDClass;

class CDClassWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout = nullptr;

public:
    QStringList visibility{"+", "-", "#", "~"};

    CDClass *cdClass = nullptr;
    QLineEdit *name = nullptr;
    QVector<QWidget *> attributes;
    QVector<QWidget *> methods;

    CDClassWidget(CDClass *cdClass, QWidget *parent = nullptr);

    void addAttribute(QString visibility = "+", QString dt = "", QString name = "");
    void delAttribute();
    void addMethod(QString visibility = "+", QString dt = "", QString name = "");
    void delMethod();

public slots:
    void addAttributeSlot();
    void delAttributeSlot();
    void addMethodSlot();
    void delMethodSlot();
    void nameUpdateSlot(const QString &text);
};

#endif // CDCLASSWIDGET_H
