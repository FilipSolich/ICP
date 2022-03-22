#include <QGraphicsProxyWidget>

#include "cdclass.hh"
#include "cdclassitem.hh"
#include "cdclasswidget.hh"
#include "cdeditor.hh"
#include "diagram.hh"
#include "cdsocket.hh"
#include "cdsocketitem.hh"

#include <QDebug>

CDClass::CDClass(Diagram *diagram, CDEditor *editor, int x, int y)
    : editor{editor},
      diagram{diagram}
{
    widget = new CDClassWidget(this);
    item = new CDClassItem(this);

    proxy = editor->scene->addWidget(widget);
    proxy->setPos(x, y);
    proxy->setParentItem(item);

    sockets[0] = new CDSocket(CDSocket::Position::Top, this, item);
    sockets[1] = new CDSocket(CDSocket::Position::Right, this, item);
    sockets[2] = new CDSocket(CDSocket::Position::Bottom, this, item);
    sockets[3] = new CDSocket(CDSocket::Position::Left, this, item);
}

CDClass::~CDClass()
{
    editor->scene->removeItem(item);
    delete proxy;
    delete item;
}

void CDClass::setName(QString name)
{
    widget->name->setText(name);
}

QString CDClass::getName(void)
{
    return widget->name->text();
}

bool CDClass::addAttribute(QString visibility, QString dt, QString name)
{
    if (!widget->visibility.contains(visibility)) {
        return false;
    }

    widget->addAttribute(visibility, dt, name);
    return true;
}

bool CDClass::addMethod(QString visibility, QString dt, QString name)
{
    if (!widget->visibility.contains(visibility)) {
        return false;
    }

    widget->addMethod(visibility, dt, name);
    return true;
}

void CDClass::redrawSockets(void)
{
    for (CDSocket *s : sockets) {
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
