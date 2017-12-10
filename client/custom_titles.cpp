#include "custom_titles.h"

custom_titles::custom_titles(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(20);
    QString min_button_stylesheet="QPushButton{border-image: url(:/title/collapse/collapse_default.png);}\
            QPushButton:hover{border-image: url(:/title/collapse/collapse_hover.png);}\
            QPushButton:pressed{border-image: url(:/title/collapse/collapse_hover.png);}";
    QString close_button_stylesheet="QPushButton{border-image: url(:/title/close/close_default.png);}\
            QPushButton:hover{border-image: url(:/title/close/close_hover.png);}\
            QPushButton:pressed{border-image: url(:/title/close/close_hover.png);}";
    max_button = new QPushButton(this);
    min_button = new QPushButton(this);
    close_button = new QPushButton(this);

    min_button->setStyleSheet(min_button_stylesheet);
    min_button->setFixedSize(12,15);
    close_button->setStyleSheet(close_button_stylesheet);
    close_button->setFixedSize(20,20);

    QHBoxLayout *base_layout = new QHBoxLayout(this);
    base_layout->addWidget(min_button);
    base_layout->addWidget(close_button);

    setLayout(base_layout);

    connect(min_button,SIGNAL(clicked(bool)),this,SLOT(min_clicked()));
    connect(close_button,SIGNAL(clicked(bool)),this,SLOT(close_clicked()));
}

void custom_titles::max_clicked()
{

}

void custom_titles::min_clicked()
{
    this->hide();
}

void custom_titles::close_clicked()
{

}
custom_titles::~custom_titles()
{
    this->close();
}
