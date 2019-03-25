#include "supprimerprofesseur.h"
#include "ui_supprimerprofesseur.h"
#include "menuprofesseur.h"
#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>
SupprimerProfesseur::SupprimerProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerProfesseur)
{
    ui->setupUi(this);
}

SupprimerProfesseur::~SupprimerProfesseur()
{
    delete ui;
}

void SupprimerProfesseur::on_Retour_clicked()
{
    hide();
    MenuProfesseur menuProfesseur;
    menuProfesseur.setModal(true);
    menuProfesseur.exec();
}

void SupprimerProfesseur::on_Rechercher_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQueryModel* modal=new QSqlQueryModel();
    QString numeroId = ui -> inputNumero -> text();
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qry->prepare("select * from professeurs where numero_identification=:num_identification");
        qry->bindValue(":num_identification",numeroId.toInt());
        qry->exec();
        modal -> setQuery(*qry);
        ui->tableView->setModel(modal);
        connectDB.closeConnexion();
    }
}

void SupprimerProfesseur::on_supprimer_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString numeroId = ui -> inputNumero -> text();
    if(connectDB.dbIsOpened()){
        QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
        qry->prepare("delete from professeurs where numero_identification=:num_identification;");
        qry->bindValue(":num_identification",numeroId.toInt());
        bool queryOK = qry->exec();
        if(queryOK) {
            QMessageBox::information(this, "Suppression", "Le professeur a bien été supprimé.");
            connectDB.closeConnexion();
        }
    }
    ui->inputNumero->setText("");
    QSqlQueryModel* modal=new QSqlQueryModel();
    ui->tableView->setModel(modal);
}
