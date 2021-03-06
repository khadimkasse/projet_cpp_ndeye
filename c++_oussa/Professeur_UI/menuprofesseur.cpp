#include "menuprofesseur.h"
#include "ui_menuprofesseur.h"
#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "ajouterprofesseur.h"
#include "supprimerprofesseur.h"
#include "../platforme1.h"
#include "modifierprofesseur.h"
#include "afficherprofesseurs.h"
MenuProfesseur::MenuProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuProfesseur)
{
    ui->setupUi(this);
}

MenuProfesseur::~MenuProfesseur()
{
    delete ui;
}

void MenuProfesseur::on_ajoutProfesseur_clicked()
{
    hide();
    AjouterProfesseur ajouterprofesseur ;
    ajouterprofesseur.setModal(true);
    ajouterprofesseur.exec();
}

void MenuProfesseur::on_suppressionProfesseur_clicked()
{
    hide();
    SupprimerProfesseur supprimerprofesseur;
    supprimerprofesseur.setModal(true);
    supprimerprofesseur.exec();
}

void MenuProfesseur::on_retour_clicked()
{
    hide();
    Platforme1 platforme1;
    platforme1.setModal(true);
    platforme1.exec();

}

void MenuProfesseur::on_modificationProfesseur_clicked()
{
    hide();
    ModifierProfesseur modifierProfesseur;
    modifierProfesseur.setModal(true);
    modifierProfesseur.exec();
}

void MenuProfesseur::on_affichageProfesseurs_clicked()
{
    hide();
    AfficherProfesseurs afficherProfesseurs;
    afficherProfesseurs.setModal(true);
    afficherProfesseurs.exec();
}
