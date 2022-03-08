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

#include "diagram.hh"
#include "class.hh"
#include "classdiagrameditor.hh"


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

void ClassDiagramEditor::addClass()
{
    int x = 0, y = 0;
    Class *new_class = new Class();
    this->diagram->classes.push_back(new_class);

    QGraphicsRectItem *rect = scene->addRect(x, y, new_class->width(), new_class->height());
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    rect->setFlag(QGraphicsItem::ItemIsSelectable);

    QGraphicsProxyWidget *proxy = scene->addWidget(new_class);
    new_class->proxy = proxy;
    proxy->setPos(x, y);
    proxy->setParentItem(rect);
}
