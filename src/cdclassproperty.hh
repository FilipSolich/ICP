#ifndef CDCLASSPROPERTY_H
#define CDCLASSPROPERTY_H

#include <QComboBox>
#include <QLineEdit>
#include <QStringList>
#include <QWidget>

#include "cdclasswidget.hh"

class CDClassProperty : public QWidget
{
    Q_OBJECT

public:
    enum class Type {Attribute, Method};

    QStringList visibilityOptions{"+", "-", "#", "~"};

    Type type;
    QComboBox *visibility = nullptr;
    QLineEdit *dt = nullptr;
    QLineEdit *name = nullptr;

    CDClassProperty(Type type, QString vis = "+", QString dataType = "", QString newName = "", QWidget *parent = nullptr);

    bool compareMethodOverwrite(CDClassProperty *other);

public slots:
    void propertyChanged();
};

#endif // CDCLASSPROPERTY_H
