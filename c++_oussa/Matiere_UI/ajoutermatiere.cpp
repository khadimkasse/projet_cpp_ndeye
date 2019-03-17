#include "ajoutermatiere.h"
#include "ui_ajoutermatiere.h"
#include "../dialogm.h"
#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>

AjouterMatiere::AjouterMatiere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterMatiere)
{
    ui->setupUi(this);
}

AjouterMatiere::~AjouterMatiere()
{
    delete ui;
}

void AjouterMatiere::on_cancel_clicked()
{
    hide();
    DialogM dialogm ;
    dialogm.setModal(true);
    dialogm.exec();
}

void AjouterMatiere::on_ajouterMatiere_clicked() {
    ConnectDB connectDB;
    connectDB.openConnexion();
    this -> matiere = new Matiere(ui -> nomMatiere ->text().toStdString(),(ui -> coefficient ->text().toInt()));
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qry->prepare("INSERT INTO matieres (nom, coefficient) "
                    "VALUES (:newNomMatiere,:newCoefficient);");
        qry->bindValue(":newNomMatiere",  QString::fromStdString(matiere->getNomMatiere()));
        qry->bindValue(":newCoefficient", matiere->getCoefficient());
        bool queryOK = qry->exec();
        if(queryOK) {
            QMessageBox::information(this,"Reussite","La matière a été rajoutée avec succès.");
            connectDB.closeConnexion();
        } else{
            QMessageBox::critical(this,"Erreur","Erreur lors de l'ajout de la matière.");
        }
    }
    ui->nomMatiere ->setText("");
    ui->coefficient ->setText("");
}
