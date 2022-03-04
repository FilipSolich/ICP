#include "mainwindow.hh"
#include "ui_mainwindow.h"

// TODO: add about link to https://icons8.com
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newDocument(){}

void MainWindow::open(){}
void MainWindow::save(){}
void MainWindow::saveAs(){}
void MainWindow::cut(){}
void MainWindow::copy(){}
void MainWindow::paste(){}
void MainWindow::undo(){}
void MainWindow::about(){}
