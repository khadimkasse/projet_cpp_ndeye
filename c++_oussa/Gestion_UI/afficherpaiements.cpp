#include "afficherpaiements.h"
#include "ui_afficherpaiements.h"
#include "menugestionprofesseurs.h"
#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>

AfficherPaiements::AfficherPaiements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherPaiements)
{
    ui->setupUi(this);
}

AfficherPaiements::~AfficherPaiements()
{
    delete ui;
}

void AfficherPaiements::on_retour_clicked()
{
    hide();
    MenuGestionProfesseurs menuGestionProfesseurs;
    menuGestionProfesseurs.setModal(true);
    menuGestionProfesseurs.exec();
}

void AfficherPaiements::on_rechercher_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQueryModel* modal=new QSqlQueryModel();
    QString numeroId = ui -> inputIdentification -> text();
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qry->prepare("select * from paiements_professeurs where numero_identification=:num_identification");
        qry->bindValue(":num_identification",numeroId.toInt());
        qry->exec();
        modal -> setQuery(*qry);
        ui->tableView->setModel(modal);
        connectDB.closeConnexion();
    }
}
