#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_close_clicked();

    void on_collapse_clicked();

    void on_Sign_up_clicked();

    void on_login_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
