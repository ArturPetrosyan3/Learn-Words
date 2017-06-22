#pragma once

#include <QFrame>
#include "mainwindow.h"

class Frame : public QFrame
{
Q_OBJECT

public:
    Frame( QWidget* );

    void setCircleRadius( int );
void drawLines(QPainter *painter);


protected:
    void paintEvent( QPaintEvent* );

private:
    int m_radius;
    QPainter painter;

    MainWindow *ob;
    QString aaa;
};
