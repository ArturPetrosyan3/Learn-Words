#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QDebug>
#include <QWebView>
#include <QListWidgetItem>
#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QLCDNumber>
//#include <QWidgetAction>
#include <QToolButton>

#include <QDebug>

#include <QVector>
#include <QPushButton>
#include <QMouseEvent>
#include "front.h"
#include <QVector>
#include <QBasicTimer>
#include "settings.h"
#include <QStandardItemModel>
#include <QDateTime>
#include <QVBoxLayout>

#include "my_grid_layout.h"

class Frame;


class settings;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    QString s[100];
    int k;
    QString s1[100];
    QString s3[1000];
    void showTable(QString tableName);
    static QString Rpath;
    static QString Fstr;
    QBasicTimer myTimer;
    int p_size;
    int slide_count12=0;
    bool play_words;
    bool play_table_word;
    int mess_size;
    int size_of_the_job = 10;
    int next_wordss;
    int deleted_match_words = 0;
    bool change_lang = true;
    bool speacker_on_rand = false;
    bool speacker_on_memorize = false;
    bool speacker_on_mach = false;
    bool change_maches = false;
    int for_2_tab = -1;
    bool random_changes = true;
    int size_of_db;
    bool the_lesson_is_finished = false;
   QString path_to_add_mis_table;
   QString name_of_the_new_table;
    QString tableName_m;
    QString tableParams_m;
    bool storige = true;
    QStringList mistake_1;
     QStringList mistake_1_1;
    QStringList mistake_2;
    QStringList mistake_2_2;
    QStringList picpath,comment_a,sentence_a,pictur;


    static  QStringList Chart_words1;
     static  QVector<int> Chart_count;
     QVector<int> Chart_count1;
    void setupModel(void);
    void setupChart(void);
    QString new_name_of_table = "word";

    static QVector<int> c;
    QStringList chart_names;
    QVector<int> count_vords;
    QVector<int> tables_count;
    QVector<int> tables_count_db;

    QStringList count_same_words_ret(QStringList);
    //QStringList count_same_words_ret(QStringList);

    static QString pic_path,search_dic,sent_for_pict,transl_for_pic;
    int Column_ind_1 =0;
    int x;
    void on_dbclick_play(QListWidgetItem* item);
    bool lisens = true;
    QString lab_name;
    int index_for = 0;
    QStringList arg_zzv;
    int l=0;
    bool see_mistakes_ = true;
    int for_class = -1;


    QStringList known_name_list;
    QStringList known_tranckik_list;
    QStringList known_sentence_list;
    QStringList known_Pick_list;
    QStringList known_comment_list;
    QStringList known_pic_path_goo_list;

    QStringList known_chart_list;
    QVector<int> known_chart_values;

    QVector<int> known_values;

     QVector<int> diff_val;

    QString known_name;
    QString known_tranckik ;
    QString known_sentence ;
    QString known_Pick ;
    QString known_comment;
    QString known_pic_path_goo ;

    bool strong ;

    bool yas_by_dif = false;

    int if_not_0 = 0;

    QByteArray z;

public slots:
    void textChangedSlot(QString);

private slots:
    void tab_3(int);
    void onButtonClicked();
    void table_open_new(QString);
    void count_same_words(QStringList word);
    void on_tabWidget_tabBarClicked(int index);
    void on_treeView_clicked(const QModelIndex &index);
    void on_listView_clicked(const QModelIndex &index);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_back_clicked();
    void on_close_clicked();
    void on_pushButton_4_clicked();
    void radio_click();
    void on_pushButton_6_clicked();
    void on_Add_clicked();
    void on_pushButton_7_clicked();
    void on_treeView_activated(const QModelIndex &index);
    void on_pushButton_8_clicked();
    void on_actionMin_triggered();
    void on_actionNorm_triggered();
    void on_actionMax_triggered();
    void on_actionClose_triggered();
    void on_addrow_triggered();
    void on_Deleterow_triggered();
    void on_pushButton1_clicked();
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_delete_2_clicked();
    void on_learn_back_clicked();
    void on_listfirst_clicked(const QModelIndex &index);
    void on_listsecond_activated(const QModelIndex &index);
    void on_listsecond_clicked(const QModelIndex &index);
    void on_totext_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_actionAbout_triggered();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_openfile_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_algo_2_list_clicked(const QModelIndex &index);
    void on_listfirst_doubleClicked(const QModelIndex &index);
    void on_nextword_3_clicked();

    void on_seetranslation_3_clicked();

    void on_checkBox_clicked();
    void on_synonyms_button();

    void on_pushButton_3_clicked();

    void on_settings_job_clicked();

    void on_changelanguage_clicked();

    void on_voice_on_clicked();

    void on_voice_of_clicked();

    void on_play_Randword_clicked();

    void on_GP_hide_clicked();

    void on_GP_hide_2_clicked();

    void on_sp_memor_clicked();

    void on_Mem_voice_on_clicked();

    void on_mem_voice_of_clicked();

    void on_Much_voice_on_clicked();

    void on_much_voice_of_clicked();



    void on_Chang_mutch_clicked();

    void on_changemac_2_clicked();

    void on_resultes_clicked();

    void on_listWidgetres_doubleClicked(const QModelIndex &index);
    void showTable1(QString);
    void on_pushButton_4_res_back_clicked();

    void on_learn_mistkake_clicked();

    void on_StackedButton_clicked();

    void on_NearButton_clicked();


    void on_sign_in_clicked();

    void on_lineEdit_regis_returnPressed();
    void pbClicked();


    void on_ch_l1_clicked();

    void on_ch_l2_clicked();

    void on_show_the_answare_clicked();

    void on_next_shufle_clicked();

    void on_classifiing_clicked();

    void on_nex_word_clas_clicked();

    void on_backclass_clicked();

    void on_pushbuttonforvalues_2_clicked();

    void on_pushbuttonforvalues_3_clicked();

    void on_pushbuttonforvalues_4_clicked();

    void on_pushbuttonforvalues_5_clicked();

    void on_pushbuttonforvalues_6_clicked();

    void on_nex_word_clas_2_clicked();

    void on_listWidgetClass_doubleClicked(const QModelIndex &index);



    void on_pushbuttonforvalues_1_clicked();

    void on_add_r_clicked();

    void on_rem_r_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_such_clicked();

    void on_syny_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pus__clicked();

    void on_lineEdit_returnPressed();

protected:
//    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    void changeEvent(QEvent *e);



private:
    Ui::MainWindow *ui;
    QStandardItemModel *itemModel;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    QSqlDatabase myDB;
    QPoint m_dragPosition;
    front *winFront;
    QKeyEvent *mykey;
    int a = -1;
    QString answare;
    int ar;
    int arm,play_table_words;
    QWebView *rad;
    settings *set;
    QProcess* newProcess;
    QStandardItemModel *model;
    int a_4 = -1;
    Frame     *m_frame;
    QVBoxLayout* vLayout;
    //QGridLayout * m_gl;
    QHBoxLayout *hlayaut;
    my_grid_layout * m_gl;
    my_grid_layout * m_lay_1;
    QPushButton *but;
    QPushButton *but_t;

   // static QString path_to_add_mis_table;
};

//QVector<QString> Chart_words,Chart_count;



#endif // MAINWINDOW_H
