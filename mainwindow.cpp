#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "picture.h"
#include <algorithm>

#include "ui_picture.h"
#include "message.h"
#include "fr.h"
#include <QSqlQuery>
#include <QtAlgorithms>
#include <QMessageBox>
#include <QMenu>
#include <QStandardItemModel>
#include <QCheckBox>
#include <QSqlDatabase>
#include <QDir>
#include <QUrl>
#include <QIcon>
#include <QToolButton>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QTreeWidget>
#include <QFileDialog>
#include <QProgressDialog>
#include <QTimer>
#include "front.h"
//#include "picture.h"
#include <QDeclarativeView>
#include <QBasicTimer>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QLineEdit>
#include <QtWebKitWidgets/QWebView>
#include <QUrl>
#include <QWidgetAction>
#include <QToolButton>
#include <QStyleFactory>
#include "settings.h"
#include "frame.h"


#include "charts/barchartplotter.h"
#include "charts/axisbase.h"

//QVector<QString> MainWindow::Chart_words;
QVector<int> MainWindow::c;

QVector<int> MainWindow::Chart_count ;
QString MainWindow::pic_path;
QString MainWindow::search_dic;
QString MainWindow::sent_for_pict;
QString MainWindow::transl_for_pic;

QStringList MainWindow::Chart_words1 = QStringList() ;

QString MainWindow::Rpath;
QString MainWindow::Fstr;

QLineEdit* lineedit;
QPushButton * SearchButton;
QPushButton * SearchButton1;
QPushButton * SearchButton2;
QPushButton * radio;
QPushButton * About;
QPushButton * synonyms;
const QString Rapath = "C:/" ;
int time = 7000;

QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE", "connection");
QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "connection34");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{
    ui->setupUi(this);
    setWindowTitle("Learn Words");
 //   qDebug() << "Chart_words01"<<Chart_words1;

// qDebug() << "Chart_words0"<< Chart_count;
    m_gl = new my_grid_layout(this,4);
    m_lay_1 = new my_grid_layout(this,5);
    hlayaut = new QHBoxLayout;
    ui->ch_l1->hide();


  //  qDebug()<<c;
    setupModel();

    setupChart();

    //setWindowTitle(QString("ChartXY %1.%2").arg(ChartXY::version()).arg(ChartXY::revision()));

   // vLayout = new QVBoxLayout( this );

////////////////////////
    ui->syny->setHidden(true);

    play_words = true;
    ui->voice_of->hide();
    if (lisens == false) {
        ui->GP_hide->hide();
    }
    ui->GP_hide_2->hide();
    ui->mem_voice_of->hide();
    ui->much_voice_of->hide();


    qDebug() <<QDir::currentPath() + "/sqldrivers/listitems.sqlite";

    ui->actionNorm->setVisible(false);
    //this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint );
    ui->webView4->load(QUrl("qrc:///images/news.html"));


    db2.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");

    if (!db2.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db2.lastError().text()));
        return;
     }

    QSqlQueryModel * modal1 = new QSqlQueryModel();
         QSqlQuery* query1 = new QSqlQuery(db2);
         query1->prepare("select Sentence from word");
         query1->exec();
         modal1->setQuery(*query1);
         ui->listView->setModel(modal1);


         newProcess = new QProcess;



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_synonyms_button() {
    QProcess* newProcess = new QProcess();
    QDir qdWDir;
    QString sWDir = qdWDir.absolutePath();
    sWDir.append("/");
    QDir::setCurrent(sWDir);
    newProcess->start("synonym/synonym.exe");
}



QString search;

void MainWindow::textChangedSlot(QString text)
{
        search = text;

}

void MainWindow::radio_click()
{

 //    rad->load(QUrl("http://www.radioguide.fm/internet-radio-england/bbc4"));

}

//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
////    qDebug() << "X:"+QString::number(event->x())+"-- Y:"+QString::number(event->y());

//}
//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
////    if (event->button() == Qt::LeftButton) {
////        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
////        event->accept();
////    }

//}




void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString Rpath = dirmodel->fileInfo(index).absoluteFilePath();
    qDebug() << Rpath;
    ui->listView->setRootIndex(filemodel->setRootPath(Rpath));
}

//QString Rpath = "";



int slide_count=0;

void MainWindow::on_pushButton_2_clicked()
{

    slide_count12 = 0;
    Fstr = Rpath;
    fr *pic = new fr;
    pic->show();


}




void MainWindow::timerEvent(QTimerEvent *e)
{
//        QString pix(s[k]);
//        QString pix1(s1[k]);
//        //qDebug() << " sdfasdfasfd" <<slide_count;
//        if (e->timerId() == myTimer.timerId()) {
//            if (k==slide_count){
//                k=0;
//            }else {
//                if (ui->radioButton->isChecked()) {
//                    ui->label_4->setText(pix);
//                    ui->label_5->setText(pix1);
//                    k++;
//                }
//                if (ui->radioButton_2->isChecked()){
//                    ui->label_4->setText(pix1);
//                    ui->label_5->setText(pix);
//                    k++;
//                }
//            }
//        }
}



void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_back_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
    slide_count=0;

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowStaysOnTopHint);
    this->show();

}

void MainWindow::keyPressEvent ( QKeyEvent * event )
{
    if ( event->key() == Qt::Key_F && event->modifiers() == Qt::ControlModifier) {
        ui->lineEdit->setFocus();
        ui->lineEdit->setText("");
    }
    if ( event->key() == Qt::Key_I && event->modifiers() == Qt::ControlModifier) {
        ui->add_r->clicked();
    }
    if ( event->key() == Qt::Key_D && event->modifiers() == Qt::ControlModifier) {
        ui->rem_r->clicked();
    }

    if ( event->key() == Qt::Key_S && event->modifiers() == Qt::ShiftModifier) {
        ui->syny->clicked();
    }
}


void MainWindow::on_close_clicked()
{
    this->close();
}



void MainWindow::on_pushButton_4_clicked()
{

}



void MainWindow::showTable(QString tableName)
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection");
        db.setDatabaseName(Rpath);
        if (!db.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db.lastError().text()));
            return ;
        }
        QSqlTableModel *model = new QSqlTableModel(0, db);
        model->setTable(tableName);
        ui->tableView->setModel(model);
        model->select();

}


void MainWindow::on_pushButton_8_clicked()
{
    //QString search;
   // search = ui->search->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection1");
    db.setDatabaseName(Rpath);
    if (!db.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db.lastError().text()));
        return;
     }
    QSqlTableModel *model = new QSqlTableModel(0, db);
     QSqlQuery query(db);
     query.exec("select * from word were WHERE Word='" + search + "' or Sentence='" + search +"' or Translation='" + search +"' ");
     while (query.next()) {
         model->setQuery(query);
         ui->tableView->setModel(model);
     }

}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->stackedWidget->currentIndex() == 1) {
    int count = ui->tableView->selectionModel()->selectedIndexes().count();

    for( int i = 0; i < count; i++)
        ui->tableView->model()->removeRow( ui->tableView->selectionModel()->selectedIndexes().at( i).row(), QModelIndex());
    QSqlTableModel *model = new QSqlTableModel(0, db1);

    model->setTable("word");
    ui->tableView->setModel(model);

    ui->tableView->setSortingEnabled(true);
    model->select();

      ui->tableView->resizeColumnsToContents();
}
}


void MainWindow::on_pushButton_7_clicked()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, tr("New File"), QString(),
                                                    tr("Database Files (*.sqlite *.sqlite3 *.db)"));
    //qDebug() << fileName;
    Rpath=fileName;
    if (!fileName.isEmpty())
    {

        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            qDebug() << "Imposible to create database!";
        }
        QRegExp rxlen("([^/]+)\.([^/]+$)");
        int pos = rxlen.indexIn(Rpath);
         QString list;
         if (pos > -1) {
             list = rxlen.cap(2);
         }
         QStringList SubStringList = list.split(".sqlite");
         ui->comboBox->clear();
         ui->comboBox->addItem(SubStringList[0]);
         ui->comboBox->addItem("Classified");

    QString tableName = "word";
    QString tableNam1 = "Mis_C";
    QString tableNam2 = "Classification";


    QString tableParams = "Word,Translation,Sentence,Pictures,Comment,ValueTheDifficulty,picpath";
    QString tableParams1 = "Word,Translation,Sentence,Pictures,Comment,ValueTheDifficulty,picpath";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
    db.setDatabaseName(fileName);
    if (!db.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db.lastError().text()));
        return;
     }
     QSqlQuery query(db);

        if(!tableName.isEmpty() && !tableParams.isEmpty())
        {
            if(!query.exec("CREATE TABLE IF NOT EXISTS "+tableName+" ("+tableParams+")"))
            qDebug() << "Somthing wrong!" << query.lastError().text();
            if(!query.exec("CREATE TABLE IF NOT EXISTS "+tableNam1+" ("+tableParams+")"))
                qDebug() << "Somthing wrong!" << query.lastError().text();
            if(!query.exec("CREATE TABLE IF NOT EXISTS "+tableNam2+" ("+tableParams1+")"))
                qDebug() << "Somthing wrong!" << query.lastError().text();
        }
        QSqlTableModel *model = new QSqlTableModel(0, db);
        model->setTable("word");
        ui->tableView->setModel(model);
        model->select();



        ///////////
        QSqlDatabase db3 = QSqlDatabase::addDatabase("QSQLITE", "connection34");

        db3.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");
        if (!db3.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db3.lastError().text()));
            return;
         }
         QSqlQuery query1(db3);

        query1.prepare("INSERT INTO word(Word,Sentence,Pictures,Comment) values(:Word,:Sentence,:Pictures,:Comment)");

        //query.bindValue(":rowid",row_count_id);
        query1.bindValue(":Word",Rpath);
        query1.bindValue(":Sentence",SubStringList[0]);
        query1.bindValue(":Pictures","");
        query1.bindValue(":Comment","");
        query1.exec();
        QSqlDatabase db5 = QSqlDatabase::addDatabase("QSQLITE", "connection1");
        db5.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");
        if (!db5.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db5.lastError().text()));
            return;
         }

        QSqlQueryModel * modal1 = new QSqlQueryModel();
             QSqlQuery* query21 = new QSqlQuery(db5);
             query21->prepare("select Sentence from word");
             query21->exec();
             modal1->setQuery(*query21);
             ui->listView->setModel(modal1);
             ui->tableView->setColumnHidden(6, true);
             ui->tableView->setColumnHidden(7, true);
     }
}

void MainWindow::table_open_new(QString str="word"){

    QSqlTableModel *model = new QSqlTableModel(0, db1);

    model->setTable(str);
    ui->tableView->setModel(model);

    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    model->select();
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->comboBox->clear();

    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();
    //ui->label_center->setStyleSheet("QLabel { color : #DCDCDC; }");

    QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }

       QString arr;
       for (int i = 0; i<slist.size();i++)
           arr = slist[i];

       ui->comboBox->addItem(arr);
       ui->comboBox->addItem("Classified");
       QSqlDatabase db77 = QSqlDatabase::addDatabase("QSQLITE", "connection1");
       db77.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");
       if (!db77.open()) {
           qDebug("Error occurred opening the database.");
           qDebug("%s.", qPrintable(db77.lastError().text()));
           return;
        }
       QString g;
        QSqlQuery query(db77);
        query.prepare("select * from word where Sentence='"+arr+"'");
        if(query.exec()){
            while(query.next()){
               g = query.value(0).toString();

            }
        }
        Rpath = g;
        path_to_add_mis_table = g;
        qDebug() << path_to_add_mis_table;
        db1.setDatabaseName(g);
        if (!db1.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db1.lastError().text()));
            return ;
        }
        if (!lisens){
            for (int i=1;i<=16;i++){
                ui->tabWidget_2->removeTab(i);
            }

        }


        table_open_new();
}





int row_id1 =0;

void MainWindow::on_Add_clicked()
{
    int count = ui->tableView->model()->rowCount();
    qDebug() << Rpath;
    db1.setDatabaseName(Rpath);
    if (!db1.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db1.lastError().text()));
        return;
     }
     QSqlQuery query(db1);
     QString picture_name = QString("Pic%1").arg(row_id1);

    query.prepare("INSERT INTO word(rowid,Word,Sentence,Pictures,Translation) values(:rowid,:Word,:Sentence,:Pictures,:Translation)");

    query.bindValue(":rowid",count);
    query.bindValue(":Word","");
    query.bindValue(":Sentence","");
    query.bindValue(":Pictures",picture_name);
    query.bindValue(":Translation","");
    query.exec();
    row_id1++;

    QSqlTableModel *model = new QSqlTableModel(0, db1);

    model->setTable("word");
    ui->tableView->setModel(model);

    ui->tableView->setSortingEnabled(true);
    model->select();

      ui->tableView->resizeColumnsToContents();

}



void MainWindow::on_treeView_activated(const QModelIndex &index)
{

}

void MainWindow::on_actionMin_triggered()
{
    this->showMinimized();
}

void MainWindow::on_actionNorm_triggered()
{
    this->showNormal();
    ui->actionNorm->setVisible(false);
    ui->actionMax->setVisible(true);
}

void MainWindow::on_actionMax_triggered()
{

    this->showMaximized();
    ui->actionMax->setVisible(false);
    ui->actionNorm->setVisible(true);
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_addrow_triggered()
{
    int count = ui->tableView->model()->rowCount();
    ui->tableView->model()->insertRow(count);
}

void MainWindow::on_Deleterow_triggered()
{
    int count = ui->tableView->selectionModel()->selectedIndexes().count();
    for( int i = 0; i < count; i++)
        ui->tableView->model()->removeRow( ui->tableView->selectionModel()->selectedIndexes().at( i).row(), QModelIndex());

}


int listsize;

void MainWindow::on_pushButton1_clicked()
{



    name_of_the_new_table.clear();

    settings sett;
    sett.setModal(true);
    sett.exec();
    //sett.close();
    size_of_the_job = mess_size;
    deleted_match_words = 0;



    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(0);
    on_tabWidget_tabBarClicked(0);



}





void MainWindow::on_pushButton2_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton3_clicked()
{
    on_pushButton_7_clicked();
    ui->stackedWidget->setCurrentIndex(1);
}




QString row;
QString row_first;
int aaa,bbb;


void MainWindow::count_same_words(QStringList word) {

    int seen[word.size()];
        for(int i = 0; i < word.size(); i++)
            seen[i] = 0;

        for(int i = 0; i < word.size(); i++) {
            if(seen[i] == 0) {
                int count = 0;
                for(int j = i; j < word.size(); j++)
                    if(word[j] == word[i]) {
                        count += 1;
                        seen[j] = 1;
                    }
                chart_names.append(word[i]);
                count_vords.append(count);;
            }
        }
        qDebug() << chart_names;
        qDebug() << count_vords;
}

QStringList MainWindow::count_same_words_ret(QStringList translation) {
    QStringList ret;
    int seen[translation.size()];
        for(int i = 0; i < translation.size(); i++)
            seen[i] = 0;

        for(int i = 0; i < translation.size(); i++) {
            if(seen[i] == 0) {
                int count = 0;
                for(int j = i; j < translation.size(); j++)
                    if(translation[j] == translation[i]) {
                        count += 1;
                        seen[j] = 1;
                    }
                ret.append(translation[i]);
                //count_vords.append(count);;
            }
        }
        return ret;
}



void MainWindow::on_listfirst_clicked(const QModelIndex &index)
{
    QModelIndexList list =ui->listfirst->selectionModel()->selectedIndexes();
    //ui->widget->setStyleSheet("QWidget {border: 1px solid #ff3939;};");
    //aaa = index.row();
    bbb = index.row();
     qDebug() << aaa;
     qDebug() << bbb;
    QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }

       QString arr;
       for (int i = 0; i<slist.size();i++)
           arr = slist[i];
       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
       db.setDatabaseName(Rpath);
       if (!db.open()) {
           qDebug("Error occurred opening the database.");
           qDebug("%s.", qPrintable(db.lastError().text()));
           return;
        }
        QSqlQuery query(db);
        query.prepare("select rowid,* from word where Translation='"+arr+"'");
        //query->exec();
        QString blabla,sentence_name,translation,pictures,pictures_path,comment;;
        if(query.exec()){
            while(query.next()){
               row_first = query.value(0).toString();
               blabla = query.value(1).toString();
               translation = query.value(2).toString();
               sentence_name = query.value(3).toString();
               pictures    = query.value(4).toString();
               comment = query.value(5).toString();
               pictures_path = query.value(6).toString();
            }
        }

        int row_for_hidd = row.toInt();
        qDebug() <<"row_for_hidd fir" <<row_for_hidd;
        int row_first_for_hidd = row_first.toInt();
        qDebug() <<"row_first_for_hidd first" <<row_first_for_hidd;
        if(row_first_for_hidd == row_for_hidd){
            qDebug() << "Xi ches jnjum vor ay urod 2" ;
            ui->listsecond->setRowHidden(aaa,true);
            ui->listfirst->setRowHidden(bbb,true);
            deleted_match_words++;
            QDir qdWDir;
            QString sWDir = qdWDir.absolutePath();
            sWDir.append("/");
            QDir::setCurrent(sWDir);

            QString voice;

            voice = blabla;
            voice.push_front('"');
             voice.push_back('"');
             //qDebug() << "search dic"<< voice;
             if (play_words) {
                 //qDebug() << play_words;
                 if (speacker_on_mach) {
                    newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                 }
             }
        } else {
            //last1.append(blabla);
            //mistake_2.append("a");
            mistake_2.append(translation);
            qDebug() << "Xi ches jnjum vor ay urod 2" <<mistake_2;

        }
        qDebug() << "size_of_db" <<size_of_db;
        if (size_of_db  == deleted_match_words){
            switch( QMessageBox::question(
                            this,
                            tr("Learn Words"),
                            tr("You have finished do you want to retry?"),
                            QMessageBox::Yes |
                            QMessageBox::No
                             ) )
                {
                  case QMessageBox::Yes:
                        size_of_the_job = mess_size;
                         deleted_match_words=0;
                          qDebug() << "size_of_the_job1" <<size_of_the_job;
                          qDebug() << "deleted_match_words1" <<deleted_match_words;
                            ui->tabWidget->setCurrentIndex(1);
                         on_tabWidget_tabBarClicked(1);
                    break;
                  case QMessageBox::No:
                        size_of_the_job = mess_size;
                        deleted_match_words=0;
                        ui->tabWidget->setCurrentIndex(2);
                        on_tabWidget_tabBarClicked(2);
                    break;

                  default:

                    break;
                }
        }
        else if (deleted_match_words == size_of_the_job) {
            switch( QMessageBox::question(
                            this,
                            tr("Learn Words"),
                            tr("We are going to the next words"),
                            QMessageBox::Yes |
                            QMessageBox::No
                             ) )
                {
                  case QMessageBox::Yes:
                        size_of_the_job += mess_size;
                        qDebug() << "size_of_the_job0" <<size_of_the_job;
                          qDebug() << "deleted_match_words0" <<deleted_match_words;
                        on_tabWidget_tabBarClicked(1);
                    break;
                  case QMessageBox::No:
                    //qDebug( "no" );
                    //if (a == size_of_the_job) {
               // a = -1;
                 size_of_the_job = mess_size;
                 deleted_match_words=0;
                 on_tabWidget_tabBarClicked(1);
                 //ui->seetranslation_3->clicked(true);
                 //ui->nextword_3->clicked(true);
                 //a = -1;

                    //}
                    break;

                  default:
                   // qDebug( "close" );
                    break;
                }
        }
}

void MainWindow::on_listsecond_activated(const QModelIndex &index)
{


}


void MainWindow::on_listsecond_clicked(const QModelIndex &index)
{
    QModelIndexList list =ui->listsecond->selectionModel()->selectedIndexes();
   // ui->widget->setStyleSheet("QWidget {border: 1px solid #ff3939;};");
    aaa = index.row();
    //bbb = index.row();
    qDebug() << aaa;
    qDebug() << bbb;
    QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }
       QString arr;
       for (int i = 0; i<slist.size();i++)
           arr = slist[i];
       //qDebug() <<arr;

       QDir qdWDir;
       QString sWDir = qdWDir.absolutePath();
       sWDir.append("/");
       QDir::setCurrent(sWDir);

       QString voice;

       voice = arr;
       voice.push_front('"');
        voice.push_back('"');
        //qDebug() << "search dic"<< voice;
        if (play_words) {
            //qDebug() << play_words;
            if (speacker_on_mach) {
                newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
            }
        }

       listsize = slist.size();
       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection33");
       db.setDatabaseName(Rpath);
       if (!db.open()) {
           qDebug("Error occurred opening the database.");
           qDebug("%s.", qPrintable(db.lastError().text()));
           return;
        }
        QSqlQuery query(db);
        query.prepare("select rowid,* from word where Word='"+arr+"'");
        QString word_name,translation,sentence_name,pictures,pictures_path,comment;
        if(query.exec()){
            while(query.next()){
                row = query.value(0).toString();
                word_name = query.value(1).toString();
                translation = query.value(2).toString();
                sentence_name = query.value(3).toString();
                pictures    = query.value(4).toString();
                comment = query.value(5).toString();
                pictures_path = query.value(6).toString();
                ui->label_3->setText(word_name);
                ui->label_6->setText(sentence_name);
            }
        }

        int row_for_hidd = row.toInt();
        qDebug() << "row_for_hidd"<<row_for_hidd;
        int row_first_for_hidd = row_first.toInt();
        qDebug() <<"row_first_for_hidd"<<row_first_for_hidd;
        if(row_first_for_hidd == row_for_hidd){
            //qDebug() << "Xi ches jnjum vor ay urod 1" ;
            ui->listsecond->setRowHidden(aaa,true);
            ui->listfirst->setRowHidden(bbb,true);
            deleted_match_words++;
        } else {
           // last.append("a");
            mistake_1.append(word_name);
            mistake_1_1.append(translation);
            sentence_a.append(sentence_name);
            picpath.append(pictures_path);
            comment_a.append(comment);
            pictur.append(pictures);
            qDebug() << "Xi ches jnjum vor ay urod 1" <<mistake_1;
            qDebug()<<name_of_the_new_table;



            //mistakes.append()
            //ui->widget->setStyleSheet("QWidget {border: 1px solid #ff3939;};");
          //  ui->listsecond->setStyleSheet("QListView::item:selected:active  {background: #ff3939; color: #FFFFFF;};");
           // ui->listfirst->setStyleSheet("QListView::item:selected  {background: #ff3939; color: #FFFFFF;};");
        }
        if (size_of_db  == deleted_match_words){
            switch( QMessageBox::question(
                            this,
                            tr("Learn Words"),
                            tr("You have finished do you want to retry?"),
                            QMessageBox::Yes |
                            QMessageBox::No
                             ) )
                {
                  case QMessageBox::Yes:
                        size_of_the_job = mess_size;
                        deleted_match_words=0;
                          qDebug() << "size_of_the_job1" <<size_of_the_job;
                          qDebug() << "deleted_match_words1" <<deleted_match_words;
                           ui->tabWidget->setCurrentIndex(1);
                         on_tabWidget_tabBarClicked(1);
                    break;
                  case QMessageBox::No:
                        size_of_the_job = mess_size;
                        deleted_match_words=0;
                        ui->tabWidget->setCurrentIndex(2);
                        on_tabWidget_tabBarClicked(2);
                    break;

                  default:

                    break;
                }
        }
        else if (deleted_match_words == size_of_the_job) {
            switch( QMessageBox::question(
                            this,
                            tr("Learn Words"),
                            tr("We are going to the next words"),
                            QMessageBox::Yes |
                            QMessageBox::No
                             ) )
                {
                  case QMessageBox::Yes:
                        size_of_the_job += mess_size;
                          qDebug() << "size_of_the_job1" <<size_of_the_job;
                            qDebug() << "deleted_match_words1" <<deleted_match_words;

                         on_tabWidget_tabBarClicked(1);
                    break;
                  case QMessageBox::No:
                        size_of_the_job = mess_size;
                        deleted_match_words=0;
                        ui->tabWidget->setCurrentIndex(1);
                         on_tabWidget_tabBarClicked(1);
                    break;

                  default:

                    break;
                }
        }

}




void MainWindow::on_learn_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_3->setText("");
    ui->label_6->setText("");

    qDebug() << listsize;
    ui->listsecond->clear();
    ui->listfirst->clear();
    a = -1;
    for_2_tab=-1;
    speacker_on_rand = false;
    size_of_the_job = mess_size;
    name_of_the_new_table.clear();
}

void MainWindow::on_totext_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection89");
    db.setDatabaseName(Rpath);
    if (!db.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db.lastError().text()));
        return;
     }
    QVector<QStringList> lst;
     QSqlQuery* query = new QSqlQuery(db);
     query->exec("SELECT * FROM word");
     while (query->next()) {
         QSqlRecord record = query->record();
         QStringList tmp;
            for(int i=0; i < record.count(); i++)
             {
                 tmp << record.value(i).toString();
             }
             lst.append(tmp);
         }
   //
     //qDebug() << lst;
     QVector<QString> sorted_items;
     for (int i=0;i<lst.size();i++){
            //sorted_items.append(lst[i][0]);
        // qDebug() << lst[i][0];
     }

     QString fileName;
      fileName = QFileDialog::getSaveFileName(this, tr("Save as"), QString(),
                                                     tr("Database Files into txt (*.txt)"));
         QFile file(fileName);
         if (!file.open(QIODevice::WriteOnly))
         {
             qDebug() << "Imposible to create database!";
         }
         /* Point a QTextStream object at the file */
         QTextStream out(&file);
        qDebug() << lst.size();
         /* Write the line to the file */
         for (int i = 0; i < lst.size(); ++i) {
             for (int j = 0; j < 2; ++j) {
                 QString str = lst[i][j];
                     out << str << "\t" << "[]" << "\t";
             }
             out << endl;
         }
         file.close();
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QModelIndexList list =ui->tableView->selectionModel()->selectedIndexes();
    //ui->label_center->setStyleSheet("QLabel { color : #DCDCDC; }");
    aaa = index.row();
    int Column_ind;
    Column_ind = index.column();
    Column_ind_1 = index.column();
    //qDebug() << "row " <<aaa;
    qDebug() << "column"<<Column_ind;


//ui->tableView->moveCursor()


    QDir qdWDir;
    QString sWDir = qdWDir.absolutePath();
    sWDir.append("/");
    QDir::setCurrent(sWDir);

    QString voice;


    QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }
       QString arr;


       for (int i = 0; i<slist.size();i++)
           arr = slist[i];

       qDebug() << "arr dic"<< arr;





       voice = arr;

       voice.push_front('"');
        voice.push_back('"');
        qDebug() << "search dic"<< voice;
        if (play_words && Column_ind != 3) {
            qDebug() << play_words;
            newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");

        }

      // qDebug() <<"arr"<<arr;
       listsize = slist.size();
      //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection34");
       db1.setDatabaseName(Rpath);
       if (!db1.open()) {
           qDebug("Error occurred opening the database.");
           qDebug("%s.", qPrintable(db1.lastError().text()));
           return;
        }
       //qDebug() <<"arrasdfasdf1";
        QSqlQuery query(db1);

        query.prepare("select rowid,* from word where Word='"+arr+"' or Sentence='"+arr+"' or Pictures='"+arr+"' or Translation='"+arr+"' or Comment='"+arr+"'");
        //qDebug() <<"arrasdfasdf";
        ui->tabWidget_2->setCurrentIndex(0);
        //delete newProcess;

        //newProcess->start("espeak.exe -v female5 -s 120 -a 50 "+voice+"");


        if (arr != "") {
        //QString search_dic;
        if(query.exec()){
           // qDebug() <<"arrasdfasdf4";
            while(query.next()){
                //qDebug() <<"arrasdfasdf3";

                 search_dic = query.value(1).toString();
                 transl_for_pic = query.value(2).toString();
                 sent_for_pict = query.value(3).toString();

                 //qDebug() << "search dic"<< search_dic;
                 pic_path = query.value(7).toString();


                ui->webView->load(QUrl("http://www.thefreedictionary.com/"+search_dic+""));
                if (lisens){
                   // ui->macmillan_web->load(QUrl("http://www.macmillandictionary.com/spellcheck/british/?q="+search_dic+""));
                    //ui->webView1->load(QUrl("http://www.lingvo-online.ru/en/Translate/en-ru/"+search_dic+""));
              //      ui->webView2->load(QUrl("http://www.wordwebonline.com/search.pl?w="+search_dic+""));
                    ui->webView3->load(QUrl("http://learnersdictionary.com/definition/"+search_dic+""));
                }
            }
        }
    }

        if (Column_ind == 3) {
            if(arr != "" && pic_path != "") {
                message *pic = new message;
                pic->show();
            }
        }


  // ui->pic_label->setPixmap(QPixmap(pic_path, 0, Qt::AutoColor));
}

void MainWindow::on_actionAbout_triggered()
{
    front *aa = new front();
    aa->show();

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{

    QModelIndexList list =ui->tableView->selectionModel()->selectedIndexes();
    aaa = index.row();
    int Column_ind;
    Column_ind = index.column();
   // qDebug() << "row " <<aaa;
   // qDebug() << "column"<<Column_ind;
    db1.setDatabaseName(Rpath);
    if (!db1.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db1.lastError().text()));
        return;
     }
    if (Column_ind == 3) {
        QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }
       QString arr;

       for (int i = 0; i<slist.size();i++)
           arr = slist[i];
       listsize = slist.size();

        QSqlQuery query(db1);

        query.prepare("select rowid,* from word where Word='"+arr+"' or Sentence='"+arr+"' or Pictures='"+arr+"' or Translation='"+arr+"' or Comment ='"+arr+"'");
        ui->tabWidget_2->setCurrentIndex(1);
        if (arr != "") {
            QString search_dicd;
            if(query.exec()){
                while(query.next()){
                     search_dicd = query.value(1).toString();
                     pic_path = query.value(3).toString();

                         QString fileName;
                         fileName = QFileDialog::getOpenFileName(this, tr("Open File..."),QString(), tr("Pictures (*.png *.jpg *.jpeg);;All Files (*)"));
                         pic_path = fileName;

                         QString SubStringList;
                        if (pic_path.size() != 0){
                         QRegExp rxlen("([^/]+)\.([^/]+$)");
                          int pos = rxlen.indexIn(pic_path);
                          QString list;
                          if (pos > -1) {
                              list = rxlen.cap(2);
                          }
                            int i =0;

                          while(list[i] != '.') {
                              SubStringList.push_back(list[i]);
                              i++;

                          }
                        }

                          //pic_path.remove('/');
                         // qDebug() << "new path3" << SubStringList;
                         if (!fileName.isEmpty())
                         {

                             db1.setDatabaseName(Rpath);
                             if (!db1.open()) {
                                 qDebug("Error occurred opening the database.");
                                 qDebug("%s.", qPrintable(db1.lastError().text()));
                                 return;
                              }
                              QSqlQuery query1(db1);
                              qDebug()<<search;
                              query1.exec("UPDATE word SET Pictures='"+SubStringList+"' WHERE Word = '"+search_dicd+"'");
                              query1.exec("UPDATE word SET picpath='"+pic_path+"' WHERE Word = '"+search_dicd+"'");
                         }

                }
            }
        }
        QSqlTableModel *model = new QSqlTableModel(0, db1);
        model->setTable("word");
        ui->tableView->setModel(model);
        //ui->tableView->setSortingEnabled(true);
        model->select();
    }
}


void MainWindow::on_openfile_clicked()
{
    QString fileName,file_path;

    //int count = ui->listView->model()-
     fileName = QFileDialog::getOpenFileName(this, tr("Open File..."),QString(), tr("Database Files (*.sqlite *.sqlite3 *.db);"));
     file_path = fileName;

     //qDebug() << "araaaaaaaaaaaa1="<< file_path;

     QRegExp rxlen("([^/]+)\.([^/]+$)");
      int pos = rxlen.indexIn(file_path);
      QString list;
      if (pos > -1) {
          list = rxlen.cap(2);
      }

       QStringList SubStringList = list.split(".sqlite");




    if (!fileName.isEmpty())
    {
        QSqlDatabase db3 = QSqlDatabase::addDatabase("QSQLITE", "connection34");
        db3.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");
        if (!db3.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db3.lastError().text()));
            return;
         }
         QSqlQuery query(db3);

        query.prepare("INSERT INTO word(Word,Sentence,Pictures,Comment) values(:Word,:Sentence,:Pictures,:Comment)");
//qDebug() << "araaaaaaaaaaaa="<<SubStringList[0];
        //query.bindValue(":rowid",row_count_id);
        query.bindValue(":Word",file_path);
        query.bindValue(":Sentence",SubStringList[0]);
        query.bindValue(":Pictures","");
        query.bindValue(":Comment","");
        query.exec();
      }
        QSqlDatabase db4 = QSqlDatabase::addDatabase("QSQLITE", "connection34");
        db4.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");
        if (!db4.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db4.lastError().text()));
            return;
         }

        QSqlQueryModel * modal1 = new QSqlQueryModel();
         QSqlQuery* query1 = new QSqlQuery(db4);
         query1->prepare("select Sentence from word");
         query1->exec();
         modal1->setQuery(*query1);
         ui->listView->setModel(modal1);
}

QString file_for_delet;
void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();
    aaa = index.row();
    qDebug() << aaa;

    QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }
       for (int i = 0; i<slist.size();i++)
           file_for_delet = slist[i];
 qDebug() << file_for_delet;


}

void MainWindow::on_delete_2_clicked()
{
    QSqlDatabase db3 = QSqlDatabase::addDatabase("QSQLITE", "connection34");
    db3.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");
    if (!db3.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db3.lastError().text()));
        return;
     }
     QSqlQuery query(db3);
    qDebug() << file_for_delet;
    query.prepare("DELETE FROM word WHERE Sentence = '"+file_for_delet+"'");

    query.exec();
    QSqlDatabase db6 = QSqlDatabase::addDatabase("QSQLITE", "connection34");
    db6.setDatabaseName(QDir::currentPath() + "/sqldrivers/listitems.sqlite");
    if (!db6.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db6.lastError().text()));
        return;
     }

    QSqlQueryModel * modal1 = new QSqlQueryModel();
     QSqlQuery* query1 = new QSqlQuery(db6);
     query1->prepare("select Sentence from word");
     query1->exec();
     modal1->setQuery(*query1);
     ui->listView->setModel(modal1);

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    time = value;
    qDebug() << time;
}



void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (yas_by_dif == true) {
    //    a=-1;
       if (index  == 0) {



           ui->seetranslation_3->setVisible(true);
           ui->nextword_3->setVisible(false);
           a++;
                   QString b = QString::number(a);
                   QVector<QStringList> lst;
                   if (a == size_of_the_job) {
                       switch( QMessageBox::question(
                                       this,
                                       tr("Learn Words"),
                                       tr("We are going to the next words"),
                                       QMessageBox::Yes |
                                       QMessageBox::No
                                        ) )
                           {
                             case QMessageBox::Yes:
                                   a= size_of_the_job;
                                   size_of_the_job += mess_size;
                               break;
                             case QMessageBox::No:
                                a = -1;
                                size_of_the_job = mess_size;
                                ui->seetranslation_3->clicked(true);
                                ui->nextword_3->clicked(true);
                                a = -1;
                               break;
                             default:
                               break;
                           }

                   }
                   if (a != size_of_the_job && a != -1) {

                   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3-");
                   db.setDatabaseName(Rpath);
                   if (!db.open()) {
                       qDebug("Error occurred opening the database.");
                       qDebug("%s.", qPrintable(db.lastError().text()));
                       return;
                    }
                   QSqlQuery query(db);
                   query.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
                   if (query.next()) {
                          QString name = query.value(0).toString();
                          QString sentence = query.value(2).toString();
                          QString pic_path_goo = query.value(5).toString();
                          answare = query.value(1).toString();
                          QDir qdWDir;
                          QString sWDir = qdWDir.absolutePath();
                          sWDir.append("/");
                          QDir::setCurrent(sWDir);
                          QString voice;
                          voice = name;
                          voice.push_front('"');
                          voice.push_back('"');
                           if (play_table_word) {
                               if (speacker_on_memorize) {
                                   newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                               }
                           }
                          ui->label_11->setText(name);
                          ui->label_12->setText(sentence);
                          ui->nextword_3->setText(answare);
                          if (lisens){
                              ui->pic_learn->hide();
                              ui->GooglePhotos_3->show();
                               ui->GooglePhotos_3->load(QUrl("http://www.google.ru/search?newwindow=1&biw=1600&bih=785&tbm=isch&sa=1&q="+name+""));
                          }
                          if (lisens == false){
                              ui->GooglePhotos_3->hide();
                              ui->pic_learn->show();
                              QPixmap watermark(pic_path_goo);
                              QPixmap newPixmap = watermark.scaled(QSize(600,600),  Qt::KeepAspectRatio);
                              ui->pic_learn->setPixmap(newPixmap);

                          }
                   }
                   query.exec(" SELECT Translation FROM '"+new_name_of_table+"'");
                   while (query.next()) {
                       QSqlRecord record = query.record();
                       QStringList tmp;
                          for(int i=0; i < record.count(); i++)
                           {
                               tmp << record.value(i).toString();
                           }
                           lst.append(tmp);
                       }
                   }
                   int ls =  lst.size();
                   if (ls == a) {
                       switch( QMessageBox::question(
                                       this,
                                       tr("Learn Words"),
                                       tr("You have finished the lesson. Do you want to retry?"),

                                       QMessageBox::Yes |
                                       QMessageBox::No
                                        ) )
                           {
                             case QMessageBox::Yes:
                               qDebug( "yes" );
                                   a = -1;
                                    size_of_the_job = mess_size;
                                    ui->seetranslation_3->clicked(true);
                                    ui->nextword_3->clicked(true);

                               break;
                             case QMessageBox::No:
                               //qDebug( "no" );
                                   a = lst.size();
                                    size_of_the_job = mess_size;
                                    ui->tabWidget->setCurrentIndex(1);
                                   on_tabWidget_tabBarClicked(1);
                               //}
                               break;

                             default:
                           size_of_the_job = mess_size;
                               //qDebug( "close" );
                               break;
                           }
                   }
        //}
       }
       if (index == 2) {
           if (random_changes) {
               a = -1;
               ui->algo_2_list->clear();
               ui->label_3->setText("");
               ui->label_6->setText("");
               ui->mainVord->setText("English word");
               ui->algo_2_list->clear();
               QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
               db.setDatabaseName(Rpath);
               if (!db.open()) {
                   qDebug("Error occurred opening the database.");
                   qDebug("%s.", qPrintable(db.lastError().text()));
                   return;
                }
               QSqlQuery query1(db);
               int counter = 0;
                   query1.exec("SELECT * FROM '"+new_name_of_table+"'");
                   while(query1.next())
                       counter++;
                   int num = qrand() % counter;
                   QString b = QString::number(num);
                   QSqlQuery query2(db);
               QString second_name;
               QString sentence_name;
               QString name;
                   query2.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
                   if (query2.next()) {
                        name = query2.value(0).toString();
                       if (change_lang) {

                          QDir qdWDir;
                          QString sWDir = qdWDir.absolutePath();
                          sWDir.append("/");
                          QDir::setCurrent(sWDir);

                          QString voice;

                          voice = name;
                          voice.push_front('"');
                           voice.push_back('"');
                           qDebug() << "search dic"<< voice;
                           if (play_table_word) {
                               if (speacker_on_rand) {
                                   newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                               }
                           }
                       }
                          second_name = query2.value(1).toString();
                          sentence_name = query2.value(2).toString();
                          if (change_lang) {
                               ui->mainVord->setText(name);
                          } else {
                              ui->mainVord->setText(second_name);
                          }
                          ui->SimpleSintence->setText(sentence_name);
                   }

               QVector<QStringList> lst;
                QSqlQuery query(db);
                if (change_lang) {
                   query.exec("SELECT Translation FROM '"+new_name_of_table+"'");
                } else {
                   query.exec("SELECT Word FROM '"+new_name_of_table+"'");
                }
                while (query.next()) {
                    QSqlRecord record = query.record();
                    QStringList tmp;
                       for(int i=0; i < record.count(); i++)
                        {
                            tmp << record.value(i).toString();
                        }
                        lst.append(tmp);
                    }

                if (lst.size() < size_of_the_job) {
                    size_of_the_job = lst.size();
                }

                QStringList sorted_items;
                if (change_lang) {
                   sorted_items.append(second_name);
                } else {
                   sorted_items.append(name);
                }
               int for_rand = 0;
               if (lst.size() < 7) {
                   for_rand = lst.size()/2;
               } else {
                   for_rand = 7;
               }


                for (int i=0;i<for_rand;i++){
                    int arr_i = (qrand() %lst.size());
                    if (change_lang) {
                        if(second_name != lst[i][0]) {
                             sorted_items.append(lst[arr_i][0]);
                        }
                    } else {
                        if(name != lst[i][0]) {
                             sorted_items.append(lst[arr_i][0]);
                        }
                    }
                }

                QStringList temp = count_same_words_ret(sorted_items);

                qDebug() <<temp;

                qSort(temp.begin(),temp.end());
                for (int i=0;i<temp.size();i++){
                    QListWidgetItem* lwi = new QListWidgetItem(temp[i]);
                    lwi->setSizeHint(QSize(250, 40));
                    ui->algo_2_list->addItem( lwi );
                    lwi->setTextAlignment(Qt::AlignCenter);
                }
                listsize = sorted_items.size();
           } else {
               if (size_of_the_job == 0) {
                   size_of_the_job = mess_size;
               }
               a = -1;
               qDebug() <<a;
               qDebug() <<for_2_tab;
              // for_2_tab =-1;
               ui->algo_2_list->clear();
               ui->label_3->setText("");
               ui->label_6->setText("");
               //ui->mainVord->setText("English word");
               ui->algo_2_list->clear();
               QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
               db.setDatabaseName(Rpath);
               if (!db.open()) {
                   qDebug("Error occurred opening the database.");
                   qDebug("%s.", qPrintable(db.lastError().text()));
                   return;
                }
               qDebug() << "size_of_the_job" << size_of_the_job;
                   for_2_tab++;
                   if (for_2_tab == size_of_db ) {
                                   switch( QMessageBox::question(
                                                   this,
                                                   tr("Learn Words"),
                                                   tr("You have finished the lesson. Do you want to retry?"),

                                                   QMessageBox::Yes |
                                                   QMessageBox::No
                                                    ) )
                                       {
                                         case QMessageBox::Yes:
                                           qDebug( "yes" );
                                               for_2_tab = -1;
                                               size_of_the_job = mess_size;
                                               on_tabWidget_tabBarClicked(2);
                                               //qDebug() << "size_of_the_job_ yes" << size_of_the_job;

                                                //size_of_the_job = mess_size;
                                                //ui->seetranslation_3->clicked(true);
                                                //ui->nextword_3->clicked(true);

                                           break;
                                         case QMessageBox::No:
                                                    for_2_tab = -1;
                                                   the_lesson_is_finished = true;

                                                   //ui->toolBar->show();
                                                   a_4 = -1;
                                                   ui->tabWidget->setCurrentIndex(3);
                                                   on_tabWidget_tabBarClicked(3);
                                           break;
                                          default:
                                   break;

                           }

                   }else if (for_2_tab== size_of_the_job) {
                       switch( QMessageBox::question(
                                       this,
                                       tr("Learn Words"),
                                       tr("We are going to the next words"),
                                       QMessageBox::Yes |
                                       QMessageBox::No
                                        ) )
                           {
                             case QMessageBox::Yes:
                                   for_2_tab= size_of_the_job;
                                   size_of_the_job += mess_size;
                               break;
                             case QMessageBox::No:
                                for_2_tab = -1;
                                size_of_the_job = mess_size;
                               break;
                             default:
                               break;
                           }

                   }

                   QString b = QString::number(for_2_tab);
                  // qDebug() << b;
                   //QString s = QString::number(st);
                   QSqlQuery query2(db);
               QString second_name;
               QString sentence_name;
               QString name;
                   query2.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
                   if (query2.next()) {
                        name = query2.value(0).toString();
                       if (change_lang) {

                          QDir qdWDir;
                          QString sWDir = qdWDir.absolutePath();
                          sWDir.append("/");
                          QDir::setCurrent(sWDir);

                          QString voice;

                          voice = name;
                          voice.push_front('"');
                           voice.push_back('"');
                           qDebug() << "search dic"<< voice;
                           if (play_table_word) {
                               //qDebug() << play_words;
                               if (speacker_on_rand) {
                                   newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                               }
                           }
                       }
                         // qDebug() << name;
                          second_name = query2.value(1).toString();
                          sentence_name = query2.value(2).toString();
                          if (change_lang) {
                               ui->mainVord->setText(name);
                          } else {
                              ui->mainVord->setText(second_name);
                          }
                          ui->SimpleSintence->setText(sentence_name);
                   }

               QVector<QStringList> lst;
                QSqlQuery query(db);
                if (change_lang) {
                   query.exec("SELECT Translation FROM '"+new_name_of_table+"'");
                } else {
                   query.exec("SELECT Word FROM '"+new_name_of_table+"'");
                }
                while (query.next()) {
                    QSqlRecord record = query.record();
                    QStringList tmp;
                       for(int i=0; i < record.count(); i++)
                        {
                            tmp << record.value(i).toString();
                        }
                        lst.append(tmp);
                    }
              //
                if (lst.size() < size_of_the_job) {
                    size_of_the_job = lst.size();
                }
                size_of_db = lst.size();

                QStringList sorted_items;
                if (change_lang) {
                   sorted_items.append(second_name);
                } else {
                   sorted_items.append(name);
                }

                int for_rand = 0;
                if (lst.size() < 7) {
                    for_rand = lst.size()/2;
                } else {
                    for_rand = 7;
                }

                for (int i=0;i<for_rand;i++){
                    int arr_i_b = qrand() % lst.size();
                    if (change_lang) {
                        if(second_name != lst[arr_i_b][0]) {
                             sorted_items.append(lst[arr_i_b][0]);
                        }
                    } else {
                        if(name != lst[i][0]) {
                             sorted_items.append(lst[arr_i_b][0]);
                        }
                    }
                }
                QStringList temp = count_same_words_ret(sorted_items);

                qSort(temp.begin(),temp.end());
                for (int i=0;i<temp.size();i++){
                    QListWidgetItem* lwi = new QListWidgetItem(temp[i]);
                    lwi->setSizeHint(QSize(250, 40));
                    ui->algo_2_list->addItem( lwi );
                    lwi->setTextAlignment(Qt::AlignCenter);
                }
                listsize = sorted_items.size();
           }
       }
       if(index == 1) {
           a = -1;
           ui->listfirst->clear();
           ui->listsecond->clear();
          // size_of_the_job = mess_size;
           QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
           db.setDatabaseName(Rpath);
           if (!db.open()) {
               qDebug("Error occurred opening the database.");
               qDebug("%s.", qPrintable(db.lastError().text()));
               return;
            }
           QVector<QStringList> lst,bst;
            QSqlQuery* query = new QSqlQuery(db);
            query->exec("SELECT Word FROM '"+new_name_of_table+"'");
            while (query->next()) {
                QSqlRecord record = query->record();
                QStringList tmp;
                   for(int i=0; i < record.count(); i++)
                    {
                        tmp << record.value(i).toString();
                    }
                    lst.append(tmp);
                }
            if (lst.size() < size_of_the_job) {
                size_of_the_job = lst.size();
            }
            size_of_db = lst.size();
            QVector<QString> sorted_items,listsecond;
            for (int i=deleted_match_words;i<size_of_the_job;i++){
                   sorted_items.append(lst[i][0]);
            }
            QSqlQuery* query1 = new QSqlQuery(db);
            query1->exec("SELECT Translation FROM '"+new_name_of_table+"'");
            while (query1->next()) {
                QSqlRecord record = query1->record();
                QStringList tmp;
                   for(int i=0; i < record.count(); i++)
                    {
                        tmp << record.value(i).toString();
                    }
                    bst.append(tmp);
            }

            for (int i=deleted_match_words;i<size_of_the_job;i++){
               listsecond.append((bst[i][0]));
            }
            qSort(sorted_items.begin(),sorted_items.end());
            if (!change_maches) {
                for (int i=0;i<sorted_items.size();i++){
                    QListWidgetItem* lwi = new QListWidgetItem(sorted_items[i]);
                    lwi->setSizeHint(QSize(250, 40));
                    ui->listsecond->addItem( lwi );
                    lwi->setTextAlignment(Qt::AlignCenter);
                }

                listsize = sorted_items.size();

                for (int i=0;i<listsecond.size();i++){
                    QListWidgetItem* lwi = new QListWidgetItem(listsecond[i]);
                    lwi->setSizeHint(QSize(250, 40));
                    ui->listfirst->addItem( lwi );
                    lwi->setTextAlignment(Qt::AlignCenter);
                }
            } else {
                for (int i=0;i<sorted_items.size();i++){
                    QListWidgetItem* lwi = new QListWidgetItem(sorted_items[i]);
                    lwi->setSizeHint(QSize(250, 40));
                    ui->listfirst->addItem( lwi );
                    lwi->setTextAlignment(Qt::AlignCenter);
                }
                listsize = sorted_items.size();
                for (int i=0;i<listsecond.size();i++){
                    QListWidgetItem* lwi = new QListWidgetItem(listsecond[i]);
                    lwi->setSizeHint(QSize(250, 40));
                    ui->listsecond->addItem( lwi );
                    lwi->setTextAlignment(Qt::AlignCenter);
                }
            }

       }

       if (index  == 3) {
          // m_gl->
           tab_3(l);
           ui->toolBox->setCurrentIndex(1);

       }
   }
    if (yas_by_dif == false) {


    if (index  == 0) {

        ui->seetranslation_3->setVisible(true);
        ui->nextword_3->setVisible(false);
        a++;
        QString b = QString::number(a);
        QVector<QStringList> lst;
        if (a == size_of_the_job) {
            switch( QMessageBox::question(
                            this,
                            tr("Learn Words"),
                            tr("We are going to the next words"),
                            QMessageBox::Yes |
                            QMessageBox::No
                             ) )
                {
                  case QMessageBox::Yes:
                        a= size_of_the_job;
                        size_of_the_job += mess_size;
                    break;
                  case QMessageBox::No:
                     a = -1;
                     size_of_the_job = mess_size;
                     ui->seetranslation_3->clicked(true);
                     ui->nextword_3->clicked(true);
                     a = -1;
                    break;
                  default:
                    break;
                }

        }
        if (a != size_of_the_job && a != -1) {

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3-");
        db.setDatabaseName(Rpath);
        if (!db.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db.lastError().text()));
            return;
         }

        QSqlQuery query(db);
        query.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
        if (query.next()) {
               QString name = query.value(0).toString();
               QString sentence = query.value(2).toString();
               QString pic_path_goo = query.value(6).toString();
               answare = query.value(1).toString();
               QString is_learned = query.value(5).toString();
               QDir qdWDir;
               QString sWDir = qdWDir.absolutePath();
               sWDir.append("/");
               QDir::setCurrent(sWDir);
               QString voice;
               voice = name;
               voice.push_front('"');
               voice.push_back('"');
              // if (is_learned != "0"){
                   if (play_table_word) {
                        if (speacker_on_memorize) {
                            newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                        }
                   }
                   ui->label_11->setText(name);
                   ui->label_12->setText(sentence);
                   ui->nextword_3->setText(answare);
                   if (lisens){
                       ui->pic_learn->hide();
                       ui->GooglePhotos_3->show();
                        ui->GooglePhotos_3->load(QUrl("http://www.google.ru/search?newwindow=1&biw=1600&bih=785&tbm=isch&sa=1&q="+name+""));
                   }
                   if (lisens == false){
                       ui->GooglePhotos_3->hide();
                       ui->pic_learn->show();
                       QPixmap watermark(pic_path_goo);
                       QPixmap newPixmap = watermark.scaled(QSize(600,600),  Qt::KeepAspectRatio);
                       ui->pic_learn->setPixmap(newPixmap);

                   }
               //} else {
                 //  ui->seetranslation_3->clicked(true);
                   //ui->nextword_3->clicked(true);
                   //on_tabWidget_tabBarClicked(0);
              // }
        }
        query.exec(" SELECT Translation FROM '"+new_name_of_table+"'");
        while (query.next()) {
            QSqlRecord record = query.record();
            QStringList tmp;
               for(int i=0; i < record.count(); i++)
                {
                    tmp << record.value(i).toString();
                }
                lst.append(tmp);
            }
        }
       int ls =  lst.size();
        if (ls == a) {
            switch( QMessageBox::question(
                            this,
                            tr("Learn Words"),
                            tr("You have finished the lesson. Do you want to retry?"),

                            QMessageBox::Yes |
                            QMessageBox::No
                             ) )
                {
                  case QMessageBox::Yes:
                    qDebug( "yes" );
                        a = -1;
                         size_of_the_job = mess_size;
                         ui->seetranslation_3->clicked(true);
                         ui->nextword_3->clicked(true);

                    break;
                  case QMessageBox::No:
                    //qDebug( "no" );
                        a = lst.size();
                         size_of_the_job = mess_size;
                         ui->tabWidget->setCurrentIndex(1);
                        on_tabWidget_tabBarClicked(1);
                    //}
                    break;

                  default:
                size_of_the_job = mess_size;
                    //qDebug( "close" );
                    break;
                }
        }

    }
    if (index == 2) {
        if (random_changes) {
            a = -1;
            ui->algo_2_list->clear();
            ui->label_3->setText("");
            ui->label_6->setText("");
            ui->mainVord->setText("English word");
            ui->algo_2_list->clear();
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
            db.setDatabaseName(Rpath);
            if (!db.open()) {
                qDebug("Error occurred opening the database.");
                qDebug("%s.", qPrintable(db.lastError().text()));
                return;
             }
            QSqlQuery query1(db);
            int counter = 0;
                query1.exec("SELECT * FROM '"+new_name_of_table+"'");
                while(query1.next())
                    counter++;
                int num = qrand() % counter;
                QString b = QString::number(num);
                QSqlQuery query2(db);
            QString second_name;
            QString sentence_name;
            QString name;
                query2.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
                if (query2.next()) {
                     name = query2.value(0).toString();
                    if (change_lang) {

                       QDir qdWDir;
                       QString sWDir = qdWDir.absolutePath();
                       sWDir.append("/");
                       QDir::setCurrent(sWDir);

                       QString voice;

                       voice = name;
                       voice.push_front('"');
                        voice.push_back('"');
                        qDebug() << "search dic"<< voice;
                        if (play_table_word) {
                            if (speacker_on_rand) {
                                newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                            }
                        }
                    }
                       second_name = query2.value(1).toString();
                       sentence_name = query2.value(2).toString();
                       if (change_lang) {
                            ui->mainVord->setText(name);
                       } else {
                           ui->mainVord->setText(second_name);
                       }
                       ui->SimpleSintence->setText(sentence_name);
                }

            QVector<QStringList> lst;
             QSqlQuery query(db);
             if (change_lang) {
                query.exec("SELECT Translation FROM '"+new_name_of_table+"'");
             } else {
                query.exec("SELECT Word FROM '"+new_name_of_table+"'");
             }
             while (query.next()) {
                 QSqlRecord record = query.record();
                 QStringList tmp;
                    for(int i=0; i < record.count(); i++)
                     {
                         tmp << record.value(i).toString();
                     }
                     lst.append(tmp);
                 }

             if (lst.size() < size_of_the_job) {
                 size_of_the_job = lst.size();
             }

             QStringList sorted_items;
             if (change_lang) {
                sorted_items.append(second_name);
             } else {
                sorted_items.append(name);
             }
            int for_rand = 0;
            if (lst.size() < 7) {
                for_rand = lst.size()/2;
            } else {
                for_rand = 7;
            }


             for (int i=0;i<for_rand;i++){
                 int arr_i = (qrand() %lst.size());
                 if (change_lang) {
                     if(second_name != lst[i][0]) {
                          sorted_items.append(lst[arr_i][0]);
                     }
                 } else {
                     if(name != lst[i][0]) {
                          sorted_items.append(lst[arr_i][0]);
                     }
                 }
             }

             QStringList temp = count_same_words_ret(sorted_items);

             qDebug() <<temp;

             qSort(temp.begin(),temp.end());
             for (int i=0;i<temp.size();i++){
                 QListWidgetItem* lwi = new QListWidgetItem(temp[i]);
                 lwi->setSizeHint(QSize(250, 40));
                 ui->algo_2_list->addItem( lwi );
                 lwi->setTextAlignment(Qt::AlignCenter);
             }
             listsize = sorted_items.size();
        } else {
            if (size_of_the_job == 0) {
                size_of_the_job = mess_size;
            }
            a = -1;
            qDebug() <<a;
            qDebug() <<for_2_tab;
           // for_2_tab =-1;
            ui->algo_2_list->clear();
            ui->label_3->setText("");
            ui->label_6->setText("");
            //ui->mainVord->setText("English word");
            ui->algo_2_list->clear();
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
            db.setDatabaseName(Rpath);
            if (!db.open()) {
                qDebug("Error occurred opening the database.");
                qDebug("%s.", qPrintable(db.lastError().text()));
                return;
             }
            qDebug() << "size_of_the_job" << size_of_the_job;
                for_2_tab++;
                if (for_2_tab == size_of_db ) {
                                switch( QMessageBox::question(
                                                this,
                                                tr("Learn Words"),
                                                tr("You have finished the lesson. Do you want to retry?"),

                                                QMessageBox::Yes |
                                                QMessageBox::No
                                                 ) )
                                    {
                                      case QMessageBox::Yes:
                                        qDebug( "yes" );
                                            for_2_tab = -1;
                                            size_of_the_job = mess_size;
                                            on_tabWidget_tabBarClicked(2);
                                            //qDebug() << "size_of_the_job_ yes" << size_of_the_job;

                                             //size_of_the_job = mess_size;
                                             //ui->seetranslation_3->clicked(true);
                                             //ui->nextword_3->clicked(true);

                                        break;
                                      case QMessageBox::No:
                                                 for_2_tab = -1;
                                                the_lesson_is_finished = true;

                                                //ui->toolBar->show();
                                                a_4 = -1;
                                                ui->tabWidget->setCurrentIndex(3);
                                                on_tabWidget_tabBarClicked(3);
                                        break;
                                       default:
                                break;

                        }

                }else if (for_2_tab== size_of_the_job) {
                    switch( QMessageBox::question(
                                    this,
                                    tr("Learn Words"),
                                    tr("We are going to the next words"),
                                    QMessageBox::Yes |
                                    QMessageBox::No
                                     ) )
                        {
                          case QMessageBox::Yes:
                                for_2_tab= size_of_the_job;
                                size_of_the_job += mess_size;
                            break;
                          case QMessageBox::No:
                             for_2_tab = -1;
                             size_of_the_job = mess_size;
                            break;
                          default:
                            break;
                        }

                }

                QString b = QString::number(for_2_tab);
               // qDebug() << b;
                //QString s = QString::number(st);
                QSqlQuery query2(db);
            QString second_name;
            QString sentence_name;
            QString name;
                query2.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
                if (query2.next()) {
                     name = query2.value(0).toString();
                    if (change_lang) {

                       QDir qdWDir;
                       QString sWDir = qdWDir.absolutePath();
                       sWDir.append("/");
                       QDir::setCurrent(sWDir);

                       QString voice;

                       voice = name;
                       voice.push_front('"');
                        voice.push_back('"');
                        qDebug() << "search dic"<< voice;
                        if (play_table_word) {
                            //qDebug() << play_words;
                            if (speacker_on_rand) {
                                newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                            }
                        }
                    }
                      // qDebug() << name;
                       second_name = query2.value(1).toString();
                       sentence_name = query2.value(2).toString();
                       if (change_lang) {
                            ui->mainVord->setText(name);
                       } else {
                           ui->mainVord->setText(second_name);
                       }
                       ui->SimpleSintence->setText(sentence_name);
                }

            QVector<QStringList> lst;
             QSqlQuery query(db);
             if (change_lang) {
                query.exec("SELECT Translation FROM '"+new_name_of_table+"'");
             } else {
                query.exec("SELECT Word FROM '"+new_name_of_table+"'");
             }
             while (query.next()) {
                 QSqlRecord record = query.record();
                 QStringList tmp;
                    for(int i=0; i < record.count(); i++)
                     {
                         tmp << record.value(i).toString();
                     }
                     lst.append(tmp);
                 }
           //
             if (lst.size() < size_of_the_job) {
                 size_of_the_job = lst.size();
             }
             size_of_db = lst.size();

             QStringList sorted_items;
             if (change_lang) {
                sorted_items.append(second_name);
             } else {
                sorted_items.append(name);
             }

             int for_rand = 0;
             if (lst.size() < 7) {
                 for_rand = lst.size()/2;
             } else {
                 for_rand = 7;
             }

             for (int i=0;i<for_rand;i++){
                 int arr_i_b = qrand() % lst.size();
                 if (change_lang) {
                     if(second_name != lst[arr_i_b][0]) {
                          sorted_items.append(lst[arr_i_b][0]);
                     }
                 } else {
                     if(name != lst[i][0]) {
                          sorted_items.append(lst[arr_i_b][0]);
                     }
                 }
             }
             QStringList temp = count_same_words_ret(sorted_items);

             qSort(temp.begin(),temp.end());
             for (int i=0;i<temp.size();i++){
                 QListWidgetItem* lwi = new QListWidgetItem(temp[i]);
                 lwi->setSizeHint(QSize(250, 40));
                 ui->algo_2_list->addItem( lwi );
                 lwi->setTextAlignment(Qt::AlignCenter);
             }
             listsize = sorted_items.size();
        }
    }
    if(index == 1) {
        a = -1;
        ui->listfirst->clear();
        ui->listsecond->clear();
       // size_of_the_job = mess_size;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3");
        db.setDatabaseName(Rpath);
        if (!db.open()) {
            qDebug("Error occurred opening the database.");
            qDebug("%s.", qPrintable(db.lastError().text()));
            return;
         }
        QVector<QStringList> lst,bst;
         QSqlQuery* query = new QSqlQuery(db);
         query->exec("SELECT Word FROM '"+new_name_of_table+"'");
         while (query->next()) {
             QSqlRecord record = query->record();
             QStringList tmp;
                for(int i=0; i < record.count(); i++)
                 {
                     tmp << record.value(i).toString();
                 }
                 lst.append(tmp);
             }
         if (lst.size() < size_of_the_job) {
             size_of_the_job = lst.size();
         }
         size_of_db = lst.size();
         QVector<QString> sorted_items,listsecond;
         for (int i=deleted_match_words;i<size_of_the_job;i++){
                sorted_items.append(lst[i][0]);
         }
         QSqlQuery* query1 = new QSqlQuery(db);
         query1->exec("SELECT Translation FROM '"+new_name_of_table+"'");
         while (query1->next()) {
             QSqlRecord record = query1->record();
             QStringList tmp;
                for(int i=0; i < record.count(); i++)
                 {
                     tmp << record.value(i).toString();
                 }
                 bst.append(tmp);
         }

         for (int i=deleted_match_words;i<size_of_the_job;i++){
            listsecond.append((bst[i][0]));
         }
         qSort(sorted_items.begin(),sorted_items.end());
         if (!change_maches) {
             for (int i=0;i<sorted_items.size();i++){
                 QListWidgetItem* lwi = new QListWidgetItem(sorted_items[i]);
                 lwi->setSizeHint(QSize(250, 40));
                 ui->listsecond->addItem( lwi );
                 lwi->setTextAlignment(Qt::AlignCenter);
             }

             listsize = sorted_items.size();

             for (int i=0;i<listsecond.size();i++){
                 QListWidgetItem* lwi = new QListWidgetItem(listsecond[i]);
                 lwi->setSizeHint(QSize(250, 40));
                 ui->listfirst->addItem( lwi );
                 lwi->setTextAlignment(Qt::AlignCenter);
             }
         } else {
             for (int i=0;i<sorted_items.size();i++){
                 QListWidgetItem* lwi = new QListWidgetItem(sorted_items[i]);
                 lwi->setSizeHint(QSize(250, 40));
                 ui->listfirst->addItem( lwi );
                 lwi->setTextAlignment(Qt::AlignCenter);
             }
             listsize = sorted_items.size();
             for (int i=0;i<listsecond.size();i++){
                 QListWidgetItem* lwi = new QListWidgetItem(listsecond[i]);
                 lwi->setSizeHint(QSize(250, 40));
                 ui->listsecond->addItem( lwi );
                 lwi->setTextAlignment(Qt::AlignCenter);
             }
         }

    }

    if (index  == 3) {
       // m_gl->
        tab_3(l);
        ui->toolBox->setCurrentIndex(1);

    }

}
}

QString GetRandomString(QString str)
{
   //const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
   const int randomStringLength = str.size(); // assuming you want random strings of 12 characters
   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % str.length();
       QChar nextChar = str.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

void MainWindow::tab_3(int l) {
    index_for =0;
    //qDebug() << index_for;
    ui->label_forclik->clear();
    lab_name.clear();
    while( m_gl->count() ) {
        QWidget* widget = m_gl->itemAt(0)->widget();
        if( widget ) {
             m_gl->removeWidget(widget);
                delete widget;
        }
    }
    ui->seetranslation_3->setVisible(true);
    ui->nextword_3->setVisible(false);
    a_4++;
    QString b = QString::number(a_4);
    QVector<QStringList> lst;
    if (a_4 == size_of_the_job) {
        switch( QMessageBox::question(
                        this,
                        tr("Learn Words"),
                        tr("We are going to the next words"),
                        QMessageBox::Yes |
                        QMessageBox::No
                         ) )
            {
              case QMessageBox::Yes:
                    a_4= size_of_the_job;
                    size_of_the_job += mess_size;
                break;
              case QMessageBox::No:
                 a_4 = -1;

                break;
              default:
                break;
            }

    }
    if (a_4 != size_of_the_job && a_4 != -1) {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3-");
    db.setDatabaseName(Rpath);
    if (!db.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db.lastError().text()));
        return;
     }
    QSqlQuery query(db);
    query.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
    if (query.next()) {
        QString name;
        if (l == 1){
           name = query.value(0).toString();
           answare = query.value(1).toString();
        }
        if(l==0){
            name = query.value(1).toString();
            answare = query.value(0).toString();
        }
           QString sentence = query.value(2).toString();
           QString pic_path_goo = query.value(5).toString();

           QDir qdWDir;
           QString sWDir = qdWDir.absolutePath();
           sWDir.append("/");
           QDir::setCurrent(sWDir);
           QString voice;
           voice = name;
           voice.push_front('"');
           voice.push_back('"');
            if (play_table_word) {
                if (speacker_on_memorize) {
                    newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                }
            }
           ui->label_13->setText(name);
            QString butt_text,aaaa;

           aaaa = answare;

             std::random_shuffle(aaaa.begin(), aaaa.end());
            //std::random_shuffle(aaaa.begin()+aaaa.size()/2, aaaa.begin());
           for (int i=0;i<aaaa.size();i++){
               but = new QPushButton;
              // but_t = new QPushButton;
               but->setMinimumWidth(60);
               but->setMinimumHeight(60);
               but->setMaximumWidth(60);
               but->setMaximumHeight(60);
               //but->
              // but->font(sub);
               QFont font = but->font();

               font.setPointSize(16);
               but->setFont(font);
                   butt_text.append(aaaa[i]);
                   but->setText(butt_text);
                   m_gl->add_widget(but);
                   butt_text.clear();
                   connect(but, SIGNAL(clicked()), this, SLOT(pbClicked()));



           }
           ui->widget->setLayout(m_gl);
           ui->frame_7->setLayout(hlayaut);


    }
    query.exec(" SELECT Translation FROM '"+new_name_of_table+"'");
    while (query.next()) {
        QSqlRecord record = query.record();
        QStringList tmp;
           for(int i=0; i < record.count(); i++)
            {
                tmp << record.value(i).toString();
            }
            lst.append(tmp);
        }
    }
   int ls =  lst.size();
   qDebug() << a_4;
   qDebug() << ls;
    if (ls == a_4) {
        switch( QMessageBox::question(
                        this,
                        tr("Learn Words"),
                        tr("You have finished the lesson. Do you want to retry?"),

                        QMessageBox::Yes |
                        QMessageBox::No
                         ) )
            {
              case QMessageBox::Yes:
                qDebug( "yes" );
                    a_4 = -1;
                     size_of_the_job = mess_size;
                     on_tabWidget_tabBarClicked(3);
                    //a_4 = -1;

                break;
              case QMessageBox::No:
                //qDebug( "no" );
                    a_4 = lst.size();
                     size_of_the_job = mess_size;
                     if (see_mistakes_){
                         ui->stackedWidget->setCurrentIndex(4);
                         ui->resultes->clicked(true);
                         ui->listWidgetres->DoubleClicked;
                     }

                //}
                break;

              default:
            size_of_the_job = mess_size;
                //qDebug( "close" );
                break;
            }
    }

}


void MainWindow::on_show_the_answare_clicked()
{
    ui->label_forclik->setText(answare);
}

void MainWindow::pbClicked(){
    QPushButton * senderButton = qobject_cast<QPushButton *>(this->sender());
   // QPushButton * senderButton1 = qobject_cast<QPushButton *>(this->sender());
    QString but_text_cout1  = senderButton->text();
    qDebug() << senderButton->text();
    if (index_for != answare.size()-1){
        if (answare.at(index_for) == but_text_cout1 ){
            lab_name.append(but_text_cout1);
            lab_name.append("   ");
            ui->label_forclik->setText(lab_name);
            senderButton->setEnabled(false);
            index_for++;
        } else {

              senderButton->setStyleSheet("QPushButton {color: silver;background-color: none;border-width: 1px; border-color: #EE2C2C; border-style: solid;}");
              // Sleep(50000);
              QTimer t;
              t.start(1000);

              QEventLoop loop;
              connect(&t, SIGNAL(timeout()), &loop, SLOT(quit()));
              loop.exec();
               senderButton->setStyleSheet("QPushButton {color: silver;background-color: none;border-width: 1px; border-color: #4A4949; border-style: solid;}");
        }
    } else {
        on_tabWidget_tabBarClicked(3);
    }

   // qDebug() << index_for;

   // pb_resClicked();
    //senderButton->clicked(true);

}



void MainWindow::on_algo_2_list_clicked(const QModelIndex &index)
{
    //ui->frame_3->setStyleSheet("QFrame { background-color: #2A2929;width: 15px; margin: 15px 3px 15px 3px; border: 1px transparent #2A2929;border-radius: 4px;} }");
    QModelIndexList list =ui->algo_2_list->selectionModel()->selectedIndexes();

    QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }

       QString arr;
       for (int i = 0; i<slist.size();i++)
           arr = slist[i];
        qDebug() <<"arr"<< arr;
       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connectiona1");
       db.setDatabaseName(Rpath);
       if (!db.open()) {
           qDebug("Error occurred opening the database.");
           qDebug("%s.", qPrintable(db.lastError().text()));
           return;
        }
        QSqlQuery query(db);

    QString search;
    search = ui->mainVord->text();
     qDebug() <<"mainVord"<< search;
     if (!change_lang && speacker_on_rand) {

        QDir qdWDir;
        QString sWDir = qdWDir.absolutePath();
        sWDir.append("/");
        QDir::setCurrent(sWDir);

        QString voice;

        voice = arr;
        voice.push_front('"');
         voice.push_back('"');
         qDebug() << "search dic"<< voice;
         if (play_table_word) {
             //qDebug() << play_words;
             if (speacker_on_rand) {
                 newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
             }
         }
     }
    int row = 0;
    if (change_lang) {
        if (query.exec("select * from word were WHERE Word='" + search + "' and Translation='" + arr +"'"))
        {
            if (query.next())
            {
               // qDebug() << "araaaa";
                 //ui->mainVord->setStyleSheet("QLabel {background: green; color : #DCDCDC; }");
                 //ui->scrollArea_2->setStyleSheet("QScrollArea {border: 1px solid green;};");

                ui->algo_2_list->clear();
                on_tabWidget_tabBarClicked(2);
            } else {

                //ui->algo_2_list->setStyleSheet("QListView::item:selected:active  {background: #ff3939; color: #FFFFFF;};");
                //ui->scrollArea_2->setStyleSheet("QScrollArea {border: 1px solid #ff3939;};");

            }
        }
    }else {
        if (query.exec("select * from word were WHERE Word='" + arr + "' and Translation='" + search +"'"))
        {
            if (query.next())
            {
               // qDebug() << "araaaa";
                 //ui->mainVord->setStyleSheet("QLabel {background: green; color : #DCDCDC; }");
                 //ui->scrollArea_2->setStyleSheet("QScrollArea {border: 1px solid green;};");

                ui->algo_2_list->clear();
                on_tabWidget_tabBarClicked(2);
            } else {
                //ui->algo_2_list->setStyleSheet("QListView::item:selected:active  {background: #ff3939; color: #FFFFFF;};");
               // ui->scrollArea_2->setStyleSheet("QScrollArea {border: 1px solid #ff3939;};");

            }
        }
    }
}

void MainWindow::on_listfirst_doubleClicked(const QModelIndex &index)
{

}

void MainWindow::on_nextword_3_clicked()
{


      on_tabWidget_tabBarClicked(0);

}



void MainWindow::on_seetranslation_3_clicked()
{
    ui->seetranslation_3->setVisible(false);
    ui->nextword_3->setVisible(true);
    ui->nextword_3->setText(answare);
    //on_tabWidget_tabBarClicked(1);
}

void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()) {
        random_changes = true;
        on_tabWidget_tabBarClicked(2);

    } else {
        random_changes = false;
        on_tabWidget_tabBarClicked(2);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    settings sett;
    sett.setModal(true);
    sett.exec();
}

void MainWindow::on_settings_job_clicked()
{
    on_pushButton_3_clicked();
    on_tabWidget_tabBarClicked(0);
}

void MainWindow::on_changelanguage_clicked()
{
    if (change_lang) {
        change_lang = false;
        on_tabWidget_tabBarClicked(2);
    }
    else {
        change_lang = true;
        on_tabWidget_tabBarClicked(2);
    }
}

void MainWindow::on_voice_on_clicked()
{
    speacker_on_rand = true;
    ui->voice_on->hide();
    ui->voice_of->show();
}

void MainWindow::on_voice_of_clicked()
{
    speacker_on_rand = false;
    ui->voice_of->hide();
    ui->voice_on->show();
}

void MainWindow::on_play_Randword_clicked()
{
    if (change_lang) {

       QDir qdWDir;
       QString sWDir = qdWDir.absolutePath();
       sWDir.append("/");
       QDir::setCurrent(sWDir);
       QString name = ui->mainVord->text();
       QString voice;


       voice = name;
       voice.push_front('"');
        voice.push_back('"');
        qDebug() << "search dic"<< voice;
        if (play_table_word) {
            //qDebug() << play_words;
            if (speacker_on_rand) {
                newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
            }
        }
    }
}

void MainWindow::on_GP_hide_clicked()
{
    ui->scrollArea_5->hide();
    ui->GP_hide->hide();
    ui->GP_hide_2->show();
}

void MainWindow::on_GP_hide_2_clicked()
{
    ui->scrollArea_5->show();
    ui->GP_hide_2->hide();
    ui->GP_hide->show();
}

void MainWindow::on_sp_memor_clicked()
{
    QDir qdWDir;
    QString sWDir = qdWDir.absolutePath();
    sWDir.append("/");
    QDir::setCurrent(sWDir);
    QString name1 = ui->label_11->text();
    QString voice;


    voice = name1;
    voice.push_front('"');
     voice.push_back('"');
     qDebug() << "search dic"<< voice;
     if (play_table_word) {
         //qDebug() << play_words;
         if (speacker_on_memorize) {
             newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
         }
     }

}

void MainWindow::on_Mem_voice_on_clicked()
{
    ui->Mem_voice_on->hide();
    speacker_on_memorize = true;
    ui->mem_voice_of->show();
}

void MainWindow::on_mem_voice_of_clicked()
{
    ui->mem_voice_of->hide();
    speacker_on_memorize = false;
    ui->Mem_voice_on->show();
}

void MainWindow::on_Much_voice_on_clicked()
{
    ui->Much_voice_on->hide();
    speacker_on_mach = true;
    ui->much_voice_of->show();
}

void MainWindow::on_much_voice_of_clicked()
{
    ui->much_voice_of->hide();
    speacker_on_mach = false;
    ui->Much_voice_on->show();
}



void MainWindow::on_Chang_mutch_clicked()
{
    change_maches = true;
    on_tabWidget_tabBarClicked(1);

}

void MainWindow::on_changemac_2_clicked()
{
    change_maches = false;
    on_tabWidget_tabBarClicked(1);

}

void MainWindow::on_resultes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

    ui->listWidgetClass->clear();
    ui->toolBox->setCurrentIndex(1);
     ui->listWidgetClass->addItem("Classification");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connectiona1");
    db.setDatabaseName(Rpath);
    if (!db.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db.lastError().text()));
        return;
     }
    QSqlQuery* query3 = new QSqlQuery(db);
    QVector<QVector<int> > bst_1;
    query3->exec("SELECT Word FROM Mis_C");
    while (query3->next()) {
        QSqlRecord record = query3->record();
        QVector<int> tmp;
           for(int i=0; i < record.count(); i++)
            {
                tmp .push_back( record.value(i).toInt());
            }
            bst_1.append(tmp);
    }
    for (int i=0;i<bst_1.size();i++){
       tables_count_db.append((bst_1[i][0]));
    }
 //   qDebug() << "Chart_words1 by clicking111" <<tables_count_db;

       ui->listWidgetres->clear();
     QStringList lst = db.tables();
     int a = lst.size()-3;
   // qDebug() << a;
     QSqlQuery query(db);
     for (int i=2;i<lst.size();i++) {
         query.exec("select * from '"+lst[i]+"'");
         query.last();

         tables_count.push_back(query.at() + 2);
     }

     for (int i=2;i<lst.size();i++) {
           ui->listWidgetres->addItem(lst[i]);
     }
   // int a = lst.size()-1;
   //  qDebug() << "sdfasdaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
     ui->listWidgetres->item(a)->setSelected(true);
     QModelIndexList list =ui->listWidgetres->selectionModel()->selectedIndexes();
    QModelIndex aaa = list[0];

     on_listWidgetres_doubleClicked(aaa);
}



void MainWindow::on_dbclick_play(QListWidgetItem* item)
{
    if (ui->listWidgetres->item(0) == item) {
        // This is the first item.
    }
}



void MainWindow::showTable1(QString tableName)
{
    name_of_the_new_table = tableName;
    QSqlDatabase db_res = QSqlDatabase::addDatabase("QSQLITE", "connectiona1");
    db_res.setDatabaseName(path_to_add_mis_table);
    if (!db_res.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db_res.lastError().text()));
        return;
    }
    QSqlTableModel * model = new QSqlTableModel(0, db_res);
    count_same_words(mistake_1);
    QStringList temp_translations = count_same_words_ret(mistake_1_1);
    QStringList temp_sentence_name = count_same_words_ret(sentence_a);
    QStringList temp_pictures_path = count_same_words_ret(picpath);
    QStringList temp_comment = count_same_words_ret(comment_a);
    QStringList temp_pictures = count_same_words_ret(pictur);

    if (temp_sentence_name.size()<chart_names.size()){
        for (int i=temp_sentence_name.size();i<chart_names.size();i++)
            temp_sentence_name.append("");
    }
    if (temp_comment.size()<chart_names.size()){
        for (int i=temp_comment.size();i<chart_names.size();i++)
            temp_comment.append("");
    }
    if (temp_translations.size()<chart_names.size()){
        for (int i=temp_translations.size();i<chart_names.size();i++)
            temp_translations.append("");
    }
    if (temp_pictures_path.size()<chart_names.size()){
        for (int i=temp_pictures_path.size();i<chart_names.size();i++)
            temp_pictures_path.append("");
    }
    if (temp_pictures.size()<chart_names.size()){
        for (int i=temp_pictures.size();i<chart_names.size();i++)
            temp_pictures.append("");
    }



    QSqlQuery query3(db_res);

    query3.prepare("INSERT INTO '"+tableName+"' (rowid,Word,Translation,Sentence,Pictures,Comment,Count,picpath) values(:rowid,:Word,:Translation,:Sentence,:Pictures,:Comment,:Count,:picpath)");
    for (int i=0;i<chart_names.size();i++) {
        query3.bindValue(":rowid",i);
        query3.bindValue(":Word",chart_names[i]);
        query3.bindValue(":Translation",temp_translations[i]);
        query3.bindValue(":Sentence",temp_sentence_name[i]);
        query3.bindValue(":Comment",temp_comment[i]);
        query3.bindValue(":Pictures",temp_pictures[i]);
        query3.bindValue(":Count",count_vords[i]);
        query3.bindValue(":picpath",temp_pictures_path[i]);
        query3.exec();
    }
    count_vords.clear();
    chart_names.clear();




    QVector<QStringList> lst;
     QSqlQuery* query = new QSqlQuery(db_res);
     query->exec("SELECT Word FROM '"+tableName+"'");
     while (query->next()) {
         QSqlRecord record = query->record();
         QStringList tmp;
            for(int i=0; i < record.count(); i++)
             {
                 tmp << record.value(i).toString();
             }
             lst.append(tmp);
     }
     for (int i=0;i<lst.size();i++){
            Chart_words1 << lst[i][0];
     }


     qDebug() <<"Chart_words1 by clicking" <<Chart_words1;

     QSqlQuery* query1 = new QSqlQuery(db_res);
     QVector<QVector<int> > bst;
     query1->exec("SELECT Count FROM '"+tableName+"'");
     while (query1->next()) {
         QSqlRecord record = query1->record();
         QVector<int> tmp;
            for(int i=0; i < record.count(); i++)
             {
                 tmp .push_back( record.value(i).toInt());
             }
             bst.append(tmp);
     }

     for (int i=0;i<bst.size();i++){
        Chart_count1.append((bst[i][0]));
     }
     qDebug() << "Chart_words1 by clicking111" <<Chart_count1;





    model->setTable(tableName);
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView_2_res->setModel(model);
    ui->tableView_2_res->setColumnHidden(6, true);



    ui->tableView_2_res->resizeColumnsToContents();


    setupModel();

    setupChart();
    chart_names.clear();
    count_vords.clear();
}

void MainWindow::onButtonClicked()
{
   // const int r = m_lineEdit->text().toInt(); // r == 0 if invalid
    m_frame->setCircleRadius( 10 );
    m_frame->update();
}



void MainWindow::on_listWidgetres_doubleClicked(const QModelIndex &index)
{
    QModelIndexList list =ui->listWidgetres->selectionModel()->selectedIndexes();
    QStringList slist;
       foreach(const QModelIndex &index, list){
           slist.append( index.data(Qt::DisplayRole ).toString());
       }

       QString arr;
       for (int i = 0; i<slist.size();i++)
           arr = slist[i];


       ui->mist_tab_nam->setText(arr);
       showTable1(arr);
        ////////////////////////


       ui->BarPlot->axisY()->setRanges(0, 100);
       ui->BarPlot->axisY()->setTicks(2, 2);
       ui->BarPlot->axisY()->setPen(QPen(Qt::darkGray));
       ui->BarPlot->axisY()->setMinorTicksPen(QPen(Qt::gray));
       ui->BarPlot->axisY()->setMajorTicksPen(QPen(Qt::darkGray));
       //ui->BarPlot->axisY()->setMinorGridPen(QPen(Qt::gray));
       ui->BarPlot->axisY()->setMajorGridPen(QPen(Qt::lightGray));
       ui->BarPlot->axisY()->setTextColor(Qt::white);

       ui->BarPlot->axisX()->setPen(QPen(Qt::darkGray));
       ui->BarPlot->axisX()->setMinorTicksPen(QPen(Qt::gray));
       ui->BarPlot->axisX()->setMajorTicksPen(QPen(Qt::darkGray));
       ui->BarPlot->axisX()->setMajorGridPen(QPen(Qt::lightGray));
       ui->BarPlot->axisX()->setTextColor(Qt::white);

       ui->BarPlot->setBarSize(32, 128);
       ui->BarPlot->setBarOpacity(0.75);

       ui->BarPlot->setBarSize(32, 128);
       ui->BarPlot->setBarOpacity(2);

       QLinearGradient bg(0,0,0,1);
       bg.setCoordinateMode(QGradient::ObjectBoundingMode);
       bg.setColorAt(1, QColor("#302E2F"));
       bg.setColorAt(0.5, QColor("#302E2F"));
       bg.setColorAt(0, QColor("#302E2F"));
       ui->BarPlot->setBackground(QBrush(bg));

       itemModel = new QStandardItemModel(1,4,this);
       itemModel->setHorizontalHeaderLabels(Chart_words1);
       qDebug() << "count " << Chart_count1;
       //itemModel->setVerticalHeaderLabels(Chart_count);
       itemModel->setHeaderData(0, Qt::Vertical, QColor("#00CED1"), Qt::BackgroundRole);

       for (int i = 0; i < 1; i++)
           for (int j = 0; j < Chart_words1.size(); j++)
               itemModel->setData(itemModel->index(i,j), Chart_count1[j]);
        strong = true;
       ui->BarPlot->setModel(itemModel);


      // ui->tableView_2_res->setModel(itemModel);

       on_NearButton_clicked();



       Chart_words1.clear();
       Chart_count1.clear();
}

void MainWindow::on_pushButton_4_res_back_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::setupModel(void)
  {
  int i;
  QDateTime date_time=QDateTime::currentDateTime();

  model=new QStandardItemModel(tables_count_db.size(),3,this);
  model->setHeaderData(0,Qt::Horizontal,tr("X"));
  model->setHeaderData(1,Qt::Horizontal,tr("Y"));
  model->setHeaderData(2,Qt::Horizontal,tr("K"));

  qDebug()<< "jhjjjjjj" <<tables_count;
  qDebug()<< "jhjjjjjj" <<tables_count_db;
  for(i=0;i<model->rowCount();i++)
    {
    model->setData(model->index(i,0,QModelIndex()),tables_count_db[i]);
    date_time=date_time.addSecs(60);

    model->setData(model->index(i,1,QModelIndex()),tables_count_db[i]);
    model->setData(model->index(i,1,QModelIndex()),QColor(255,0,0),Qt::DecorationRole);

    model->setData(model->index(i,2,QModelIndex()),tables_count_db[i]);
    model->setData(model->index(i,2,QModelIndex()),QColor(0,255,0),Qt::DecorationRole);
    }
  }

void MainWindow::setupChart(void)
{
  ui->chart->setModel(model);
  ui->chart->setting().border().setRight(30);
  ui->chart->setting().border().setLeft(30);
  ui->chart->setting().border().setTop(30);
  ui->chart->setting().border().setBottom(30);
  ui->chart->setting().border().setBackgroundColor(QColor(48,46,47));
  ui->chart->setting().grid().horizzontalTick().setTickMajor(11);
  // ui->chart->setting().grid().horizzontalTick().setTickMinor(5);
  ui->chart->setting().grid().verticalTick().setTickMajor(11);
  //ui->chart->setting().grid().verticalTick().setTickMinor(5);
  ui->chart->setting().grid().setBackgroundColor(QColor(48,46,47));
  ui->chart->setting().grid().setForegroundColor(QColor(255,255,255));
  ui->chart->setting().scale().setAutoCurrentLimit(true);
  ui->chart->setting().scale().setNominalAutoLimit(true);
  ui->chart->updateChart();
}


void MainWindow::on_learn_mistkake_clicked()
{
    size_of_the_job = mess_size;
    deleted_match_words = 0;

   new_name_of_table = name_of_the_new_table;

   // table_open_new(new_name_of_table);
   QSqlDatabase db_res = QSqlDatabase::addDatabase("QSQLITE", "connectiona1");
   db_res.setDatabaseName(path_to_add_mis_table);
   if (!db_res.open()) {
       qDebug("Error occurred opening the database.");
       qDebug("%s.", qPrintable(db_res.lastError().text()));
       return;
    }
   QSqlTableModel * model = new QSqlTableModel(0, db_res);
    //qDebug() <<tableName;

    QSqlQuery query2(db_res);
    for (int i=0;i<chart_names.size();i++){
           query2.prepare("ALTER TABLE '"+new_name_of_table+"' column Count");
    }
   qDebug() << new_name_of_table;
   table_open_new(new_name_of_table);
   ui->pushButton1->clicked(true);
   on_tabWidget_tabBarClicked(0);
   ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_StackedButton_clicked()
{
    ui->BarPlot->axisY()->setRanges(-100, 100);
    ui->BarPlot->setBarScale(0.5);
    ui->BarPlot->setBarType(QSint::BarChartPlotter::Stacked);
    ui->BarPlot->repaint();
}

void MainWindow::on_NearButton_clicked()
{
    if (strong == true)
        ui->BarPlot->axisY()->setRanges(0, 50);
    else
        ui->BarPlot->axisY()->setRanges(0, 6);
    ui->BarPlot->setBarScale(0.1);
    ui->BarPlot->setBarType(QSint::BarChartPlotter::Columns);
    ui->BarPlot->repaint();
}
void MainWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void MainWindow::on_sign_in_clicked()
{
    // ui->stackedWidget->setCurrentIndex(0);
    QString reg_name = ui->lineEdit_regis->text();

    QSqlDatabase db_res = QSqlDatabase::addDatabase("QSQLITE", "connectiona1");
    db_res.setDatabaseName(QDir::currentPath() + "/sqldrivers/lic.sqlite");
    if (!db_res.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db_res.lastError().text()));
        return;
     }

    QVector<QStringList> lst;
    QStringList regname_lsit;
     QSqlQuery* query = new QSqlQuery(db_res);
     query->exec("SELECT Word FROM word");
     while (query->next()) {
         QSqlRecord record = query->record();
         QStringList tmp;
            for(int i=0; i < record.count(); i++)
             {
                 tmp << record.value(i).toString();
             }
             lst.append(tmp);
     }
     for (int i=0;i<lst.size();i++){
            regname_lsit << lst[i][0];
     }
   qDebug() <<  regname_lsit;
    for (int i=0;i<regname_lsit.size();i++) {
        if (regname_lsit[i] == reg_name) {
            ui->stackedWidget->setCurrentIndex(0);
        } else {
            ui->status->setText("You don't have acount!");
        }
    }

}

void MainWindow::on_lineEdit_regis_returnPressed()
{
    on_sign_in_clicked();
}

void MainWindow::on_ch_l1_clicked()
{
    l=0;
    ui->ch_l1->hide();
    ui->ch_l2->show();
    a_4 = -1;
    on_tabWidget_tabBarClicked(3);
}

void MainWindow::on_ch_l2_clicked()
{
    l=1;
    a_4 =-1;
    ui->ch_l2->hide();
    ui->ch_l1->show();
    on_tabWidget_tabBarClicked(3);
}




void MainWindow::on_next_shufle_clicked()
{
    on_tabWidget_tabBarClicked(3);
}

void MainWindow::on_classifiing_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->classifiing->setChecked(true);
    ui->nex_word_clas_2->setEnabled(false);
    on_nex_word_clas_clicked();
}

void MainWindow::on_nex_word_clas_clicked()
{
    //ui->seetranslation_3->setVisible(true);
   // ui->nextword_3->setVisible(false);
    ui->nex_word_clas->setEnabled(false);
    ui->the_hurd_is->setText("");
    ui->pushbuttonforvalues_2->setEnabled(true);
    ui->pushbuttonforvalues_3->setEnabled(true);
    ui->pushbuttonforvalues_4->setEnabled(true);
    ui->pushbuttonforvalues_5->setEnabled(true);
    ui->pushbuttonforvalues_6->setEnabled(true);
    ui->pushbuttonforvalues_1->setEnabled(true);

    for_class++;
    QString b = QString::number(for_class);
    QVector<QStringList> lst;


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection3-");
    db.setDatabaseName(Rpath);
    if (!db.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db.lastError().text()));
        return;
     }
    QSqlQuery query(db);
    query.exec("SELECT * FROM '"+new_name_of_table+"' WHERE rowid='" + b + "'");
    if (query.next()) {
           known_name = query.value(0).toString();
           known_tranckik = query.value(1).toString();
           known_sentence = query.value(2).toString();
           known_Pick = query.value(3).toString();
           known_comment = query.value(4).toString();
           known_pic_path_goo = query.value(5).toString();

           QDir qdWDir;
           QString sWDir = qdWDir.absolutePath();
           sWDir.append("/");
           QDir::setCurrent(sWDir);
           QString voice;
           voice = known_name;
           voice.push_front('"');
           voice.push_back('"');
            if (play_table_word) {
                if (speacker_on_memorize) {
                    newProcess->start("espeak.exe -v female5+f5 -s 120 -a 50 "+voice+"");
                }
            }
            ui->known_words_eng->setText(known_name);
            ui->known_words_eng_2->setText(known_tranckik);


    }
    query.exec(" SELECT Translation FROM word");
    while (query.next()) {
        QSqlRecord record = query.record();
        QStringList tmp;
           for(int i=0; i < record.count(); i++)
            {
                tmp << record.value(i).toString();
            }
            lst.append(tmp);
     }

    if (lst.size() == for_class) {
        switch( QMessageBox::question(
                        this,
                        tr("Learn Words"),
                        tr("You have finished the Classificatyon. Do you want to classifay?"),

                        QMessageBox::Yes |
                        QMessageBox::No
                         ) )
            {
              case QMessageBox::Yes:

                    ui->nex_word_clas_2->setEnabled(true);
                    on_nex_word_clas_2_clicked();
                break;
              case QMessageBox::No:

                    ui->nex_word_clas_2->setEnabled(false);
                    on_backclass_clicked();

                break;
              default:
              break;
            }
    }

}

void MainWindow::on_backclass_clicked()
{
    for_class=-1;
    known_name_list.clear();
    known_tranckik_list.clear();
    known_sentence_list.clear();
    known_Pick_list.clear();
    known_comment_list.clear();
    known_pic_path_goo_list.clear();
    known_values.clear();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushbuttonforvalues_2_clicked()
{
    ui->nex_word_clas->setEnabled(true);
    ui->pushbuttonforvalues_1->setEnabled(false);
    ui->pushbuttonforvalues_2->setEnabled(false);
    ui->pushbuttonforvalues_3->setEnabled(false);
    ui->pushbuttonforvalues_4->setEnabled(false);
    ui->pushbuttonforvalues_5->setEnabled(false);
    ui->pushbuttonforvalues_6->setEnabled(false);
    known_name_list << known_name;
     known_tranckik_list << known_tranckik;
     known_sentence_list << known_sentence;
     known_Pick_list << known_Pick;
     known_comment_list << known_comment;
     known_pic_path_goo_list << known_pic_path_goo;
     known_values.append(1);
     ui->the_hurd_is->setText("1");
     qDebug() << known_name_list;
     qDebug() << known_tranckik_list;
     qDebug() << known_sentence_list;
     qDebug() << known_Pick_list;
     qDebug() << known_comment_list;
     qDebug() << known_pic_path_goo_list;
     qDebug() << known_values;
}

void MainWindow::on_pushbuttonforvalues_3_clicked()
{
    ui->nex_word_clas->setEnabled(true);
    ui->pushbuttonforvalues_1->setEnabled(false);
    ui->pushbuttonforvalues_2->setEnabled(false);
    ui->pushbuttonforvalues_3->setEnabled(false);
    ui->pushbuttonforvalues_4->setEnabled(false);
    ui->pushbuttonforvalues_5->setEnabled(false);
    ui->pushbuttonforvalues_6->setEnabled(false);
    known_name_list << known_name;
    known_tranckik_list << known_tranckik;
    known_sentence_list << known_sentence;
    known_Pick_list << known_Pick;
    known_comment_list << known_comment;
    known_pic_path_goo_list << known_pic_path_goo;
    known_values.append(2);
    ui->the_hurd_is->setText("2");
    qDebug() << known_name_list;
    qDebug() << known_tranckik_list;
    qDebug() << known_sentence_list;
    qDebug() << known_Pick_list;
    qDebug() << known_comment_list;
    qDebug() << known_pic_path_goo_list;
    qDebug() << known_values;
}

void MainWindow::on_pushbuttonforvalues_4_clicked()
{
    ui->nex_word_clas->setEnabled(true);
    ui->pushbuttonforvalues_1->setEnabled(false);
    ui->pushbuttonforvalues_2->setEnabled(false);
    ui->pushbuttonforvalues_3->setEnabled(false);
    ui->pushbuttonforvalues_4->setEnabled(false);
    ui->pushbuttonforvalues_5->setEnabled(false);
    ui->pushbuttonforvalues_6->setEnabled(false);
    known_name_list << known_name;
    known_tranckik_list << known_tranckik;
    known_sentence_list << known_sentence;
    known_Pick_list << known_Pick;
    known_comment_list << known_comment;
    known_pic_path_goo_list << known_pic_path_goo;
    known_values.append(3);
    ui->the_hurd_is->setText("3");
    qDebug() << known_name_list;
    qDebug() << known_tranckik_list;
    qDebug() << known_sentence_list;
    qDebug() << known_Pick_list;
    qDebug() << known_comment_list;
    qDebug() << known_pic_path_goo_list;
    qDebug() << known_values;
}

void MainWindow::on_pushbuttonforvalues_5_clicked()
{
    ui->nex_word_clas->setEnabled(true);
    ui->pushbuttonforvalues_1->setEnabled(false);
    ui->pushbuttonforvalues_2->setEnabled(false);
    ui->pushbuttonforvalues_3->setEnabled(false);
    ui->pushbuttonforvalues_4->setEnabled(false);
    ui->pushbuttonforvalues_5->setEnabled(false);
    ui->pushbuttonforvalues_6->setEnabled(false);
    known_name_list << known_name;
    known_tranckik_list << known_tranckik;
    known_sentence_list << known_sentence;
    known_Pick_list << known_Pick;
    known_comment_list << known_comment;
    known_pic_path_goo_list << known_pic_path_goo;
    known_values.append(4);
    ui->the_hurd_is->setText("4");
    qDebug() << known_name_list;
    qDebug() << known_tranckik_list;
    qDebug() << known_sentence_list;
    qDebug() << known_Pick_list;
    qDebug() << known_comment_list;
    qDebug() << known_pic_path_goo_list;
    qDebug() << known_values;
}

void MainWindow::on_pushbuttonforvalues_6_clicked()
{
    ui->nex_word_clas->setEnabled(true);
    ui->pushbuttonforvalues_1->setEnabled(false);
    ui->pushbuttonforvalues_2->setEnabled(false);
    ui->pushbuttonforvalues_3->setEnabled(false);
    ui->pushbuttonforvalues_4->setEnabled(false);
    ui->pushbuttonforvalues_5->setEnabled(false);
    ui->pushbuttonforvalues_6->setEnabled(false);
    known_name_list << known_name;
    known_tranckik_list << known_tranckik;
    known_sentence_list << known_sentence;
    known_Pick_list << known_Pick;
    known_comment_list << known_comment;
    known_pic_path_goo_list << known_pic_path_goo;
    known_values.append(5);
    ui->the_hurd_is->setText("5");
    qDebug() << known_name_list;
    qDebug() << known_tranckik_list;
    qDebug() << known_sentence_list;
    qDebug() << known_Pick_list;
    qDebug() << known_comment_list;
    qDebug() << known_pic_path_goo_list;
    qDebug() << known_values;
}

void MainWindow::on_nex_word_clas_2_clicked()
{
    QSqlDatabase db_res = QSqlDatabase::addDatabase("QSQLITE", "connectiona1");
    db_res.setDatabaseName(Rpath);
    if (!db_res.open()) {
        qDebug("Error occurred opening the database.");
        qDebug("%s.", qPrintable(db_res.lastError().text()));
        return;
    }
    QSqlQuery query3(db_res);
    query3.prepare("UPDATE word SET ValueTheDifficulty = :ValueTheDifficulty WHERE rowid =:rowid ");
    for (int i=0;i<known_name_list.size();i++) {
        query3.bindValue(":rowid",i);
        query3.bindValue(":ValueTheDifficulty",known_values[i]);
        query3.exec();
    }

    query3.prepare("INSERT or replace INTO Classification (rowid,Word,Translation,Sentence,Pictures,Comment,ValueTheDifficulty,picpath) values(:rowid,:Word,:Translation,:Sentence,:Pictures,:Comment,:ValueTheDifficulty,:picpath)");
    for (int i=0;i<known_name_list.size();i++) {
        query3.bindValue(":rowid",i);
        query3.bindValue(":Word",known_name_list[i]);
        query3.bindValue(":Translation",known_tranckik_list[i]);
        query3.bindValue(":Sentence",known_sentence_list[i]);
        query3.bindValue(":Comment",known_comment_list[i]);
        query3.bindValue(":Pictures",known_Pick_list[i]);
        query3.bindValue(":ValueTheDifficulty",known_values[i]);
        query3.bindValue(":picpath",known_pic_path_goo_list[i]);
        query3.exec();
    }

    known_name_list.clear();
    known_tranckik_list.clear();
    known_sentence_list.clear();
    known_Pick_list.clear();
    known_comment_list.clear();
    known_pic_path_goo_list.clear();
    known_values.clear();
    ui->stackedWidget->setCurrentIndex(4);
    on_resultes_clicked();
    ui->toolBox->setCurrentIndex(0);

    ui->listWidgetClass->clear();
    qDebug() << "f";
    ui->listWidgetClass->addItem("Classification");
    ui->listWidgetClass->item(0)->setSelected(true);
    QModelIndexList list =ui->listWidgetClass->selectionModel()->selectedIndexes();
    QModelIndex aaa = list[0];
    on_listWidgetClass_doubleClicked(aaa);
}

void MainWindow::on_listWidgetClass_doubleClicked(const QModelIndex &index)
{
    QModelIndexList list =ui->listWidgetClass->selectionModel()->selectedIndexes();
    QStringList slist;
    foreach(const QModelIndex &index, list){
        slist.append( index.data(Qt::DisplayRole ).toString());
    }
    QString arr;
    for (int i = 0; i<slist.size();i++)
        arr = slist[i];
    ui->mist_tab_nam->setText(arr);

       QSqlDatabase db_res = QSqlDatabase::addDatabase("QSQLITE", "connectiona1");
       db_res.setDatabaseName(Rpath);
       if (!db_res.open()) {
           qDebug("Error occurred opening the database.");
           qDebug("%s.", qPrintable(db_res.lastError().text()));
           return;
       }
       QSqlQuery query3(db_res);


       QVector<QStringList> lst;
        QSqlQuery* query = new QSqlQuery(db_res);
        query->exec("SELECT Word FROM Classification");
        while (query->next()) {
            QSqlRecord record = query->record();
            QStringList tmp;
               for(int i=0; i < record.count(); i++)
                {
                    tmp << record.value(i).toString();
                }
                lst.append(tmp);
        }
        for (int i=0;i<lst.size();i++){
               known_chart_list << lst[i][0];
        }


        qDebug() <<"Chart_words1 by clicking" <<known_chart_list;

        QSqlQuery* query1 = new QSqlQuery(db_res);
        QVector<QVector<int> > bst;
        query1->exec("SELECT ValueTheDifficulty FROM word");
        while (query1->next()) {
            QSqlRecord record = query1->record();
            QVector<int> tmp;
               for(int i=0; i < record.count(); i++)
                {
                    tmp .push_back( record.value(i).toInt());
                }
                bst.append(tmp);
        }

        for (int i=0;i<bst.size();i++){
           known_chart_values.append((bst[i][0]));
        }



        qDebug() << "Chart_words1 by clicking111" <<known_chart_values;
        query3.prepare("UPDATE Classification SET ValueTheDifficulty = :ValueTheDifficulty WHERE rowid =:rowid ");
        for (int i=0;i<known_chart_values.size();i++) {
            query3.bindValue(":rowid",i);
            query3.bindValue(":ValueTheDifficulty",known_chart_values[i]);
            query3.exec();
        }

        QVector<int> itesm_vor_deleting;
        for (int i=0;i<known_chart_values.size();i++){
           itesm_vor_deleting.append((known_chart_values[i]));
        }


        QSqlQuery query0(db_res);
        for(int i=0;i<itesm_vor_deleting.size();i++) {
            if (itesm_vor_deleting[i] == 0) {
                QString b = QString::number(i);
                query0.prepare("DELETE FROM Classification WHERE rowid = '" + b + "'");
                if (!query0.exec())
                {
                    qDebug() << "Error" << query0.lastError().text();
                    return;
                }
            }
        }
        showTable1(arr);
       ////////////////////
       ///
       ///   ui->BarPlot->axisY()->setRanges(0, 100);
       ui->BarPlot->axisY()->setTicks(2, 2);
       ui->BarPlot->axisY()->setPen(QPen(Qt::darkGray));
       ui->BarPlot->axisY()->setMinorTicksPen(QPen(Qt::gray));
       ui->BarPlot->axisY()->setMajorTicksPen(QPen(Qt::darkGray));
       /////ui->BarPlot->axisY()->setMinorGridPen(QPen(Qt::gray));
       ui->BarPlot->axisY()->setMajorGridPen(QPen(Qt::lightGray));
       ui->BarPlot->axisY()->setTextColor(Qt::white);

       ui->BarPlot->axisX()->setPen(QPen(Qt::darkGray));
       ui->BarPlot->axisX()->setMinorTicksPen(QPen(Qt::gray));
       ui->BarPlot->axisX()->setMajorTicksPen(QPen(Qt::darkGray));
       ui->BarPlot->axisX()->setMajorGridPen(QPen(Qt::lightGray));
       ui->BarPlot->axisX()->setTextColor(Qt::white);

       ui->BarPlot->setBarSize(32, 128);
       ui->BarPlot->setBarOpacity(0.75);

       ui->BarPlot->setBarSize(32, 128);
       ui->BarPlot->setBarOpacity(2);

       QLinearGradient bg(0,0,0,1);
       bg.setCoordinateMode(QGradient::ObjectBoundingMode);
       bg.setColorAt(1, QColor("#302E2F"));
       bg.setColorAt(0.5, QColor("#302E2F"));
       bg.setColorAt(0, QColor("#302E2F"));
       ui->BarPlot->setBackground(QBrush(bg));
       itemModel = new QStandardItemModel(1,4,this);
       itemModel->setHorizontalHeaderLabels(known_chart_list);
       itemModel->setHeaderData(0, Qt::Vertical, QColor("#00CED1"), Qt::BackgroundRole);

       for (int i = 0; i < 1; i++)
           for (int j = 0; j < known_chart_values.size(); j++)
               itemModel->setData(itemModel->index(i,j), known_chart_values[j]);
        strong =false;
       ui->BarPlot->setModel(itemModel);
       on_NearButton_clicked();
       known_chart_values.clear();
       known_chart_list.clear();
       ///////////////////
}



void MainWindow::on_pushbuttonforvalues_1_clicked()
{
    ui->nex_word_clas->setEnabled(true);
    ui->pushbuttonforvalues_1->setEnabled(false);
    ui->pushbuttonforvalues_2->setEnabled(false);
    ui->pushbuttonforvalues_3->setEnabled(false);
    ui->pushbuttonforvalues_4->setEnabled(false);
    ui->pushbuttonforvalues_5->setEnabled(false);
    ui->pushbuttonforvalues_6->setEnabled(false);
    known_name_list << "";
    known_tranckik_list << "";
    known_sentence_list << "";
    known_Pick_list << "";
    known_comment_list << "";
     known_pic_path_goo_list << "";
     known_values.append(0);
     ui->the_hurd_is->setText("0");
     qDebug() << known_name_list;
     qDebug() << known_tranckik_list;
     qDebug() << known_sentence_list;
     qDebug() << known_Pick_list;
     qDebug() << known_comment_list;
     qDebug() << known_pic_path_goo_list;
     qDebug() << known_values;
}

void MainWindow::on_add_r_clicked()
{
    on_Add_clicked();
}

void MainWindow::on_rem_r_clicked()
{
    on_pushButton_6_clicked();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    textChangedSlot(arg1);
}

void MainWindow::on_such_clicked()
{
    on_pushButton_8_clicked();
}

void MainWindow::on_syny_clicked()
{
    if(lisens) {
       on_synonyms_button();

        connect(ui->listWidgetres,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_dbclick_play(QListWidgetItem*)));

    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Classified"){
        QString name1 = "Classification";
        new_name_of_table = name1;
        table_open_new(name1);
    }
    else if (arg1 != "word") {
        QString name = "word";
        new_name_of_table = name;
        table_open_new(name);
    }

}

void MainWindow::on_pus__clicked()
{
    on_actionAbout_triggered();
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_8_clicked();
}
