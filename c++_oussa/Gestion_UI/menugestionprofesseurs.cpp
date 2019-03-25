#include "menugestionprofesseurs.h"
#include "ui_menugestionprofesseurs.h"
#include "menugestion.h"
#include "gestionprofesseurs.h"
#include "afficherpaiements.h"

MenuGestionProfesseurs::MenuGestionProfesseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuGestionProfesseurs)
{
    ui->setupUi(this);
}

MenuGestionProfesseurs::~MenuGestionProfesseurs()
{
    delete ui;
}

void MenuGestionProfesseurs::on_retour_clicked()
{
    hide();
    MenuGestion menuGestion;
    menuGestion.setModal(true);
    menuGestion.exec();
}

void MenuGestionProfesseurs::on_payerProfesseur_clicked()
{
    hide();
    GestionProfesseurs gestionProfesseurs;
    gestionProfesseurs.setModal(true);
    gestionProfesseurs.exec();
}

void MenuGestionProfesseurs::on_afficherPaiements_clicked()
{
    hide();
    AfficherPaiements afficherPaiements;
    afficherPaiements.setModal(true);
    afficherPaiements.exec();
}
