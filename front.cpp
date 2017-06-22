#include "front.h"
#include "ui_front.h"
#include <QDeclarativeView>
#include <QMainWindow>
front::front(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::front)
{
    ui->setupUi(this);
   // setWindowIcon(QPixmap(":/images/ic.png"));
    setWindowTitle("Learn Words About");
    this->setWindowFlags(Qt::Dialog
                         | Qt::WindowCloseButtonHint );
}

front::~front()
{
    delete ui;
}

void front::on_actionClose_triggered()
{
    this->close();
}
