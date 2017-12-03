#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDesktopServices>
#include <QUrl>
#include <QtWebView/QtWebView>

int testnum = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->password_Edit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{

}
void MainWindow::on_close_clicked()
{
    exit(0);
}

void MainWindow::on_collapse_clicked()
{
    std::cout<<"debug_collapse"<<std::endl;
}

void MainWindow::on_Sign_up_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://transistor107.org")));
}

void MainWindow::on_login_clicked()
{
    testnum+=1;
    std::cout<<"Debug_login"<<testnum<<std::endl;
}
