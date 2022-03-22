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

#include "cdclass.hh"
#include "cdeditor.hh"
#include "cdeditorscene.hh"
#include "diagram.hh"


CDEditor::CDEditor(QWidget *parent, Diagram *diagram)
    : QWidget(parent)
{
    scene = new CDEditorScene(diagram);

    view = new QGraphicsView(this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);

    this->setLayout(layout);

    this->diagram = diagram;
}

CDClass *CDEditor::addClass(int x, int y)
{
    CDClass *new_class = new CDClass(diagram, this, x, y);
    diagram->cdClasses.push_back(new_class);

    return new_class;
}

void CDEditor::removeClass(void)
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.size() > 0) {
        CDClassItem *item = static_cast<CDClassItem *>(items[0]);
        QVector<CDClass *> *classes = &diagram->cdClasses;
        classes->erase(std::remove(classes->begin(), classes->end(), item->parentCls), classes->end());
        delete item->parentCls;
    }
}
