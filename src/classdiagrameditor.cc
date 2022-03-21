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
#include "classdiagrameditorscene.hh"
#include "diagram.hh"


ClassDiagramEditor::ClassDiagramEditor(QWidget *parent, Diagram *diagram)
    : QWidget(parent)
{
    scene = new ClassDiagramEditorScene(diagram);

    view = new QGraphicsView(this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);

    this->setLayout(layout);

    this->diagram = diagram;
}

Class *ClassDiagramEditor::addClass(int x, int y)
{
    Class *new_class = new Class(this, diagram, x, y);
    diagram->classes.push_back(new_class);

    return new_class;
}

void ClassDiagramEditor::removeClass(void)
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.size() > 0) {
        ClassItem *item = static_cast<ClassItem *>(items[0]);
        QVector<Class *> *classes = &diagram->classes;
        classes->erase(std::remove(classes->begin(), classes->end(), item->parentCls), classes->end());
        delete item->parentCls;
    }
}
