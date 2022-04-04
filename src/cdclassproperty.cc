#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QWidget>

#include "cdclass.hh"
#include "cdclassproperty.hh"

CDClassProperty::CDClassProperty(Type type, QString vis, QString dataType, QString newName, QWidget *parent)
    : QWidget{parent},
      type{type}
{
    QHBoxLayout *layout= new QHBoxLayout(this);

    visibility = new QComboBox(this);
    visibility->addItems(this->visibilityOptions);
    visibility->setCurrentText(vis);

    dt = new QLineEdit(dataType, this);

    QLabel *divider = new QLabel(":", this);

    name = new QLineEdit(newName, this);

    layout->addWidget(visibility);
    layout->addWidget(dt);
    layout->addWidget(divider);
    layout->addWidget(name);

    this->setLayout(layout);

    connect(visibility, &QComboBox::currentTextChanged, this, &CDClassProperty::propertyChanged);
    connect(dt, &QLineEdit::editingFinished, this, &CDClassProperty::propertyChanged);
    connect(name, &QLineEdit::editingFinished, this, &CDClassProperty::propertyChanged);
}

bool CDClassProperty::compareMethodOverwrite(CDClassProperty *other)
{
    if (
        visibility->currentText() == other->visibility->currentText() &&
        dt->text() == other->dt->text() &&
        name->text() == other->name->text()
    ) {
        return true;
    } else {
        return false;
    }
}

void CDClassProperty::propertyChanged()
{
    if (type == Type::Method) {
        static_cast<CDClassWidget *>(parent())->cdClass->checkHeredity();
    }
}
