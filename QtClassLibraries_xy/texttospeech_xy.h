#ifndef TEXTTOSPEECH_XY_H
#define TEXTTOSPEECH_XY_H

/*
* brief: 文字转为语音播放，仅限windows 下使用
 *
 * author: xy
 *
 * date： 2018年12月10号
 *
*/

#include <QThread>
#include <QString>
#include <QMutex>

#if defined(Q_OS_WIN)
#include <QAxObject>
#include <qt_windows.h>
#endif

//文字转为语音进行播放，仅限window下使用
class TextToSpeech_xy : public QThread
{
public:
    TextToSpeech_xy();
    ~TextToSpeech_xy();
    //阻塞方式播放文字语音
    static void play(const QString& text);
    //线程方式播放文字语音，多语音时排队播放
    void playing(const QString& text);

protected:
    //C++11中final和override的用法

    //inal标识符用来限制某个类不能被继承，或者某个虚函数不能被继承(非虚函数不能用final标识符修饰)。

    //override标识符可以让编译器帮忙确认派生类中声明的重写函数与基类的虚函数是否有相同的签名，
    //同时也明确表明将会重写基类的虚函数，可以防止因疏忽把本来的想重写的基类的虚函数在派生类中声明为重载，
    //还可以防止在派生类中重写的虚函数声明漏掉virtual关键字。
    virtual void run() override;

    QMutex m_mutex;
    QList<QString> m_sounds;
};

#endif // TEXTTOSPEECH_XY_H
