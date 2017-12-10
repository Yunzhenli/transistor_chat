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
/*
 *
 *Will Do:
 * Context menu
 * Too many tray icons
 * double click
 *
*/
int testnum = 0;
QString user_name,pass_word;
QSystemTrayIcon *login_winicon;
QMenu * login_menu;
QAction * show_login_action;
QAction * exit_login_action;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_areaMovable = geometry();
    m_bPressed = false;
    setWindowFlags(Qt::FramelessWindowHint);
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
    create_Action();
    create_menu();
    login_winicon->show();
}

void MainWindow::create_Action()
{
    show_login_action = new QAction(QObject::trUtf8("Show Login Window"),this);
    connect(show_login_action,SIGNAL(triggered()),this,SLOT(_show_login_window()));
    exit_login_action = new QAction(QObject::trUtf8("Exit Aciton"),this);
    connect(exit_login_action,SIGNAL(triggered()),this,SLOT(_exit_login_window()));
}
void MainWindow::create_menu()
{
    login_menu = new QMenu(this);
    login_menu->addAction(show_login_action);
    login_menu->addSeparator();
    login_menu->addAction(exit_login_action);
    login_winicon->setContextMenu(login_menu);
}
void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        this->show();
        //login_winicon->hide();
        break;
    default:
        break;
    }
}
void MainWindow::_show_login_window()
{
    this->show();
    resize(200,200);
}
void MainWindow::_exit_login_window()
{
    exit(0);
}
void MainWindow::on_Sign_up_clicked()
{
    custom_titles *title = new custom_titles(this);
    //QDesktopServices::openUrl(QUrl(QLatin1String("http://transistor107.org")));
    window1.show();
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
