#ifndef CLASSDIAGRAMEDITORVIEW_HH
#define CLASSDIAGRAMEDITORVIEW_HH

#include <QGraphicsView>
#include <QMouseEvent>

class Diagram;

class ClassDiagramEditorView : public QGraphicsView
{
public:
    Diagram *diagram = nullptr;
    ClassDiagramEditorView(Diagram *diagram, QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // CLASSDIAGRAMEDITORVIEW_HH
