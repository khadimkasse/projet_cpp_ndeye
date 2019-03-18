#include "gestionetudiants.h"
#include "ui_gestionetudiants.h"

GestionEtudiants::GestionEtudiants(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionEtudiants)
{
    ui->setupUi(this);
}

GestionEtudiants::~GestionEtudiants()
{
    delete ui;
}
