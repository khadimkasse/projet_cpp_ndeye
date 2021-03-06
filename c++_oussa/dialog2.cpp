/*Constitue la première page que l'on atteint avant de créer un étudiant ou autre.
Devrait constituer un menu principal permettant d'accéder aux autres pages de l'application. */
#include "dialog2.h"
#include "ui_dialog2.h"
#include "ajouteretudiant.h"
#include "afficheretudiants.h"
#include "supprimeretudiant.h"
#include "modifieretudiant.h"
#include "platforme1.h"
#include <QMessageBox>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
   hide();
   AjouterEtudiant ajouteretud;
   ajouteretud.setModal(true);
   ajouteretud.exec();
}

void Dialog2::on_pushButton_5_clicked()
{
    hide();
    Platforme1 platforme1 ;
    platforme1.setModal(true);
    platforme1.exec();
}

void Dialog2::on_pushButton_3_clicked()
{
    hide();
    ModifierEtudiant modifierEtudiant;
    modifierEtudiant.setModal(true);
    modifierEtudiant.exec();
}

void Dialog2::on_pushButton_4_clicked()
{
    hide();
    AfficherEtudiants afficherEtudiants;
    afficherEtudiants.setModal(true);
    afficherEtudiants.exec();
}

void Dialog2::on_pushButton_2_clicked()
{
    hide();
    SupprimerEtudiant supprimerEtudiant;
    supprimerEtudiant.setModal(true);
    supprimerEtudiant.exec();
}
