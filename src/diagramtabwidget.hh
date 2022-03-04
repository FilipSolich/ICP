/**
 * \file diagramtabwidget.hh
 *
 * \brief Header file for DiagramTabWidget class.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#ifndef DIAGRAMTABWIDGET_HH
#define DIAGRAMTABWIDGET_HH

#include <QTabWidget>
#include <QWidget>

class DiagramTabWidget : public QTabWidget
{
    Q_OBJECT

    int sequenceDiagramCounter = 1;

    void addDummyTab(void);

public:
    explicit DiagramTabWidget(QWidget *parent = nullptr);

private slots:
    void addSequenceTab(int index);

};

#endif // DIAGRAMTABWIDGET_HH
