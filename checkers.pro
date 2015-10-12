#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T17:18:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = checkers
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    pieces.cpp

HEADERS  += mainwindow.h \
    pieces.h
