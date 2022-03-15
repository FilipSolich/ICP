/**
 * \file classdiagrameditor.cc
 *
 * \brief Source code for ClassDiagramEditor.
 *
 * \date 8. 4. 2022
 * \author Filip Solich
 */

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "class.hh"
#include "classdiagrameditor.hh"
#include "diagram.hh"


ClassDiagramEditor::ClassDiagramEditor(QWidget *parent, Diagram *diagram)
    : QWidget(parent)
{
    scene = new QGraphicsScene;

    view = new QGraphicsView(this);
    view->setScene(scene);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);

    this->setLayout(layout);

    this->diagram = diagram;

    addClass(); // TODO Remove after testing
}

Class *ClassDiagramEditor::addClass(int x, int y)
{
    Class *new_class = new Class(this, diagram, x, y);
    diagram->classes.push_back(new_class);

    return new_class;
}
