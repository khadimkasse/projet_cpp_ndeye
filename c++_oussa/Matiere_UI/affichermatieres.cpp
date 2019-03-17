#include "affichermatieres.h"
#include "ui_affichermatieres.h"
#include "../dialogm.h"

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
    qry->exec();
    modal -> setQuery(*qry);
    ui->tableView->setModel(modal);
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
