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
    ajouteretudiant.cpp \
    ../sokhna_cpp/Personne.cpp \
    ../sokhna_cpp/Etudiant.cpp \
    afficheretudiants.cpp \
    connectdb.cpp
    ../sokhna_cpp/Note.cpp

HEADERS  += mainwindow.h \
    platforme1.h \
    dialog2.h \
    dialogm.h \
    ajouteretudiant.h \
    ../sokhna_cpp/Personne.h \
    ../sokhna_cpp/Etudiant.h\
    ../sokhna_cpp/Note.h \
    afficheretudiants.h \
    connectdb.h

FORMS    += mainwindow.ui \
    platforme1.ui \
    dialog2.ui \
    dialogm.ui \
    ajouteretudiant.ui \
    afficheretudiants.ui

DISTFILES += \
    requetes_sql_projet_cpp
