#include "afficherprofesseurs.h"
#include "ui_afficherprofesseurs.h"
#include "menuprofesseur.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include "connectdb.h"

AfficherProfesseurs::AfficherProfesseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherProfesseurs)
{
    ui->setupUi(this);
    ConnectDB connectDB;
    QSqlQueryModel* modal=new QSqlQueryModel();
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("select * from professeurs order by numero_identification;");
    qry->exec();
    modal -> setQuery(*qry);
    ui->tableView->setModel(modal);
    connectDB.closeConnexion();
}

AfficherProfesseurs::~AfficherProfesseurs()
{
    delete ui;
}

void AfficherProfesseurs::on_retour_clicked()
{
    hide();
    MenuProfesseur menuProfesseur;
    menuProfesseur.setModal(true);
    menuProfesseur.exec();
}
