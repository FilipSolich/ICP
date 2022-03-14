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

QPointF Class::getSocketPos(Socket::Position pos)
{
    int x, y;
    int itemX = item->pos().x();
    int itemY = item->pos().y();

    switch (pos) {
        case Socket::Position::Top:
            x = itemX + item->rect().width() / 2;
            y = itemY - (SocketItem::_heigth / 2);
            break;
        case Socket::Position::Right:
            x = itemX + item->rect().width() - (SocketItem::_width / 2);
            y = itemY + item->rect().height() / 2;
            break;
        case Socket::Position::Bottom:
            x = itemX + item->rect().width() / 2;
            y = itemY + item->rect().height() - (SocketItem::_heigth / 2);
            break;
        case Socket::Position::Left:
            x = itemX - (SocketItem::_width / 2);
            y = itemY + item->rect().height() / 2;
            break;
    }

    return QPointF(x, y);
}

void Class::moved(QPointF point)
{
    for (Socket *s : sockets) {
        s->moveTo(getSocketPos(s->position));
    }
}
