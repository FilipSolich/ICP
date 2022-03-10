#ifndef CLASS_HH
#define CLASS_HH

#include "classitem.hh"
#include "classwidget.hh"

class Diagram;
class ClassDiagramEditor;

class Class
{
public:
    Class(ClassDiagramEditor *editor, Diagram *diagram, int x = 0, int y = 0);

    ClassDiagramEditor *editor = nullptr;
    ClassItem *item = nullptr;
    ClassWidget *widget = nullptr;
    QGraphicsProxyWidget *proxy = nullptr;

    Diagram *diagram;

    void setName(QString name);
    bool addAttribute(QString visibility, QString dt, QString name);
    bool addMethod(QString visibility, QString dt, QString name);
};

#endif // CLASS_HH
