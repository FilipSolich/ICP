#ifndef CLASSDIAGRAMSCENE_H
#define CLASSDIAGRAMSCENE_H

#include <QWidget>
#include <QGraphicsScene>

class ClassDiagramScene : public QWidget
{
    Q_OBJECT

    QGraphicsScene *scene = nullptr;
public:
    ClassDiagramScene(QWidget *parent = nullptr);

    void addClass();
};

#endif // CLASSDIAGRAMSCENE_H
