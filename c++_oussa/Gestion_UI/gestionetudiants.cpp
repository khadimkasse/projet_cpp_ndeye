#include "gestionetudiants.h"
#include "ui_gestionetudiants.h"
#include "menugestion.h"
#include "noteretudiant.h"
#include "detailsnotes.h"

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

void GestionEtudiants::on_retour_clicked()
{
    hide();
    MenuGestion menuGestion;
    menuGestion.setModal(true);
    menuGestion.exec();
}

void GestionEtudiants::on_noterEtudiant_clicked()
{
    hide();
    NoterEtudiant noterEtudiant;
    noterEtudiant.setModal(true);
    noterEtudiant.exec();
}

void GestionEtudiants::on_consulterNotes_clicked()
{
    hide();
    DetailsNotes detailsNotes;
    detailsNotes.setModal(true);
    detailsNotes.exec();
}
