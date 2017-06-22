#ifndef FRONT_H
#define FRONT_H

#include <QMainWindow>

namespace Ui {
class front;
}

class front : public QMainWindow
{
    Q_OBJECT

public:
    explicit front(QWidget *parent = 0);
    ~front();

private slots:


    void on_actionClose_triggered();

private:
    Ui::front *ui;
};

#endif // FRONT_H
