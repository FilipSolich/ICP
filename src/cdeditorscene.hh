#ifndef CDEDITORSCENE_H
#define CDEDITORSCENE_H

#include <QGraphicsScene>

#include "cdeditor.hh"

class CDEditorScene : public QGraphicsScene
{
public:
    CDEditor *editor = nullptr;

    CDEditorScene(CDEditor *editor);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CDEDITORSCENE_H
