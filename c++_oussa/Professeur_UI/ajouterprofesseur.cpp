#include "ajouterprofesseur.h"
#include "ui_ajouterprofesseur.h"
#include "menuprofesseur.h"

AjouterProfesseur::AjouterProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterProfesseur)
{
    ui->setupUi(this);
}

AjouterProfesseur::~AjouterProfesseur()
{
    delete ui;
}

void AjouterProfesseur::on_retour_clicked()
{
    hide();
    MenuProfesseur menuPreofesseur;
    menuPreofesseur.setModal(true);
    menuPreofesseur.exec();
}

void AjouterProfesseur::on_ajouter_clicked()
{

}
