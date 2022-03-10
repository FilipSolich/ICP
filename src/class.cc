#include <QGraphicsProxyWidget>

#include "class.hh"
#include "classitem.hh"
#include "classwidget.hh"
#include "classdiagrameditor.hh"
#include "diagram.hh"

Class::Class(ClassDiagramEditor *editor, Diagram *diagram, int x, int y)
    : editor{editor},
      diagram{diagram}
{
    widget = new ClassWidget(this);
    item = new ClassItem(this);

    proxy = editor->scene->addWidget(widget);
    proxy->setPos(x, y);
    proxy->setParentItem(item);

    diagram->classes.push_back(this);
}

void Class::setName(QString name)
{
    widget->name->setText(name);
}

bool Class::addAttribute(QString visibility, QString dt, QString name)
{
    if (!widget->visibility.contains(visibility)) {
        return false;
    }

    widget->addAttribute(visibility, dt, name);
}

bool Class::addMethod(QString visibility, QString dt, QString name)
{
    if (!widget->visibility.contains(visibility)) {
        return false;
    }

    widget->addMethod(visibility, dt, name);
}
