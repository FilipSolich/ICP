/**
 * \file class.cc
 *
 * \brief Source code for Class class.
 *
 * \date 6. 4. 2022
 * \author Filip Solich
 */

#include <QCoreApplication>
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

    connect(addAttrBtn, &QPushButton::clicked, this, &ClassWidget::addAttributeSlot);
    connect(delAttrBtn, &QPushButton::clicked, this, &ClassWidget::delAttributeSlot);
    connect(addMethBtn, &QPushButton::clicked, this, &ClassWidget::addMethodSlot);
    connect(delMethBtn, &QPushButton::clicked, this, &ClassWidget::delMethodSlot);
}

void ClassWidget::addAttribute(QString visibility, QString dt, QString name)
{
    // TODO check arguments
    QWidget *attr = new QWidget(this);

    QHBoxLayout *layout= new QHBoxLayout(attr);

    QComboBox *visibilityBox = new QComboBox(attr);
    visibilityBox ->addItems(this->visibility);
    visibilityBox->setCurrentText(visibility);

    QLineEdit *dtLine = new QLineEdit(dt, attr);
    dtLine->setObjectName("dt");

    QLabel *divider = new QLabel(":", attr);

    QLineEdit *nameLine = new QLineEdit(name, attr);
    nameLine->setObjectName("name");

    layout->addWidget(visibilityBox);
    layout->addWidget(dtLine);
    layout->addWidget(divider);
    layout->addWidget(nameLine);

    attr->setLayout(layout);

    this->layout->insertWidget(1 + attributes.size(), attr);
    attributes.push_back(attr);

    QCoreApplication::processEvents(QEventLoop::AllEvents);
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

        QCoreApplication::processEvents(QEventLoop::AllEvents);
        this->parentClass->item->setWidgetSize(QRectF(this->x(), this->y(), this->width(), this->height()));
    }
}

void ClassWidget::addMethod(QString visibility, QString dt, QString name)
{
    // TODO check arguments
    QWidget *meth = new QWidget(this);

    QHBoxLayout *layout = new QHBoxLayout(meth);

    QComboBox *visibilityBox = new QComboBox(meth);
    visibilityBox ->addItems(this->visibility);
    visibilityBox->setCurrentText(visibility);

    QLineEdit *returnDt = new QLineEdit(dt, meth);
    returnDt->setObjectName("dt");

    QLabel *divider = new QLabel(":", meth);

    QLineEdit *nameLine = new QLineEdit(name, meth);
    nameLine->setObjectName("name");

    layout->addWidget(visibilityBox);
    layout->addWidget(returnDt);
    layout->addWidget(divider);
    layout->addWidget(nameLine);

    meth->setLayout(layout);

    this->layout->insertWidget(this->layout->count() - 1, meth);
    methods.push_back(meth);

    QCoreApplication::processEvents(QEventLoop::AllEvents);
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

        QCoreApplication::processEvents(QEventLoop::AllEvents);
        this->parentClass->item->setWidgetSize(QRectF(this->x(), this->y(), this->width(), this->height()));
    }
}

void ClassWidget::addAttributeSlot(void)
{
    addAttribute();
}

void ClassWidget::delAttributeSlot(void)
{
    delAttribute();
}

void ClassWidget::addMethodSlot(void)
{
    addMethod();
}

void ClassWidget::delMethodSlot(void)
{
    delMethod();
}
