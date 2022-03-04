/**
 * \file mainwindow.hh
 *
 * \brief Header file for class MainWindow.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    QString currentFile;
};
#endif // MAINWINDOW_HH
