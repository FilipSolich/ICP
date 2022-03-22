#ifndef CDCLASS_H
#define CDCLASS_H

#include "cdclassitem.hh"
#include "cdclasswidget.hh"
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

    CDClass(Class *cls, CDEditor *editor, QPointF pos);
    ~CDClass();

    bool addAttribute(QString visibility, QString dt, QString name);
    bool addMethod(QString visibility, QString dt, QString name);

    void redrawSockets();
};

#endif // CDCLASS_H
