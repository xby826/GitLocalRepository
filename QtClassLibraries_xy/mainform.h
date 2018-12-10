#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>

#include "csvfilereadwirte_xy.h"
#include "texttospeech_xy.h"

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
    //播放按钮槽函数
    void on_playBtn_clicked();
    //文字下来框内容改变事件
    void on_spackComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainForm *ui;

    TextToSpeech_xy *m_textToSpeech_xy;
};

#endif // MAINFORM_H
