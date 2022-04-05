/**
 * \file diagramtabwidget.cc
 *
 * \brief Source code for DiagramTabWidget class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#include "cdeditor.hh"
#include "diagramtabwidget.hh"
#include "sequenceeditor.hh"

DiagramTabWidget::DiagramTabWidget(QWidget *parent)
    : QTabWidget{parent}
{
    this->parent = static_cast<MainWindow *>(parent);

    setTabPosition(QTabWidget::South);

    classTab = new CDEditor(this);
    SequenceEditor *sequenceTab = new SequenceEditor(this);
    sequenceTabs.push_back(sequenceTab);

    addTab(classTab, "Class diagram");
    addTab(sequenceTab, QString("Sequence diagram %1").arg(sequenceDiagramCounter));
    addDummyTab();

    connect(this, &DiagramTabWidget::tabBarClicked, this, &DiagramTabWidget::selectTab);
}

void DiagramTabWidget::selectTab(int index)
{
    if (index == this->count() - 1) {
        removeTab(index);

        sequenceDiagramCounter += 1;

        SequenceEditor *sequence = new SequenceEditor(this);
        sequenceTabs.push_back(sequence);

        addTab(sequence, QString("Sequence diagram %1").arg(sequenceDiagramCounter));

        addDummyTab();
    }
    if (index == 0) {
        parent->edgeComboBox->setClassEditorEdges();
    } else {
        parent->edgeComboBox->setSequenceEditorEdges();
    }
}

void DiagramTabWidget::addDummyTab()
{
    QWidget *dummy = new QWidget;
    addTab(dummy, "+");
}
