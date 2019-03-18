#include "gestionprofesseurs.h"
#include "ui_gestionprofesseurs.h"

GestionProfesseurs::GestionProfesseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionProfesseurs)
{
    ui->setupUi(this);
}

GestionProfesseurs::~GestionProfesseurs()
{
    delete ui;
}
