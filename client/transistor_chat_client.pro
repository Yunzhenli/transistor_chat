#-------------------------------------------------
#
# Project created by QtCreator 2017-12-03T11:29:06
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = transistor_chat_client
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    custom_windows.cpp \
    custom_titles.cpp

HEADERS += \
    custom_windows.h \
    custom_windows.h \
    mainwindow.h \
    custom_titles.h

FORMS += \
        mainwindow.ui \
    change_host.ui \
    custom_windows.ui \
    custom_windows.ui

RESOURCES += \
    resource/res.qrc
