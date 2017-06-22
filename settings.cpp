#include "settings.h"
#include "ui_settings.h"
#include "QDebug"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    setWindowTitle("Settings");
   // this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint );
    //ob.play_words = true;
    //ob->mess_size = 10;
    if (ob->storige){


        QString time = QDate::currentDate().toString();
        QString time1 = QTime::currentTime().toString();
        time.append("_");
        time.append(time1);
        time.replace(" ","_");
        time.replace(":","_");


        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection12313");
        db.setDatabaseName(ob->path_to_add_mis_table);
        if (!db.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db.lastError().text()));
            return;
         }
         QSqlQuery query(db);
         query.exec("select * from Mis_C");
         query.last();
         int i =0;
         i = query.at() + 2;
         query.prepare("INSERT INTO Mis_C (rowid,Word,Sentence,Pictures,Translation) values(:rowid,:Word,:Sentence,:Pictures,:Translation)");

         query.bindValue(":rowid",i);
         query.bindValue(":Word",i);
         query.bindValue(":Sentence","");
         query.bindValue(":Pictures","");
         query.bindValue(":Translation","");
         query.exec();

         QString tableName_m = "";
       //  qDebug() <<"iiiiiiiiiiiiiiiiii"<< i;
         QString to_app = QString::number(i);
         //tableName_m.append("_");
        tableName_m.append(time);
         //qDebug()<< ob->path_to_add_mis_table;
         ob->name_of_the_new_table.append(tableName_m);
         QString tableParams_m = "Word,Translation,Sentence,Pictures,Comment,Count,picpath";

            if(!tableName_m.isEmpty() && !tableParams_m.isEmpty())
            {
                if(!query.exec("CREATE TABLE "+tableName_m+" ("+tableParams_m+")"))
                qDebug() << "Somthing wrong!" << query.lastError().text();
            }
    }
    ui->spinBox->setValue(ob->mess_size);
    ui->spinBox->setValue(10);
    ui->checkBox_4->setChecked(ob->play_words);
    ui->checkBox_5->setChecked(ob->play_table_word);


}

settings::~settings()
{
    delete ui;
}

void settings::on_checkBox_4_clicked()
{
    if (ui->checkBox_4->isChecked()){
        ob->play_words = true;
        qDebug() << ob->play_words;
    } else {
        ob->play_words = false;
        qDebug() <<"sdfsd"<< ob->play_words;
    }
}

void settings::on_spinBox_valueChanged(int arg1)
{
   ob->mess_size = arg1;
    ob->size_of_the_job = arg1;
}

void settings::on_checkBox_5_clicked()
{
    if (ui->checkBox_5->isChecked()){
        ob->play_table_word = true;
       // qDebug() << ob->play_words;
    } else {
        ob->play_table_word = false;
       // qDebug() <<"sdfsd"<< ob->play_words;
    }
}

void settings::on_pushButton_clicked()
{
    ob->next_wordss = 1;
}

void settings::on_pushButton_2_clicked()
{
    ob->next_wordss = 0;
}

void settings::on_new_table_clicked()
{

}

void settings::on_checkBox_7_clicked()
{
    if (ui->checkBox_7->isChecked()){
         ob->storige = true;
    } else {
        ob->storige = false;
    }
}

void settings::on_pushButtonclosesettings_clicked()
{
    this->close();
}

void settings::on_radioButton_2_clicked()
{
    ob->see_mistakes_=true;
}
