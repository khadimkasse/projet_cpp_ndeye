#include "modifierprofesseur.h"
#include "ui_modifierprofesseur.h"
#include "menuprofesseur.h"
ModifierProfesseur::ModifierProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierProfesseur)
{
    ui->setupUi(this);
}

ModifierProfesseur::~ModifierProfesseur()
{
    delete ui;
}

void ModifierProfesseur::on_retour_clicked()
{
    hide();
    MenuProfesseur menuprofesseur;
    menuprofesseur.setModal(true);
    menuprofesseur.exec();
}
