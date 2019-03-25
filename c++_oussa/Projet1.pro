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
    ../sokhna_cpp/Professeur.cpp \
    afficheretudiants.cpp \
    connectdb.cpp \
    supprimeretudiant.cpp \
    modifieretudiant.cpp \
    Matiere_UI/ajoutermatiere.cpp \
    Matiere_UI/affichermatieres.cpp \
    Matiere_UI/supprimermatiere.cpp \
    Matiere_UI/modifiermatiere.cpp \
    Professeur_UI/menuprofesseur.cpp \
    Professeur_UI/ajouterprofesseur.cpp \
    Gestion_UI/gestionetudiants.cpp \
    Gestion_UI/noteretudiant.cpp \
    Gestion_UI/gestionprofesseurs.cpp \
    Gestion_UI/menugestion.cpp \
    Gestion_UI/detailsnotes.cpp \
    Professeur_UI/supprimerprofesseur.cpp \
    Professeur_UI/modifierprofesseur.cpp \
    Professeur_UI/afficherprofesseurs.cpp \
    Gestion_UI/afficherpaiements.cpp \
    Gestion_UI/menugestionprofesseurs.cpp

HEADERS  += mainwindow.h \
    platforme1.h \
    dialog2.h \
    dialogm.h \
    ajouteretudiant.h \
    ../sokhna_cpp/Personne.h \
    ../sokhna_cpp/Etudiant.h\
    ../sokhna_cpp/Note.h \
    ../sokhna_cpp/Matiere.h \
    ../sokhna_cpp/Professeur.h \
    afficheretudiants.h \
    connectdb.h \
    supprimeretudiant.h \
    modifieretudiant.h \
    Matiere_UI/ajoutermatiere.h \
    Matiere_UI/affichermatieres.h \
    Matiere_UI/supprimermatiere.h \
    Matiere_UI/modifiermatiere.h \
    Professeur_UI/menuprofesseur.h \
    Professeur_UI/ajouterprofesseur.h \
    Gestion_UI/gestionetudiants.h \
    Gestion_UI/noteretudiant.h \
    Gestion_UI/gestionprofesseurs.h \
    Gestion_UI/menugestion.h \
    Gestion_UI/detailsnotes.h \
    Professeur_UI/supprimerprofesseur.h \
    Professeur_UI/modifierprofesseur.h \
    Professeur_UI/afficherprofesseurs.h \
    Gestion_UI/afficherpaiements.h \
    Gestion_UI/menugestionprofesseurs.h

FORMS    += mainwindow.ui \
    platforme1.ui \
    dialog2.ui \
    dialogm.ui \
    ajouteretudiant.ui \
    afficheretudiants.ui \
    supprimeretudiant.ui \
    modifieretudiant.ui \
    Matiere_UI/ajoutermatiere.ui \
    Matiere_UI/affichermatieres.ui \
    Matiere_UI/supprimermatiere.ui \
    Matiere_UI/modifiermatiere.ui \
    Professeur_UI/menuprofesseur.ui \
    Professeur_UI/ajouterprofesseur.ui \
    Gestion_UI/gestionetudiants.ui \
    Gestion_UI/noteretudiant.ui \
    Gestion_UI/gestionprofesseurs.ui \
    Gestion_UI/menugestion.ui \
    Gestion_UI/detailsnotes.ui \
    Professeur_UI/supprimerprofesseur.ui \
    Professeur_UI/modifierprofesseur.ui \
    Professeur_UI/afficherprofesseurs.ui \
    Gestion_UI/afficherpaiements.ui \
    Gestion_UI/menugestionprofesseurs.ui

DISTFILES += \
    requetes_sql_projet_cpp
