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

    QGraphicsView *view = nullptr;
    QGraphicsScene *scene = nullptr;

    Diagram *diagram = nullptr;

public:
    ClassDiagramEditor(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    void addClass();
};

#endif // CLASSDIAGRAMEDITOR_H
