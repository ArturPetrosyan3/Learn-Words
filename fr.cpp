#include "fr.h"
#include "ui_fr.h"

#include <QDebug>
//int SlideTime = 0;
fr::fr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fr)
{
    ui->setupUi(this);
    setWindowTitle("Learn Words");
    this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint );
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_5->setAlignment(Qt::AlignCenter);
    QString a = "Language 1";
    ui->label_4->setText(a);
    ui->label_5->setText("Language 2");
    ob.k=0;

    qDebug() << "SlideTime" << SlideTime;
    ob.myTimer.start(SlideTime, this);
   // ob.myTimer.stop();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection1");
    db.setDatabaseName(ob.Fstr);

    qDebug() << "constructor " << ob.Fstr;
    qDebug() << "Rput2 constructor" <<ob.Rpath;


    QVector<QStringList> lst;
    if (!db.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db.lastError().text()));
        return;
     }
     QSqlQuery query(db);
     query.exec("SELECT * FROM word");
     while (query.next()) {
         QSqlRecord record = query.record();
         QStringList tmp;
            for(int i=0; i < record.count(); i++)
             {
                 tmp << record.value(i).toString();
             }
             lst.append(tmp);
         }
     foreach (const QStringList &var, lst) {
        ob.slide_count12++;
     }
     //qDebug() << slide_count;
     ////////////////////////////////
     for (int i=0;i<ob.slide_count12;i++){
            ob.s[i] = lst[i][0];
     }
     for (int i=0;i<ob.slide_count12;i++){
            ob.s1[i] = lst[i][1];
     }
     for (int i=0;i<ob.slide_count12;i++){
            ob.s3[i] = lst[i][2];
     }

}

fr::~fr()
{
    delete ui;
    //delete ob;
}


void fr::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}
void fr::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void fr::timerEvent(QTimerEvent *e)
{
        QString vo;
        QString pix(ob.s[ob.k]);
        QString pix1(ob.s1[ob.k]);
        QString pix3(ob.s3[ob.k]);
        QString pix_vice,pix_3_voice;
        QProcess* newProcess = new QProcess();
        QDir qdWDir;
        QString sWDir = qdWDir.absolutePath();
        sWDir.append("/");
        QDir::setCurrent(sWDir);
        //newProcess->start("espeak.exe -v female5 -s 120 -a 50 "+voice+"");
        //qDebug() << " sdfasdfasfd" <<slide_count;
        if (ui->checkBoxTurnoff->isChecked()){
            vo = "50";
        } else {
            vo = "0";
        }

        if (e->timerId() == ob.myTimer.timerId()) {
            if (ob.k==ob.slide_count12){
                ob.k=0;
            }else {

                if (ui->radioButton->isChecked()) {
                    if (ui->checkBoxread->isChecked()){
                        ui->label_3->setText(pix3);
                        pix_3_voice=pix3;
                        pix_3_voice.push_front('"');
                        pix_3_voice.push_front(" ");
                        pix_3_voice.push_front((QString)vo);
                        pix_3_voice.push_back('"');

                        newProcess->start("espeak.exe -v female5+f5 -s 120 -a "+pix_3_voice+"");
                    } else {
                        ui->label_3->setText("Check the Read sentence to listen sentence.");
                        pix_vice = pix;
                        pix_vice.push_front('"');
                        pix_vice.push_front(" ");
                        pix_vice.push_front((QString)vo);
                        pix_vice.push_back('"');
                        qDebug() << "pix_vice" << pix_vice;
                        newProcess->start("espeak.exe -v female5+f5 -s 120 -a "+pix_vice+"");
                    }
                    ui->label_4->setText(pix);
                    ui->label_5->setText(pix1);
                    ob.k++;
                }
                if (ui->radioButton_2->isChecked()){
                    if (ui->checkBoxread->isChecked()){
                        ui->label_3->setText(pix3);
                        pix_3_voice=pix3;
                        pix_3_voice.push_front('"');
                        pix_3_voice.push_front(" ");
                        pix_3_voice.push_front((QString)vo);
                        pix_3_voice.push_back('"');

                        newProcess->start("espeak.exe -v female5+f5 -s 120 -a "+pix_3_voice+"");
                    } else {
                        ui->label_3->setText("Check the Read sentence to listen sentence.");
                        pix_vice = pix;
                        pix_vice.push_front('"');
                        pix_vice.push_front(" ");
                        pix_vice.push_front((QString)vo);
                        pix_vice.push_back('"');
                        qDebug() << "pix_vice" << pix_vice;
                        newProcess->start("espeak.exe -v female5+f5 -s 120 -a "+pix_vice+"");
                    }
                    ui->label_4->setText(pix1);
                    ui->label_5->setText(pix);
                    ob.k++;
                }
            }
        }
}

void fr::on_back_clicked()
{
    qDebug() << "back " << ob.Fstr;
    ob.Fstr = "";
    ob.slide_count12=0;
    ob.myTimer.stop();
    this->close();
}

void fr::on_horizontalSlider_valueChanged(int value)
{
    SlideTime = value;
    ob.myTimer.stop();
    ob.myTimer.start(SlideTime, this);
    //qDebug() << SlideTime ;
    //qDebug() << value;
}
