#include "texttospeech_xy.h"

TextToSpeech_xy::TextToSpeech_xy()
{

}

TextToSpeech_xy::~TextToSpeech_xy()
{

}

void TextToSpeech_xy::play(const QString &text)
{
#if defined(Q_OS_WIN)
    CoInitialize(NULL);
    QAxObject speak("SAPI.SpVoice");
    speak.dynamicCall("Speak(QString)",text);
    CoUninitialize();
#endif
}

void TextToSpeech_xy::playing(const QString &text)
{
    m_mutex.lock();
    m_sounds.append(text);
    m_mutex.unlock();

    if(!isRunning())
    {
        //QThread::LowestPriority 设置线程的优先级
        //优先级中的各个枚举值
//        QThread::IdlePriority  0  没有其它线程运行时才调度.
//        QThread::LowestPriority 1  比LowPriority调度频率低.
//        QThread::LowPriority  2    比NormalPriority调度频率低.
//        QThread::NormalPriority  3  操作系统默认的默认优先级.
//        QThread::HighPriority  4    比NormalPriority调度频繁.
//        QThread::HighestPriority  5  比HighPriority调度频繁.
//        QThread::TimeCriticalPriority  6  尽可能频繁的调度.
//        QThread::InheritPriority   7  使用和创建线程同样的优先级. 这是默认值.
        start(QThread::LowestPriority);
    }
}

void TextToSpeech_xy::run()
{
    for(;;)
    {
        QString sound;
        m_mutex.lock();
        if(!m_sounds.isEmpty())
        {
            sound = m_sounds.takeFirst();
        }
        m_mutex.unlock();

        if(!sound.isEmpty())
        {
            play(sound);
        }
    }
}
