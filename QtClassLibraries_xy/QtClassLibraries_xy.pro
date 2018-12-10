#-------------------------------------------------
#
# Project created by QtCreator 2018-12-03T17:02:32
#
#-------------------------------------------------

QT       += core gui


# qt5.7以上版本使用QAxObject类
QT += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtClassLibraries_xy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainform.cpp \
    csvfilereadwirte_xy.cpp \
    texttospeech_xy.cpp

HEADERS  += mainform.h \
    csvfilereadwirte_xy.h \
    texttospeech_xy.h

FORMS    += mainform.ui

DISTFILES += \
    updatedInstructions/updatedInstructions.txt









