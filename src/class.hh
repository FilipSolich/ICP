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
    QLineEdit *name = nullptr;

    int attributes_count = 0;
    int methods_count = 0;

public:
    QGraphicsProxyWidget *proxy = nullptr;

    explicit Class(QWidget *parent = nullptr);

    QStringList dataTypes{"int", "float", "string"};
    QStringList visibility{"+", "-", "#", "~"};

    void addAttribute(void);
    void delAttribute(void);
    void addMethod(void);
    void delMethod(void);

signals:

};

#endif // CLASS_HH
