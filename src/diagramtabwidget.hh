/**
 * \file diagramtabwidget.hh
 *
 * \brief DiagramTabWidget class representing tab bar for users diagram.
 *
 * \date 15. 3. 2022
 * \author Filip Solich
 */

#ifndef DIAGRAMTABWIDGET_HH
#define DIAGRAMTABWIDGET_HH

#include <QTabWidget>
#include <QWidget>

#include "diagram.hh"
#include "classdiagrameditor.hh"
#include "mainwindow.hh"
#include "sequencediagram.hh"

class DiagramTabWidget : public QTabWidget
{
    Q_OBJECT

    MainWindow *parent;
    int sequenceDiagramCounter = 1;

    void addDummyTab(void);

public:
    explicit DiagramTabWidget(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    ClassDiagramEditor *classTab;
    QVector<SequenceDiagram *> sequnceTabs;

private slots:
    void selectTab(int index);

};

#endif // DIAGRAMTABWIDGET_HH
