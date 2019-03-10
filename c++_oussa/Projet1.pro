#-------------------------------------------------
#
# Project created by QtCreator 2019-01-19T13:42:30
#
#-------------------------------------------------

QT       += core gui sql



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    platforme1.cpp \
    dialog2.cpp \
    dialogm.cpp \
    ajouteretudiant.cpp

HEADERS  += mainwindow.h \
    platforme1.h \
    dialog2.h \
    dialogm.h \
    ajouteretudiant.h

FORMS    += mainwindow.ui \
    platforme1.ui \
    dialog2.ui \
    dialogm.ui \
    ajouteretudiant.ui

DISTFILES += \
    requetes_sql_projet_cpp
