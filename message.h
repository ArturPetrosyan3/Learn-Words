#ifndef MESSAGE_H
#define MESSAGE_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class message;
}

class message : public QDialog
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = 0);
    ~message();
    MainWindow ob1;
    QString num;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void focusOutEvent(QFocusEvent * event);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::message *ui;
    QPoint m_dragPosition;
};

#endif // MESSAGE_H
