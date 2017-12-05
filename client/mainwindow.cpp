#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDesktopServices>
#include <QUrl>
#include <QtWebView/QtWebView>
#include <QDebug>
#include <string>
#include <QHostAddress>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QtGui>
#include <QObject>
int testnum = 0;
QString user_name,pass_word;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_areaMovable = geometry();
    m_bPressed = false;
    ui->setupUi(this);
    ui->password_Edit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bPressed)
    {
        move(pos()+event->pos() - m_ptPress);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_ptPress = event->pos();
        m_bPressed = m_areaMovable.contains(m_ptPress);
    }
}
void MainWindow::mouseReleaseEvent()
{
    m_bPressed = false;
}
void MainWindow::setAreaMovable(const QRect rt)
{
    if(m_areaMovable !=rt)
    {
        m_areaMovable = rt;
    }
}

void MainWindow::on_close_clicked()
{
    exit(0);
}

void MainWindow::on_collapse_clicked()
{
    this->hide();
    QSystemTrayIcon *login_winicon;
    //delete login_winicon;
    //TODO:toomany icons
    login_winicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon("../client/resource/logo_default.png");
    login_winicon->setIcon(icon);
    //login_winicon->setToolTip(QObject::trUtf8("Transistor Chat \n Design for geek"));
    connect(login_winicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
    login_winicon->show();
}
void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        this->show();
        break;
    default:
        break;
    }
}
void MainWindow::on_Sign_up_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://transistor107.org")));
}

void MainWindow::on_login_clicked()
{
    user_name=ui->username_Edit->text();
    pass_word=ui->password_Edit->text();
    const char* user_name_c = (user_name.toStdString()).c_str();
    const char* pass_word_c = (pass_word.toStdString()).c_str();
    send_userdata(user_name_c,pass_word_c);
}

void MainWindow::send_userdata(const char* user_name,const char* pass_word)
{
   QTcpSocket *client_socket;
   client_socket = new QTcpSocket(this);
   client_socket->connectToHost(QHostAddress("127.0.0.1"),23333);
   client_socket->write(user_name);
   client_socket->write(pass_word);
}
