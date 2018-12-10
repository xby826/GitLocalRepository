#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    m_textToSpeech_xy = new TextToSpeech_xy();
}

MainForm::~MainForm()
{
    delete ui;
}
//csv文件读取示例按钮槽函数
void MainForm::on_csvFileReadBtn_clicked()
{
    QFile file("CsvFileReadWirte_xy.csv");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    CsvFileReadWirte_xy csv(&file);
    while(!csv.atEnd())
    {
        QStringList res = csv.readAndAnalysisCsvLine();
        qDebug().noquote() << res;
    }

    ui->statusBar->showMessage("读取成功...");
}
//csv文件写入示例按钮槽函数
void MainForm::on_csvFileWriteBtn_clicked()
{
    QFile file("CsvFileReadWirte_xy.csv");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    double d = 0.111;
    float f = 0.343f;
    int i = 1212;
    QString str1 = QStringLiteral("这是文本");
    QString str2 = QStringLiteral("这是一个带,号的文本");
    QString str3 = QStringLiteral("这是一个带\"文本");
    //这是一个\"复合文本\"文本:1,2,4,5,xy
    //QString str4 = QStringLiteral("这是一个\"复合文本\"文本:1,2,3,4,5,xy");
    CsvFileReadWirte_xy csv(&file);
    csv << d << f << i << str1 << str2 << str3  << endl;
    csv << str3 << str2 << str1 << i << f << d << endl;
    file.close();
    ui->statusBar->showMessage("写入成功...");
}
//播放按钮槽函数   阻塞方式播放文字语音
void MainForm::on_playBtn_clicked()
{
    m_textToSpeech_xy->play(ui->spackComboBox->currentText());
}
//文字下来框内容改变事件  线程方式播放文字语音，多语音时排队播放
void MainForm::on_spackComboBox_currentTextChanged(const QString &arg1)
{
    m_textToSpeech_xy->playing(arg1);
}
