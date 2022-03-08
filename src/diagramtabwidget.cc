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
    setTabPosition(QTabWidget::South);

    ClassDiagramEditor *classTab = new ClassDiagramEditor(this, diagram);
    SequenceDiagram *sequenceTab = new SequenceDiagram(this);

    addTab(classTab, "Class diagram");
    addTab(sequenceTab, QString("Sequence diagram %1").arg(sequenceDiagramCounter));
    addDummyTab();

    connect(this, &DiagramTabWidget::tabBarClicked, this, &DiagramTabWidget::addSequenceTab);
}

void DiagramTabWidget::addSequenceTab(int index)
{
    if (index == this->count() - 1) {
        removeTab(index);

        sequenceDiagramCounter += 1;

        SequenceDiagram *sequence = new SequenceDiagram(this);
        addTab(sequence, QString("Sequence diagram %1").arg(sequenceDiagramCounter));

        addDummyTab();
    }
}

void DiagramTabWidget::addDummyTab(void)
{
    QWidget *dummy = new QWidget;
    addTab(dummy, "+");
}
