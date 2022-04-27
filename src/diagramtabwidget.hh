/**
 * \file diagramtabwidget.hh
 *
 * \brief `DiagramTabWidget` class representing tab bar for users diagram.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef DIAGRAMTABWIDGET_HH
#define DIAGRAMTABWIDGET_HH

#include <QTabWidget>
#include <QWidget>

#include "cdeditor.hh"
#include "mainwindow.hh"
#include "sequenceeditor.hh"

/**
 * Tab widget for class diagram and sequence diagrams.
 */
class DiagramTabWidget : public QTabWidget
{
    Q_OBJECT

    MainWindow *parent;
    int sequenceDiagramCounter = 1;

    /**
     * Add dummy tab with "+" name which create new sequence diagram if pressed.
     */
    void addDummyTab();

public:
    CDEditor *classTab;
    QVector<SequenceEditor *> sequenceTabs;

    /**
     * Constructor.
     *
     * \param parent Pointer to parent window.
     */
    explicit DiagramTabWidget(QWidget *parent = nullptr);

public slots:

    /**
     * Slot for adding new sequence diagram.
     *
     * \param index Index of selected tab.
     */
    void selectTab(int index);

};

#endif // DIAGRAMTABWIDGET_HH
