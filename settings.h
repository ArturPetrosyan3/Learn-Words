#ifndef SETTINGS_H
#define SETTINGS_H
#include "mainwindow.h"
#include <QDialog>

//#include <QMainWindow>
class MainWindow;
namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();
    MainWindow *ob;



private slots:
    void on_checkBox_4_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_checkBox_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_new_table_clicked();

    void on_checkBox_7_clicked();

    void on_pushButtonclosesettings_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::settings *ui;


};

#endif // SETTINGS_H
