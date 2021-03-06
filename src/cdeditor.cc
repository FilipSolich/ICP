/**
 * \file cdeditor.cc
 *
 * \brief Source code for `CDEditor`.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QWidget>
#include <QVBoxLayout>

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
