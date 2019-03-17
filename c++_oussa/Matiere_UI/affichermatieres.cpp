#include "affichermatieres.h"
#include "ui_affichermatieres.h"
#include "../dialogm.h"
#include "../connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>

AfficherMatieres::AfficherMatieres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherMatieres)
{
    ui->setupUi(this);
    ConnectDB connectDB;
    QSqlQueryModel* modal=new QSqlQueryModel();
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("select * from matieres order by nom;");
    bool queryOK = qry->exec();
    if(queryOK) {
        modal -> setQuery(*qry);
        ui->tableView->setModel(modal);
    } else {
        QMessageBox::critical(this,"Erreur","Une erreur s'est produite lors de l'affichage des matières.");
    }
    connectDB.closeConnexion();
}

AfficherMatieres::~AfficherMatieres()
{
    delete ui;
}

void AfficherMatieres::on_retour_clicked()
{
    hide();
    DialogM dialogm ;
    dialogm.setModal(true);
    dialogm.exec();
}
