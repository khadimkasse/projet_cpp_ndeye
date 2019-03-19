#include "menugestion.h"
#include "ui_menugestion.h"
#include "../platforme1.h"
#include "gestionetudiants.h"
#include "gestionprofesseurs.h"

MenuGestion::MenuGestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuGestion)
{
    ui->setupUi(this);
}

MenuGestion::~MenuGestion()
{
    delete ui;
}

void MenuGestion::on_retour_clicked()
{
    hide();
    Platforme1 plf1;
    plf1.setModal(true);
    plf1.exec();
}

void MenuGestion::on_gestioEtudiantsn_clicked()
{
    hide();
    GestionEtudiants gestionEtudiants;
    gestionEtudiants.setModal(true);
    gestionEtudiants.exec();
}

void MenuGestion::on_gestionProfesseurs_clicked()
{
    hide();
    GestionProfesseurs gestionProfesseurs;
    gestionProfesseurs.setModal(true);
    gestionProfesseurs.exec();
}
