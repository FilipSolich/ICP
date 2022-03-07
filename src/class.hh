/**
 * \file class.hh
 *
 * \brief Header file for Class class.
 *
 * \date 6. 4. 2022
 * \author Filip Solich
 */

#ifndef CLASS_HH
#define CLASS_HH

#include <QLineEdit>
#include <QWidget>
#include <QVBoxLayout>

class Class : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout = nullptr;

public:
    QGraphicsProxyWidget *proxy = nullptr;
    QLineEdit *name = nullptr;
    QVector<QWidget *> attributes;
    QVector<QWidget *> methods;

    explicit Class(QWidget *parent = nullptr);

    QStringList visibility{"+", "-", "#", "~"};

    void addAttribute(void);
    void delAttribute(void);
    void addMethod(void);
    void delMethod(void);

signals:

};

#endif // CLASS_HH
