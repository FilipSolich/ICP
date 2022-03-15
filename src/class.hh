#ifndef CLASS_HH
#define CLASS_HH

#include "classitem.hh"
#include "classwidget.hh"
#include "socket.hh"

class Diagram;
class ClassDiagramEditor;

class Class
{
public:
    ClassDiagramEditor *editor = nullptr;
    ClassItem *item = nullptr;
    ClassWidget *widget = nullptr;
    QGraphicsProxyWidget *proxy = nullptr;

    Socket *sockets[4];
    Diagram *diagram;

    Class(ClassDiagramEditor *editor, Diagram *diagram, int x = 0, int y = 0);

    void setName(QString name);
    QString getName(void);

    bool addAttribute(QString visibility, QString dt, QString name);
    bool addMethod(QString visibility, QString dt, QString name);

    void redrawSockets(void);

    // QPointF getSocketPos(Socket::Position pos); // TODO: remove
    // void moved(QPointF point); // TODO: remove
};

#endif // CLASS_HH
