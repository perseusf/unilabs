
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
    currentplayer.cpp \
    decisionmaker.cpp \
    board.cpp \
    dynamicarray.cpp \
    arraysequence.cpp \
    game.cpp \
    linkedlist.cpp \
    listsequence.cpp \
    move.cpp

HEADERS  += \
    board.h \
    currentplayer.h \
    decisionmaker.h \
    game.h \
    move.h \
    dynamicarray.h \
    arraysequence.h \
    linkedlist.h \
    listsequence.h \
    sequence.h

RESOURCES += \
    resource.qrc
