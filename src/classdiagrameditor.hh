/**
 * \file classdiagrameditor.hh
 *
 * \brief ClassDiagramEditor class representing editor for class diagrams.
 *
 * \date 8. 4. 2022
 * \author Filip Solich
 */

#ifndef CLASSDIAGRAMEDITOR_H
#define CLASSDIAGRAMEDITOR_H

#include <QWidget>
#include <QGraphicsScene>

#include "diagram.hh"

class ClassDiagramEditor : public QWidget
{
    Q_OBJECT

    Diagram *diagram = nullptr;

public:
    QGraphicsView *view = nullptr;
    QGraphicsScene *scene = nullptr;

    ClassDiagramEditor(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    Class *addClass(int x = 0, int y = 0);
    void removeClass(void);
};

#endif // CLASSDIAGRAMEDITOR_H
