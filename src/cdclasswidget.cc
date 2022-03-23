/**
 * \file class.cc
 *
 * \brief Source code for Class class.
 *
 * \date 15. 4. 2022
 * \author Filip Solich
 */

#include <QCoreApplication>
#include <QComboBox>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

#include "cdclass.hh"
#include "cdclasswidget.hh"

CDClassWidget::CDClassWidget(CDClass *cdClass, QWidget *parent)
    : QWidget{parent},
      cdClass{cdClass}
{
    setMinimumWidth(250);
    setMaximumWidth(250);

    layout = new QVBoxLayout(this);

    name = new QLineEdit(cdClass->cls->getName(), this);

    // Add and remove attribute buttons
    QWidget *attrBtns = new QWidget(this);
    QHBoxLayout *attrBtnsLayout = new QHBoxLayout(attrBtns);
    QPushButton *addAttrBtn = new QPushButton("+", attrBtns);
    QPushButton *delAttrBtn = new QPushButton("-", attrBtns);
    attrBtnsLayout->addWidget(addAttrBtn);
    attrBtnsLayout->addWidget(delAttrBtn);
    attrBtns->setLayout(attrBtnsLayout);

    // Attribute and methods divider
    QFrame *divider = new QFrame();
    divider->setFrameShape(QFrame::HLine);

    // Add and remove method buttons
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

    connect(addAttrBtn, &QPushButton::clicked, this, &CDClassWidget::addAttributeSlot);
    connect(delAttrBtn, &QPushButton::clicked, this, &CDClassWidget::delAttributeSlot);
    connect(addMethBtn, &QPushButton::clicked, this, &CDClassWidget::addMethodSlot);
    connect(delMethBtn, &QPushButton::clicked, this, &CDClassWidget::delMethodSlot);
    connect(name, &QLineEdit::textChanged, this, &CDClassWidget::nameUpdateSlot);
}

void CDClassWidget::addAttribute(QString visibility, QString dt, QString name)
{
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
    this->cdClass->item->setRect(rect());

    cdClass->redrawSockets();
}

void CDClassWidget::delAttribute()
{
    if (attributes.size() > 0) {
        QWidget *w = attributes.last();
        attributes.pop_back();
        this->layout->removeWidget(w);
        delete w;

        adjustSize();

        QCoreApplication::processEvents(QEventLoop::AllEvents);
        this->cdClass->item->setRect(rect());
        cdClass->redrawSockets();
    }
}

void CDClassWidget::addMethod(QString visibility, QString dt, QString name)
{
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
    this->cdClass->item->setRect(rect());

    cdClass->redrawSockets();
}

void CDClassWidget::delMethod()
{
    if (methods.size() > 0) {
        QWidget *w = methods.last();
        methods.pop_back();
        this->layout->removeWidget(w);
        delete w;

        adjustSize();

        QCoreApplication::processEvents(QEventLoop::AllEvents);
        this->cdClass->item->setRect(rect());
        cdClass->redrawSockets();
    }
}

void CDClassWidget::addAttributeSlot()
{
    addAttribute();
}

void CDClassWidget::delAttributeSlot()
{
    delAttribute();
}

void CDClassWidget::addMethodSlot()
{
    addMethod();
}

void CDClassWidget::delMethodSlot()
{
    delMethod();
}

void CDClassWidget::nameUpdateSlot(const QString &text)
{
    cdClass->cls->setName(text);
}
