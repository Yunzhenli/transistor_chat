#ifndef CUSTOM_WINDOWS_H
#define CUSTOM_WINDOWS_H

#include <QWidget>
#include <QPoint>
#include <QApplication>
#include <QWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QString>
#include <QLayout>
#include <QGridLayout>
#include <QDebug>
namespace Ui {
class custom_windows;
}

class custom_windows : public QWidget
{
    Q_OBJECT

public:
    explicit custom_windows(QWidget *parent = 0);
        ~custom_windows();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void init_basebutton();
private slots:
    void min_clicked();
    void close_clicked();
private:
    QPoint m_point;
    bool m_bPressed;
    QPushButton *Close_button;
    QPushButton *Min_button;
    QGridLayout *Base_layout;
    Ui::custom_windows *ui;
};

#endif // CUSTOM_WINDOWS_H
