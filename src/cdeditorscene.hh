#ifndef CDEDITORSCENE_H
#define CDEDITORSCENE_H

#include <QGraphicsScene>

#include "diagram.hh"

class CDEditorScene : public QGraphicsScene
{
public:
    Diagram *diagram;

    explicit CDEditorScene(Diagram *diagram, QObject *parent = nullptr);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CDEDITORSCENE_H
