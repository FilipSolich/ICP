#ifndef CLASS_HH
#define CLASS_HH

#include "classitem.hh"
#include "classwidget.hh"

class Diagram;
class ClassDiagramEditor;

class Class
{
public:
    Class(ClassDiagramEditor *editor, Diagram *diagram);

    ClassDiagramEditor *editor = nullptr;
    ClassItem *item = nullptr;
    ClassWidget *widget = nullptr;
    QGraphicsProxyWidget *proxy = nullptr;

    Diagram *diagram;
};

#endif // CLASS_HH
