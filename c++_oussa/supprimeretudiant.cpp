#include "supprimeretudiant.h"
#include "ui_supprimeretudiant.h"
#include "connectdb.h"
#include "dialog2.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>

SupprimerEtudiant::SupprimerEtudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerEtudiant)
{
    ui->setupUi(this);
}

SupprimerEtudiant::~SupprimerEtudiant()
{
    delete ui;
}

void SupprimerEtudiant::on_pushButton_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQueryModel* modal=new QSqlQueryModel();
    QString numeroEtudiant = ui -> numeroEtudiant -> text();
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qry->prepare("select * from etudiants where numero_etudiant=:num_etudiant");
        qry->bindValue(":num_etudiant",numeroEtudiant.toInt());
        qry->exec();
        modal -> setQuery(*qry);
        ui->tableView->setModel(modal);
    }

    connectDB.closeConnexion();
}

void SupprimerEtudiant::on_pushButton_2_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString numeroEtudiant = ui -> numeroEtudiant -> text();
    if(connectDB.dbIsOpened()){
        QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
        qry->prepare("delete from etudiants where numero_etudiant=:num_etudiant;");
        qry->bindValue(":num_etudiant",numeroEtudiant.toInt());
        bool queryOK = qry->exec();
        if(queryOK) {
            QMessageBox::information(this, "Suppression", "L'étudiant a bien été supprimé.");
            connectDB.closeConnexion();
        }
    }
    ui->numeroEtudiant->setText("");
    QSqlQueryModel* modal=new QSqlQueryModel();
    ui->tableView->setModel(modal);
}

void SupprimerEtudiant::on_cancel_clicked()
{
    hide();
    Dialog2 dialog2 ;
    dialog2.setModal(true);
    dialog2.exec();
}
