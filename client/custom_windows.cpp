#include "custom_windows.h"
#include "ui_custom_windows.h"
#include <QtGui>
#include <iostream>
QString min_button_stylesheet="QPushButton{border-image: url(:/title/collapse/collapse_default.png);}\
        QPushButton:hover{border-image: url(:/title/collapse/collapse_hover.png);}\
        QPushButton:pressed{border-image: url(:/title/collapse/collapse_hover.png);}";
QString close_button_stylesheet="QPushButton{border-image: url(:/title/close/close_default.png);}\
        QPushButton:hover{border-image: url(:/title/close/close_hover.png);}\
        QPushButton:pressed{border-image: url(:/title/close/close_hover.png);}";
custom_windows::custom_windows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::custom_windows)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    init_basebutton();
    ui->setupUi(this);
}
void custom_windows::init_basebutton()
{
    Base_layout = new QGridLayout(this);
    Min_button = new QPushButton(this);
    Close_button = new QPushButton(this);
    Min_button->setFixedSize(12,15);
    Close_button->setFixedSize(20,20);
    Min_button->setStyleSheet(min_button_stylesheet);
    Close_button->setStyleSheet(close_button_stylesheet);
    connect(Min_button,SIGNAL(clicked()),this,SLOT(min_clicked()));
    connect(Close_button,SIGNAL(clicked()),this,SLOT(min_clicked()));
    Close_button->setGeometry((width()-5),3,20,20);
    Min_button->setGeometry(755,6,20,20);
}

void custom_windows::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed)
    move(event->pos() - m_point + pos());

}
void custom_windows::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
       {
           m_bPressed = true;
           m_point = event->pos();
       }
}
void custom_windows::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed = false;
}
void custom_windows::min_clicked()
{
    std::cout<<1<<std::endl;
    std::cout<<width()<<std::endl;
    //this->hide();
}
void custom_windows::close_clicked()
{
    this->hide();
}
custom_windows::~custom_windows()
{
    delete ui;
}
