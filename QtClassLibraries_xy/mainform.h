#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>

#include "csvfilereadwirte_xy.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    //csv文件读取示例按钮槽函数
    void on_csvFileReadBtn_clicked();
    //csv文件写入示例按钮槽函数
    void on_csvFileWriteBtn_clicked();

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
