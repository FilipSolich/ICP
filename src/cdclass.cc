#include <QGraphicsProxyWidget>
#include <QComboBox>

#include "cdclass.hh"
#include "cdclassitem.hh"
#include "cdclassproperty.hh"
#include "cdclasswidget.hh"
#include "cdeditor.hh"
#include "cdeditorscene.hh"
#include "cdsocket.hh"
#include "cdsocketitem.hh"

CDClass::CDClass(Class *cls, CDEditor *editor, QPointF pos)
    : editor{editor},
      cls{cls}
{
    widget = new CDClassWidget(this);
    item = new CDClassItem(this, pos);

    proxy = editor->scene->addWidget(widget);
    proxy->setParentItem(item);

    item->setPos(pos);

    sockets.push_back(new CDSocket(CDSocket::Position::Top, this));
    sockets.push_back(new CDSocket(CDSocket::Position::Right, this));
    sockets.push_back(new CDSocket(CDSocket::Position::Bottom, this));
    sockets.push_back(new CDSocket(CDSocket::Position::Left, this));
}

CDClass::~CDClass()
{
    for (CDSocket *socket : qAsConst(sockets)) {
        delete socket;
    }

    editor->scene->removeItem(item);
    delete widget;
    delete item;
}

void CDClass::addProperty(CDClassProperty::Type type, QString visibility, QString dt, QString name)
{
    if (type == CDClassProperty::Type::Attribute) {
        widget->addAttribute(visibility, dt, name);
    } else {
        widget->addMethod(visibility, dt, name);
    }
}

void CDClass::setHeredity(CDClass *cls, bool parent)
{
    if (parent) {
        inherits.push_back(cls);
        checkHeredity();
    } else {
        inheritedBy.push_back(cls);
    }
}

void CDClass::removeHeredity(CDClass *cls, bool parent)
{
    if (parent) {
        inherits.remove(inherits.indexOf(cls));
        checkHeredity();
    } else {
        inheritedBy.remove(inheritedBy.indexOf(cls));
    }
}
void CDClass::checkHeredity()
{
    QSet<CDClassProperty *> overwriten;
    for (CDClass *parent : qAsConst(inherits)) {
        overwriten += parent->compareMethods(this);
    }

    for (CDClassProperty *method : qAsConst(widget->methods)) {
        if (overwriten.contains(method)) {
            method->setPalette(QPalette(QColor(211, 0, 211)));
        } else {
            method->setPalette(QPalette());
        }
    }

    for (CDClass *child : qAsConst(inheritedBy)) {
        child->checkHeredity();
    }
}

QSet<CDClassProperty *> CDClass::compareMethods(CDClass *child)
{
    QVector<CDClassProperty *> *thisMethods = &(this->widget->methods);
    QVector<CDClassProperty *> *childMethods = &(child->widget->methods);

    QSet<CDClassProperty *> overwriten;
    for (CDClassProperty *thisMethod : qAsConst(*thisMethods)){
        for (CDClassProperty *childMethod : qAsConst(*childMethods)) {
            if (thisMethod->compareMethodOverwrite(childMethod)) {
                overwriten.insert(childMethod);
            }
        }
    }

    for (CDClass *parent : qAsConst(inherits)) {
        overwriten += parent->compareMethods(child);
    }

    return overwriten;
}

void CDClass::redrawSockets()
{
    for (CDSocket *s : qAsConst(sockets)) {
        s->redraw();
    }
}
