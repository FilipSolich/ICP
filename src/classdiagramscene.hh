#ifndef CLASSDIAGRAMSCENE_H
#define CLASSDIAGRAMSCENE_H

#include <QWidget>
#include <QGraphicsScene>

#include "diagram.hh"

class ClassDiagramScene : public QWidget
{
    Q_OBJECT

    QGraphicsScene *scene = nullptr;
    Diagram *diagram = nullptr;

public:
    ClassDiagramScene(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    void addClass();
};

#endif // CLASSDIAGRAMSCENE_H
