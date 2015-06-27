#-------------------------------------------------
#
# Project created by QtCreator 2015-06-19T10:13:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candycrush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    star.cpp \
    Destroy.cpp \
    vertical.cpp \
    horizontal.cpp \
    nineblock.cpp

HEADERS  += mainwindow.h \
    blank.h \
    star.h \
    Destroy.h \
    vertical.h \
    horizontal.h \
    nineblock.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc
