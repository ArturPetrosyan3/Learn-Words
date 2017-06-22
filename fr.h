#ifndef FR_H
#define FR_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class fr;
}

class fr : public QDialog
{
    Q_OBJECT

public:
    explicit fr(QWidget *parent = 0);
    ~fr();
    MainWindow ob;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    //virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_back_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::fr *ui;
    QPoint m_dragPosition;
    int SlideTime = 7000;


};

#endif // FR_H
