/**
 * \file classwidget.cc
 *
 * \brief Source code for `ClassWidget` class.
 *
 * \date 5. 4. 2022
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
#include "cdclassproperty.hh"

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
    connect(cdClass->cls, &Class::setNameSignal, this, &CDClassWidget::newNameSlot);
}

void CDClassWidget::addProperty(CDClassProperty::Type type, QString visibility, QString dt, QString name)
{
    CDClassProperty *prop = new CDClassProperty(type, visibility, dt, name, this);

    if (type == CDClassProperty::Type::Attribute) {
        this->layout->insertWidget(1 + attributes.size(), prop);
        attributes.push_back(prop);
    } else {
        this->layout->insertWidget(this->layout->count() - 1, prop);
        methods.push_back(prop);
    }

    QCoreApplication::processEvents(QEventLoop::AllEvents);
    this->cdClass->item->setRect(rect());

    cdClass->redrawSockets();
}

void CDClassWidget::delProperty(CDClassProperty::Type type)
{
    CDClassProperty *w = nullptr;
    if (type == CDClassProperty::Type::Attribute) {
        if (attributes.size() > 0) {
            w = attributes.last();
            attributes.pop_back();
        }
    } else {
        if (methods.size() > 0) {
            w = methods.last();
            methods.pop_back();
        }
    }

    if (w) {
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
    addProperty(CDClassProperty::Type::Attribute);
}

void CDClassWidget::delAttributeSlot()
{
    delProperty(CDClassProperty::Type::Attribute);
}

void CDClassWidget::addMethodSlot()
{
    addProperty(CDClassProperty::Type::Method);
}

void CDClassWidget::delMethodSlot()
{
    delProperty(CDClassProperty::Type::Method);
}

void CDClassWidget::nameUpdateSlot(const QString &text)
{
    cdClass->cls->setName(text);
}

void CDClassWidget::newNameSlot(const QString &name)
{
    if (this->name->text() != name) {
        this->name->setText(name);
    }
}
