#ifndef CLASSDIAGRAMEDITORSCENE_HH
#define CLASSDIAGRAMEDITORSCENE_HH

#include <QGraphicsScene>

#include "diagram.hh"

class ClassDiagramEditorScene : public QGraphicsScene
{
public:
    Diagram *diagram;

    explicit ClassDiagramEditorScene(Diagram *diagram, QObject *parent = nullptr);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *ev);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CLASSDIAGRAMEDITORSCENE_HH
