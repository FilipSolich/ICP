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

CDEditor::CDEditor(QWidget *parent)
    : QWidget{parent}
{
    scene = new CDEditorScene(this);

    view = new QGraphicsView(this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);

    this->setLayout(layout);
}
