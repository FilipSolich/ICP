#include <QGraphicsProxyWidget>

#include "class.hh"
#include "classitem.hh"
#include "classwidget.hh"
#include "classdiagrameditor.hh"
#include "diagram.hh"
#include "socket.hh"
#include "socketitem.hh"

#include <QDebug>

Class::Class(ClassDiagramEditor *editor, Diagram *diagram, int x, int y)
    : editor{editor},
      diagram{diagram}
{
    widget = new ClassWidget(this);
    item = new ClassItem(this);

    proxy = editor->scene->addWidget(widget);
    proxy->setPos(x, y);
    proxy->setParentItem(item);

    sockets[0] = new Socket(Socket::Position::Top, this, item);
    sockets[1] = new Socket(Socket::Position::Right, this, item);
    sockets[2] = new Socket(Socket::Position::Bottom, this, item);
    sockets[3] = new Socket(Socket::Position::Left, this, item);
}

Class::~Class()
{
    editor->scene->removeItem(item);
    delete proxy;
    delete item;
}

void Class::setName(QString name)
{
    widget->name->setText(name);
}

QString Class::getName(void)
{
    return widget->name->text();
}

bool Class::addAttribute(QString visibility, QString dt, QString name)
{
    if (!widget->visibility.contains(visibility)) {
        return false;
    }

    widget->addAttribute(visibility, dt, name);
    return true;
}

bool Class::addMethod(QString visibility, QString dt, QString name)
{
    if (!widget->visibility.contains(visibility)) {
        return false;
    }

    widget->addMethod(visibility, dt, name);
    return true;
}

void Class::redrawSockets(void)
{
    for (Socket *s : sockets) {
        s->redraw();
    }
}

// TODO: remove
// void Class::moved(QPointF point)
// {
//     //for (Socket *s : sockets) {
//     //    s->moveTo(getSocketPos(s->position));
//     //}
// }
