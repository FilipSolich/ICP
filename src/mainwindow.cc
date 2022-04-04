/**
 * \file mainwindow.cc
 *
 * \brief Source code for MainWindow class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

// Some code was taken from https://doc.qt.io/qt-6/qtwidgets-tutorials-notepad-example.html

#include <QComboBox>
#include <QFileDialog>
#include <QGraphicsItem>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QTextStream>

#include "cdeditorscene.hh"
#include "edgecombobox.hh"
#include "fileprocessor.hh"
#include "itemtype.hh"
#include "mainwindow.hh"
#include "ui_mainwindow.h"

class DiagramTabWidget;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui{new Ui::MainWindow}
{
    ui->setupUi(this);

    setWindowTitle("UML Editor");

    tabs = new DiagramTabWidget(this);
    ui->centralwidget->layout()->addWidget(tabs);

    diagram = new Diagram(tabs->classTab, &(tabs->sequenceTabs), this);

    edgeComboBox = new EdgeComboBox(this);
    ui->toolBar->addWidget(edgeComboBox);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::save);
    connect(ui->actionSave_as, &QAction::triggered, this, &MainWindow::saveAs);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exit);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAdd_class, &QAction::triggered, this, &MainWindow::addClass);
    connect(ui->actionRemove_selected, &QAction::triggered, this, &MainWindow::removeSelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newDocument()
{
    closeCurrentDiagram();
    currentFile.clear();
    diagram = new Diagram(tabs->classTab, &(tabs->sequenceTabs), this);
}

void MainWindow::open()
{
    closeCurrentDiagram();

    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file{fileName};
    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle("UML Editor - " + fileName);

    QTextStream in{&file};
    QString text = in.readAll();

    FileProcessor parser{this};
    diagram = parser.parseFile(tabs, &text);

    file.close();
}

void MainWindow::save()
{
    QString fileName;
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        if (fileName.isEmpty()) {
            return;
        }
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }

    QFile file{fileName};
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setWindowTitle("UML Editor - " + fileName);

    FileProcessor generator{this};
    QString text = generator.generateFile(diagram);

    QTextStream out{&file};
    out << text;

    file.close();

    if (diagram != nullptr) {
        diagram->unsavedChanges = false;
    }
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file{fileName};
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    currentFile = fileName;
    setWindowTitle("UML Editor - " + fileName);

    FileProcessor generator{this};
    QString text = generator.generateFile(diagram);

    QTextStream out{&file};
    out << text;

    file.close();

    if (diagram != nullptr) {
        diagram->unsavedChanges = false;
    }
}

void MainWindow::exit()
{
    closeCurrentDiagram();
    close();
}

void MainWindow::cut(){} // TODO
void MainWindow::copy(){} // TODO
void MainWindow::paste(){} // TODO
void MainWindow::undo(){} // TODO

void MainWindow::about()
{
    QWidget *about = new QWidget();
    about->resize(400, 200);
    about->setWindowTitle("About");

    QLabel *label = new QLabel(about);
    label->setAlignment(Qt::AlignCenter);
    label->setText("Version: v1.0.0\nIcons are provided by Icons8\nhttps://icons8.com");

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(label);

    about->setLayout(layout);
    about->show();
}

void MainWindow::closeCurrentDiagram(void)
{
    if (diagram != nullptr) {
        if (diagram->unsavedChanges) {
            QMessageBox *mg = new QMessageBox;
            mg->setWindowTitle("Save changes");
            mg->setText("Diagram have unsaved changes");
            mg->addButton(QMessageBox::Discard);
            mg->addButton(QMessageBox::Save);
            int code = mg->exec();

            if (code == QMessageBox::Save) {
                save();
            }
        }

        delete diagram;
        diagram = nullptr;
    }
}

void MainWindow::addClass()
{
    diagram->addClass();
}

void MainWindow::removeSelected()
{
    QList<QGraphicsItem *> items;
    if (tabs->currentIndex() == 0) {
        CDEditorScene *scene = static_cast<CDEditor *>(tabs->currentWidget())->scene;
        items = scene->selectedItems();
    } else {
        // TODO sequence scene
    }

    for (QGraphicsItem *item : qAsConst(items)) {
        if (item->type() == ItemTypeCDClass) {
            CDClassItem *i = static_cast<CDClassItem *>(item);
            delete i->cdClass->cls;
        } else if (item->type() == ItemTypeCDEdge) {
            CDEdgeItem *i = static_cast<CDEdgeItem *>(item);
            delete i->cdEdge;
        }
    }
}
