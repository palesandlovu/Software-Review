#include <QApplication>
#include "mainwindow.h"
#include <QString>
#include <QDate>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow main;
    main.show(); //call mainwindow/GUI

    return a.exec();
}
