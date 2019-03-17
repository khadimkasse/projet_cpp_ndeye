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
    ../sokhna_cpp/Note.cpp \
    ../sokhna_cpp/Matiere.cpp \
    afficheretudiants.cpp \
    connectdb.cpp \
    supprimeretudiant.cpp \
    modifieretudiant.cpp

HEADERS  += mainwindow.h \
    platforme1.h \
    dialog2.h \
    dialogm.h \
    ajouteretudiant.h \
    ../sokhna_cpp/Personne.h \
    ../sokhna_cpp/Etudiant.h\
    ../sokhna_cpp/Note.h \
    ../sokhna_cpp/Matiere.h \
    afficheretudiants.h \
    connectdb.h \
    supprimeretudiant.h \
    modifieretudiant.h

FORMS    += mainwindow.ui \
    platforme1.ui \
    dialog2.ui \
    dialogm.ui \
    ajouteretudiant.ui \
    afficheretudiants.ui \
    supprimeretudiant.ui \
    modifieretudiant.ui

DISTFILES += \
    requetes_sql_projet_cpp
