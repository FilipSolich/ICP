#include <QGraphicsProxyWidget>

#include "class.hh"
#include "classitem.hh"
#include "classwidget.hh"
#include "classdiagrameditor.hh"
#include "diagram.hh"

Class::Class(ClassDiagramEditor *editor, Diagram *diagram)
    : editor{editor},
      diagram{diagram}
{
    widget = new ClassWidget(this);
    item = new ClassItem(this);

    proxy = editor->scene->addWidget(widget);
    proxy->setPos(0, 0);
    proxy->setParentItem(item);

    diagram->classes.push_back(this);
}
