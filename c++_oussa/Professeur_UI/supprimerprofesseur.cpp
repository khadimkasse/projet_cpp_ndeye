#include "supprimerprofesseur.h"
#include "ui_supprimerprofesseur.h"
#include "menuprofesseur.h"
SupprimerProfesseur::SupprimerProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerProfesseur)
{
    ui->setupUi(this);
}

SupprimerProfesseur::~SupprimerProfesseur()
{
    delete ui;
}

void SupprimerProfesseur::on_Retour_clicked()
{
    hide();
    MenuProfesseur menuProfesseur;
    menuProfesseur.setModal(true);
    menuProfesseur.exec();
}
