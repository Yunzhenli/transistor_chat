#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QTcpSocket>
#include <iostream>
#include <QSystemTrayIcon>
const int port = 1007;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setAreaMovable(const QRect rt);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent();
    void send_userdata(const char* user_name,const char* pass_word);

private slots:
    void on_close_clicked();

    void on_collapse_clicked();

    void on_Sign_up_clicked();

    void on_login_clicked();

    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
private:
    QRect m_areaMovable;
    bool m_bPressed;
    QPoint m_ptPress;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
