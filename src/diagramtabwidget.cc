/**
 * \file diagramtabwidget.cc
 *
 * \brief Source code for DiagramTabWidget class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#include "classdiagrameditor.hh"
#include "diagram.hh"
#include "diagramtabwidget.hh"
#include "sequencediagram.hh"

DiagramTabWidget::DiagramTabWidget(QWidget *parent, Diagram *diagram)
    : QTabWidget{parent}
{
    this->parent = static_cast<MainWindow *>(parent);

    setTabPosition(QTabWidget::South);

    classTab = new ClassDiagramEditor(this, diagram);
    SequenceDiagram *sequenceTab = new SequenceDiagram(this);
    sequnceTabs.push_back(sequenceTab);

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

        SequenceDiagram *sequence = new SequenceDiagram(this);
        sequnceTabs.push_back(sequence);

        addTab(sequence, QString("Sequence diagram %1").arg(sequenceDiagramCounter));

        addDummyTab();
    }
    if (index == 0) {
        parent->edgeComboBox->setClassEditorEdges();
    } else {
        parent->edgeComboBox->setSequenceEditorEdges();
    }
}

void DiagramTabWidget::addDummyTab(void)
{
    QWidget *dummy = new QWidget;
    addTab(dummy, "+");
}
