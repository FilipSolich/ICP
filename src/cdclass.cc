#include <QGraphicsProxyWidget>

#include "cdclass.hh"
#include "cdclassitem.hh"
#include "cdclasswidget.hh"
#include "cdeditor.hh"
#include "cdeditorscene.hh"
#include "cdsocket.hh"
#include "cdsocketitem.hh"

CDClass::CDClass(CDEditor *editor, Class *cls, QPointF pos)
    : editor{editor},
      cls{cls}
{
    widget = new CDClassWidget(this);
    item = new CDClassItem(this, pos);

    proxy = editor->scene->addWidget(widget);
    proxy->setPos(pos);
    proxy->setParentItem(item);

    sockets.push_back(new CDSocket(CDSocket::Position::Top, this, item));
    sockets.push_back(new CDSocket(CDSocket::Position::Right, this, item));
    sockets.push_back(new CDSocket(CDSocket::Position::Bottom, this, item));
    sockets.push_back(new CDSocket(CDSocket::Position::Left, this, item));
}

CDClass::~CDClass()
{
    for (CDSocket *socket : qAsConst(sockets)) {
        delete socket;
    }

    editor->scene->removeItem(item);
    delete widget;
    delete item;
    delete proxy;
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

void CDClass::redrawSockets()
{
    for (CDSocket *s : qAsConst(sockets)) {
        s->redraw();
    }
}
