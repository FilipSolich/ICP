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

#include "classwidget.hh"
#include "class.hh"
#include <QDebug>

ClassWidget::ClassWidget(Class *parentClass, QWidget *parent)
    : QWidget{parent}
{
    this->parentClass = parentClass;

    setMinimumWidth(250);
    setMaximumWidth(250);

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

    setLayout(layout);
    resize(layout->sizeHint());

    connect(addAttrBtn, &QPushButton::clicked, this, &ClassWidget::addAttribute);
    connect(delAttrBtn, &QPushButton::clicked, this, &ClassWidget::delAttribute);
    connect(addMethBtn, &QPushButton::clicked, this, &ClassWidget::addMethod);
    connect(delMethBtn, &QPushButton::clicked, this, &ClassWidget::delMethod);
    qDebug() << this->width() << this->height();
}

void ClassWidget::addAttribute(void)
{
    QWidget *attr = new QWidget(this);

    QHBoxLayout *layout= new QHBoxLayout(attr);

    QComboBox *visibilityBox = new QComboBox(attr);
    visibilityBox ->addItems(visibility);

    QLineEdit *dt = new QLineEdit(attr);
    dt->setObjectName("dt");

    QLabel *divider = new QLabel(":", attr);

    QLineEdit *name = new QLineEdit(attr);
    name->setObjectName("name");

    layout->addWidget(visibilityBox);
    layout->addWidget(dt);
    layout->addWidget(divider);
    layout->addWidget(name);

    attr->setLayout(layout);

    this->layout->insertWidget(1 + attributes.size(), attr);
    attributes.push_back(attr);

    this->parentClass->item->setWidgetSize(QRectF(this->x(), this->y(), this->width(), this->height()));
}

void ClassWidget::delAttribute(void)
{
    if (attributes.size() > 0) {
        QWidget *w = attributes.last();
        attributes.pop_back();
        this->layout->removeWidget(w);
        delete w;

        adjustSize();

        this->parentClass->item->setWidgetSize(QRectF(this->x(), this->y(), this->width(), this->height()));
    }
}

void ClassWidget::addMethod(void)
{
    QWidget *meth = new QWidget(this);

    QHBoxLayout *layout = new QHBoxLayout(meth);

    QComboBox *visibilityBox = new QComboBox(meth);
    visibilityBox ->addItems(visibility);

    QLineEdit *returnDt = new QLineEdit(meth);
    returnDt->setObjectName("dt");

    QLabel *divider = new QLabel(":", meth);

    QLineEdit *name = new QLineEdit(meth);
    name->setObjectName("name");

    layout->addWidget(visibilityBox);
    layout->addWidget(returnDt);
    layout->addWidget(divider);
    layout->addWidget(name);

    meth->setLayout(layout);

    this->layout->insertWidget(this->layout->count() - 1, meth);
    methods.push_back(meth);

    this->parentClass->item->setWidgetSize(QRectF(this->x(), this->y(), this->width(), this->height()));
}

void ClassWidget::delMethod(void)
{
    if (methods.size() > 0) {
        QWidget *w = methods.last();
        methods.pop_back();
        this->layout->removeWidget(w);
        delete w;

        adjustSize();

        this->parentClass->item->setWidgetSize(QRectF(this->x(), this->y(), this->width(), this->height()));
    }
}
