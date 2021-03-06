/**
 * \file mainwindow.hh
 *
 * \brief Class implementing application main window.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QUndoStack>
#include <QGraphicsItem>

#include "edgecombobox.hh"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class DiagramTabWidget;
class Diagram;

/**
 * Class implementing application main window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    QString currentFile;
    Diagram *diagram = nullptr;

    QUndoStack *undoStack = nullptr;

    /**
     * Function close current diagram and clear graphics scenes.
     */
    void closeCurrentDiagram(void);

public:
    DiagramTabWidget *tabs = nullptr;
    EdgeComboBox *edgeComboBox = nullptr;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    /**
     * Save old position of QGraphicsItem in undo stack
     *
     * @param item moved QGraphicsItem
     * @param oldPosition old position of moved item
     */
    void itemMoved(QGraphicsItem *item, const QPointF &oldPosition);

private slots:
    /**
     * Slot for 'New' button.
     */
    void newDocument();

    /**
     * Slot for 'Open' button.
     */
    void open();

    /**
     * Slot for 'Save' button.
     */
    void save();

    /**
     * Slot for 'Save as' button.
     */
    void saveAs();

    /**
     * Slot for 'Exit' button.
     */
    void exit();

    /**
     * Slot for 'Undo' button.
     */
    void undo();

    /**
     * Slot for about window.
     */
    void about();

    /**
     * Slot for 'Add class' button.
     */
    void addClass();

    /**
     * Slot for 'Remove selected' button.
     */
    void removeSelected();
};
#endif // MAINWINDOW_HH
