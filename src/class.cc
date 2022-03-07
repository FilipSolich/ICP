/**
 * \file class.cc
 *
 * \brief Source code for Class class.
 *
 * \date 6. 4. 2022
 * \author Filip Solich
 */

#include <QComboBox>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

#include "class.hh"

#include <QDebug>

Class::Class(QWidget *parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout(this);

    name = new QLineEdit(this);

    QWidget *attrBtns = new QWidget(this);
    QHBoxLayout *attrBtnsLayout = new QHBoxLayout(attrBtns);
    QPushButton *addAttrBtn = new QPushButton("+", attrBtns);
    QPushButton *delAttrBtn = new QPushButton("-", attrBtns);
    attrBtnsLayout->addWidget(addAttrBtn);
    attrBtnsLayout->addWidget(delAttrBtn);
    attrBtns->setLayout(attrBtnsLayout);

    QFrame *divider = new QFrame();
    divider->setFrameShape(QFrame::HLine);

    QWidget *methBtns = new QWidget(this);
    QHBoxLayout *methBtnsLayout = new QHBoxLayout(methBtns);
    QPushButton *addMethBtn = new QPushButton("+", methBtns);
    QPushButton *delMethBtn = new QPushButton("-", methBtns);
    methBtnsLayout->addWidget(addMethBtn);
    methBtnsLayout->addWidget(delMethBtn);
    methBtns->setLayout(methBtnsLayout);

    layout->addWidget(name);
    layout->addWidget(attrBtns);
    layout->addWidget(divider);
    layout->addWidget(methBtns);

    resize(layout->sizeHint());
    setLayout(layout);

    connect(addAttrBtn, &QPushButton::clicked, this, &Class::addAttribute);
    connect(delAttrBtn, &QPushButton::clicked, this, &Class::delAttribute);
    connect(addMethBtn, &QPushButton::clicked, this, &Class::addMethod);
    connect(delMethBtn, &QPushButton::clicked, this, &Class::delMethod);
}

void Class::addAttribute(void)
{
    QWidget *attr = new QWidget(this);

    QHBoxLayout *layout= new QHBoxLayout(attr);

    QComboBox *visibilityBox = new QComboBox(attr);
    visibilityBox ->addItems(visibility);

    QComboBox *dt = new QComboBox(attr);
    dt->addItems(dataTypes);

    QLabel *divider = new QLabel(":", attr);

    QLineEdit *name = new QLineEdit(attr);

    layout->addWidget(visibilityBox);
    layout->addWidget(dt);
    layout->addWidget(divider);
    layout->addWidget(name);

    attr->setLayout(layout);

    this->layout->insertWidget(1 + attributes_count, attr);
    attributes_count += 1;
}

void Class::delAttribute(void)
{
    if (attributes_count > 0) {
        QList<QLabel *> labels = this->findChildren<QLabel *>();
        QWidget *w = labels[0]->parentWidget();
        this->layout->removeWidget(w);
        delete w;
        resize(minimumSizeHint());
        attributes_count -= 1;

        //resize(this->layout->minimumSizeHint());
        setLayout(this->layout);
        //static_cast<QGraphicsRectItem *>(this->proxy->parentItem())->setRect(0, 0, this->width(), this->height());
    }
}

void Class::addMethod(void)
{
}

void Class::delMethod(void)
{
    this->layout->removeItem(this->layout->itemAt(3 + methods_count)); // TODO probably change 3
    methods_count -= 1;
}
