#ifndef CDCLASS_H
#define CDCLASS_H

#include "cdclassitem.hh"
#include "cdclasswidget.hh"
#include "cdclassproperty.hh"
#include "cdsocket.hh"

class CDEditor;
class Class;

class CDClass
{
public:
    CDEditor *editor = nullptr;
    Class *cls = nullptr;

    CDClassItem *item = nullptr;
    CDClassWidget *widget = nullptr;
    QGraphicsProxyWidget *proxy = nullptr;

    QVector<CDSocket *> sockets;
    QVector<CDClass *> inherits;
    QVector<CDClass *> inheritedBy;

    CDClass(Class *cls, CDEditor *editor, QPointF pos);
    ~CDClass();

    bool addAttribute(QString visibility, QString dt, QString name); // TODO remove
    bool addMethod(QString visibility, QString dt, QString name); // TODO remove
    bool addProperty(CDClassProperty::Type type, QString visibility, QString dt, QString name);

    void setHeredity(CDClass *cls, bool parent);
    void removeHeredity(CDClass *cls, bool parent);

    void checkHeredity();
    QSet<CDClassProperty *> compareMethods(CDClass *child);

    void redrawSockets();
};

#endif // CDCLASS_H
