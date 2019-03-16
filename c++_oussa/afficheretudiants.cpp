#include "afficheretudiants.h"
#include "ui_afficheretudiants.h"
#include "dialog2.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include "connectdb.h"

AfficherEtudiants::AfficherEtudiants(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherEtudiants)
{
     ui->setupUi(this);
    ConnectDB connectDB;
    QSqlQueryModel* modal=new QSqlQueryModel();
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("select * from etudiants;");
    qry->exec();
    modal -> setQuery(*qry);
    ui->tableView->setModel(modal);
    connectDB.closeConnexion();
}

AfficherEtudiants::~AfficherEtudiants()
{
    delete ui;
}

void AfficherEtudiants::on_cancel_clicked()
{
    hide();
    Dialog2 dialog2 ;
    dialog2.setModal(true);
    dialog2.exec();
}
