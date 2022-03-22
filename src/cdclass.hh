#ifndef CDCLASS_H
#define CDCLASS_H

#include "cdclassitem.hh"
#include "cdclasswidget.hh"
#include "cdsocket.hh"

class Diagram;
class CDEditor;

class CDClass
{
public:
    CDEditor *editor = nullptr;
    CDClassItem *item = nullptr;
    CDClassWidget *widget = nullptr;
    QGraphicsProxyWidget *proxy = nullptr;

    CDSocket *sockets[4];
    Diagram *diagram;

    CDClass(Diagram *diagram, CDEditor *editor, int x = 0, int y = 0);
    ~CDClass();

    void setName(QString name);
    QString getName(void);

    bool addAttribute(QString visibility, QString dt, QString name);
    bool addMethod(QString visibility, QString dt, QString name);

    void redrawSockets(void);
};

#endif // CDCLASS_H
