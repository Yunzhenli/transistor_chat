#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.move(600,400);
    w.show();
    return a.exec();
}
