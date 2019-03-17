#include "modifieretudiant.h"
#include "ui_modifieretudiant.h"
#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include "../sokhna_cpp/Etudiant.h"
#include "../sokhna_cpp/Personne.h"
#include "dialog2.h"
#include "../sokhna_cpp/Note.h"
#include <QMessageBox>



ModifierEtudiant::ModifierEtudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierEtudiant)
{
    ui->setupUi(this);
}

ModifierEtudiant::~ModifierEtudiant()
{
    delete ui;
}

void ModifierEtudiant::on_rechercher_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString numeroEtudiant = ui -> dernierNumeroEtudiant -> text();
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qry->prepare("select * from etudiants where numero_etudiant=:num_etudiant");
        qry->bindValue(":num_etudiant",numeroEtudiant.toInt());
        qry->exec();
        while(qry->next()) {
            this -> etudiant = new Etudiant(qry->value(2).toString().toStdString(), qry->value(1).toString().toStdString(),qry->value(0).toInt(),
                                    qry->value(4).toString().toStdString(), qry->value(3).toString().toStdString(), qry->value(5).toString().toStdString(),
                                    qry->value(6).toString().toStdString());
            ui->nom->setText(QString::fromStdString(etudiant->getNom()));
            ui->prenom->setText(QString::fromStdString(etudiant->getPrenom()));
            ui->noEtudiant->setText(QString::number(etudiant->getIdentifiant()));
            ui->dateDeNaissance->setText(QString::fromStdString(etudiant->getDateDeNaissance()));
            ui->noTelephone->setText(QString::fromStdString(etudiant->getNumeroTelephone()));
            ui->adresse->setText(QString::fromStdString(etudiant->getAdresse()));
            ui->formation->setText(QString::fromStdString(etudiant->getFormation()));
        }
    }

    connectDB.closeConnexion();
}

void ModifierEtudiant::on_pushButton_clicked()
{
    hide();
    Dialog2 dialog2 ;
    dialog2.setModal(true);
    dialog2.exec();
}

void ModifierEtudiant::on_pushButton_2_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString numeroEtudiant = ui -> dernierNumeroEtudiant -> text();
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    etudiant -> updateInfos(ui -> prenom -> text().toStdString(), ui -> nom -> text().toStdString(),  ui -> noEtudiant -> text().toInt(),
                             ui -> noTelephone -> text().toStdString(),  ui -> dateDeNaissance -> text().toStdString(),  ui -> adresse -> text().toStdString(),
                             ui -> formation -> text().toStdString());
    if(connectDB.dbIsOpened()){
        qry->prepare("update etudiants set "
                     "numero_etudiant=:new_numero_etudiant, nom=:new_nom, prenom=:new_prenom, "
                     "date_de_naissance=:new_date_de_naissance, numero_de_telephone=:new_numero_de_telephone, "
                     "adresse=:new_adresse, formation=:new_formation where numero_etudiant=:numero_etudiant");
        qry->bindValue(":numero_etudiant",numeroEtudiant);
        qry->bindValue(":new_numero_etudiant",QString::number(this -> etudiant->getIdentifiant()));
        qry->bindValue(":new_nom",QString::fromStdString(this -> etudiant->getNom()));
        qry->bindValue(":new_prenom",QString::fromStdString(this -> etudiant->getPrenom()));
        qry->bindValue(":new_date_de_naissance",QString::fromStdString( this -> etudiant->getDateDeNaissance()));
        qry->bindValue(":new_numero_de_telephone",QString::fromStdString(this -> etudiant->getNumeroTelephone()));
        qry->bindValue(":new_adresse",QString::fromStdString(this -> etudiant->getAdresse()));
        qry->bindValue(":new_formation",QString::fromStdString(this -> etudiant->getFormation()));
        bool queryOK = qry->exec();
        if(queryOK) {
            connectDB.closeConnexion();
            QMessageBox::information(this, "Modification", "Les informations de l'étudiant ont bien été modifiés.");
        }
    }
    ui->dernierNumeroEtudiant ->setText("");
    ui->nom->setText("");
    ui->prenom->setText("");
    ui->noEtudiant->setText("");
    ui->dateDeNaissance->setText("");
    ui->noTelephone->setText("");
    ui->adresse->setText("");
    ui->formation->setText("");
}
