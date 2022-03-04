/**
 * \file diagramtabwidget.cc
 *
 * \brief Source code for DiagramTabWidget class.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#include <QDebug> // TODO: remove

#include "diagramtabwidget.hh"
#include "sequencediagram.hh"

DiagramTabWidget::DiagramTabWidget(QWidget *parent)
    : QTabWidget{parent}
{
    setTabPosition(QTabWidget::South);

    QWidget *dummy1 = new QWidget;
    SequenceDiagram *sequence = new SequenceDiagram(this);

    addTab(dummy1, "Class diagram");
    addTab(sequence, QString("Sequence diagram %1").arg(sequenceDiagramCounter));
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
