#include "dialogm.h"
#include "ui_dialogm.h"
#include "platforme1.h"
#include "Matiere_UI/ajoutermatiere.h"
#include "Matiere_UI/affichermatieres.h"
#include "Matiere_UI/supprimermatiere.h"
#include "Matiere_UI/modifiermatiere.h"

DialogM::DialogM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogM)
{
    ui->setupUi(this);
}

DialogM::~DialogM()
{
    delete ui;
}

void DialogM::on_retour_clicked()
{
    hide();
    Platforme1 platforme1 ;
    platforme1.setModal(true);
    platforme1.exec();
}

void DialogM::on_ajouterMatiere_clicked()
{
    hide();
    AjouterMatiere ajouterMatiere;
    ajouterMatiere.setModal(true);
    ajouterMatiere.exec();
}

void DialogM::on_afficherMatieres_clicked()
{
    hide();
    AfficherMatieres afficherMatieres;
    afficherMatieres.setModal(true);
    afficherMatieres.exec();
}

void DialogM::on_supprimerMatiere_clicked()
{
    hide();
    SupprimerMatiere supprimerMatiere;
    supprimerMatiere.setModal(true);
    supprimerMatiere.exec();
}

void DialogM::on_modifierMatiere_clicked()
{
    hide();
    ModifierMatiere modifierMatiere;
    modifierMatiere.setModal(true);
    modifierMatiere.exec();
}
