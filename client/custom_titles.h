#ifndef CUSTOM_TITLES_H
#define CUSTOM_TITLES_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QWindow>
#include <QString>
class QLabel;
class QpushButton;

class custom_titles : public QWidget
{
    Q_OBJECT
public:
    explicit custom_titles(QWidget *parent = nullptr);
    ~custom_titles();
protected:
//    virtual void mouseDoubleClickEvent(QMouseEvent *event);
//    virtual void mousePressEvent(QMouseEvent *event);
//    virtual bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void min_clicked();
    void max_clicked();
    void close_clicked();
private:
    void updateMaximize();
private:
    //QLabel *m_pIconLabel;
    //QLabel *m_pTitleLabel;
    QPushButton *max_button;
    QPushButton *min_button;
    QPushButton *close_button;
};

#endif // CUSTOM_TITLES_H
