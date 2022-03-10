/**
 * \file mainwindow.hh
 *
 * \brief Main window class.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

#include "diagram.hh"
#include "diagramtabwidget.hh"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    QString currentFile;
    Diagram *diagram = nullptr;

    void closeCurrentDiagram(void);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    DiagramTabWidget *tabs = nullptr;

private slots:
    void newDocument();
    void open();
    void save();
    void saveAs();
    void exit();
    void cut();
    void copy();
    void paste();
    void undo();
    void about();
};
#endif // MAINWINDOW_HH
