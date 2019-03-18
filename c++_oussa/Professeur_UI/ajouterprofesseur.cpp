#include "ajouterprofesseur.h"
#include "ui_ajouterprofesseur.h"

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
