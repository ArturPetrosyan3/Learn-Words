#include "message.h"
#include "ui_message.h"

message::message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);

   // this->setFocusProxy(this);

    this->setFocusPolicy(Qt::ClickFocus);
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint );
    this->setFocusPolicy(Qt::ClickFocus);
    ui->label->setText(ob1.search_dic);
    ui->label_2->setText(ob1.transl_for_pic);
    ui->label_3->setText(ob1.sent_for_pict);

    QPixmap watermark(ob1.pic_path);
    QPixmap newPixmap = watermark.scaled(QSize(334,150),  Qt::KeepAspectRatio);
    ui->pic_label->setPixmap(newPixmap);
    ob1.search_dic.clear();
      this->setFocusPolicy(Qt::ClickFocus);
}

message::~message()
{
    delete ui;
}


void message::mouseMoveEvent(QMouseEvent *event)
{

    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);

        event->accept();
    }
}
void message::mousePressEvent(QMouseEvent *event)
{
   // eventFilter(this,event);
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();

        event->accept();
    }
    if(event->button() == Qt::RightButton){
        this->close();
    }
}
void message::mouseReleaseEvent(QMouseEvent *event){
    if (event->type() == QEvent::FocusOut)
    {
           this->close();
    }
}

bool message::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::FocusOut ||
        event->type() == QEvent::KeyPress ||
        event->type() == QEvent::MouseButtonPress)
    {
       // while (!ttWidgets.isEmpty()) {
            //ToolBarWidget * p = ttWidgets->takeFirst();
            this->close();
            this->deleteLater();
        //}
    }
    return message::eventFilter(obj, event);
}

void message::focusOutEvent(QFocusEvent * event)
    {
       this->close();
    }
void message::on_pushButton_clicked()
{

}

void message::on_pushButton_2_clicked()
{
    //ob1->next_wordss = 0;

    this->close();
    //qDebug() << "sdfasdfasdaaaaaaaaaaaaa" << ob1->next_wordss;
}
