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

