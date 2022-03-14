#include <QGraphicsProxyWidget>

#include "class.hh"
#include "classitem.hh"
#include "classwidget.hh"
#include "classdiagrameditor.hh"
#include "diagram.hh"

#include "socket.hh"

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

    sockets[0] = new Socket(this, Socket::Position::Top);
    sockets[1] = new Socket(this, Socket::Position::Right);
    sockets[2] = new Socket(this, Socket::Position::Bottom);
    sockets[3] = new Socket(this, Socket::Position::Left);
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

QPoint Class::getSocketPos(Socket::Position pos)
{
    int x, y;
    switch (pos) {
        case Socket::Position::Top:
            x = item->rect().width() / 2;
            y = 0;
            break;
        case Socket::Position::Right:
            x = item->rect().width();
            y = item->rect().height() / 2;
            break;
        case Socket::Position::Bottom:
            x = item->rect().width() / 2;
            y = item->rect().height();
            break;
        case Socket::Position::Left:
            x = 0;
            y = item->rect().height() / 2;
            break;
    }

    return QPoint(x, y);
}
