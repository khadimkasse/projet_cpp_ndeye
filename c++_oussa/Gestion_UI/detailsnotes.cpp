#include "detailsnotes.h"
#include "ui_detailsnotes.h"
#include "gestionetudiants.h"
#include "../connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>

DetailsNotes::DetailsNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsNotes)
{
    ui->setupUi(this);
}

DetailsNotes::~DetailsNotes()
{
    delete ui;
}

void DetailsNotes::on_retour_clicked()
{
    hide();
    GestionEtudiants gestionsEtudiants;
    gestionsEtudiants.setModal(true);
    gestionsEtudiants.exec();
}

void DetailsNotes::on_rechercheEtudiants_clicked()
{
    ConnectDB connectDB;
    QSqlQueryModel* modal=new QSqlQueryModel();
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("select notes.numero_etudiant, matieres.nom,"
                   " matieres.coefficient, notes.note from "
                   "notes INNER JOIN matieres "
                   "ON notes.nom_matiere=matieres.nom where "
                   "notes.numero_etudiant=:newNumeroEtudiant order by matieres.nom;");
    qry -> bindValue(":newNumeroEtudiant", ui -> numeroEtudiant -> text().toInt());
    qry->exec();
    modal -> setQuery(*qry);
    ui-> tableauAffichage ->setModel(modal);
    connectDB.closeConnexion();
}
