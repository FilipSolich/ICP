/**
 * \file main.cc
 *
 * \brief Entry point of the program.
 *
 * \date 4. 3. 2022
 * \author Filip Solich
 */

#include <QApplication>

#include "mainwindow.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.showMaximized();

    return a.exec();
}
