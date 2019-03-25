/*Contient, avec sa UI, la logique pour récupérer toutes les informations utiles
à l'ajout d'nu étudaint et les stocke dans la BDD.
Futures évolutions : Cette classe ne sert qu'à récupérer des infos de la UI et
à les insérer dans la BDD. Il faudrait donc le binder dans une classe et faire
toute la logique de sauvegarde avec des classes comme il faut. */
#include "ajouteretudiant.h"
#include "ui_ajouteretudiant.h"
#include "dialog2.h"
#include "connectdb.h"
#include <QMessageBox>
#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlDatabase>

ConnectDB connectDB;


AjouterEtudiant::AjouterEtudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterEtudiant)
{
    ui->setupUi(this);
}

AjouterEtudiant::~AjouterEtudiant()
{
    delete ui;
}


void AjouterEtudiant::on_pushButton_2_clicked()
{
    hide();
    Dialog2 dialog2 ;
    dialog2.setModal(true);
    dialog2.exec();
}

void AjouterEtudiant::on_pushButton_AjouterEtud_clicked()
{
    connectDB.openConnexion();

    this -> etudiantCourant = new Etudiant(ui->lineEditNom->text().toStdString(), ui->lineEditPrenom->text().toStdString(),
            ui->lineEditNumeroEtudiant->text().toInt(),ui->lineEditNumTel->text().toStdString(),
            ui->lineEditDateDeNaissance->text().toStdString(), ui->lineEditAdresse->text().toStdString(),
            ui->lineEditFormation->text().toStdString());

    QSqlQuery qry(connectDB.getConnexion());

    if(connectDB.dbIsOpened()){

    qry.prepare("INSERT INTO etudiants (numero_etudiant, nom, prenom, date_de_naissance, numero_de_telephone, adresse, formation)"
                "VALUES (:newNum_Etudiant,:newNom,:newPrenom,:newDate_de_naissance,:newNum_de_Tel,:newAdresse, :newFormation)");
    qry.bindValue(":newNum_Etudiant",etudiantCourant->getIdentifiant());
    qry.bindValue(":newNom", QString::fromStdString(etudiantCourant->getNom()));
    qry.bindValue(":newPrenom",QString::fromStdString(etudiantCourant->getPrenom()));
    qry.bindValue(":newDate_de_naissance",QString::fromStdString(etudiantCourant->getDateDeNaissance()));
    qry.bindValue(":newNum_de_Tel",QString::fromStdString(etudiantCourant->getNumeroTelephone()));
    qry.bindValue(":newAdresse",QString::fromStdString(etudiantCourant->getAdresse()));
    qry.bindValue(":newFormation",QString::fromStdString(etudiantCourant->getFormation()));
    bool ok2 = qry.exec();

   if(ok2){

    QMessageBox::information(this,"Reussite","Le nouveau étudiant a été ajouté avec succès");
    connectDB.closeConnexion();

   }else
      {
        QMessageBox::critical(this,"Erreur","Erreur lors de l'ajout de l'étudiant");
       }
    }
    ui->lineEditNom->setText("");
    ui->lineEditPrenom->setText("");
    ui->lineEditNumeroEtudiant->setText("");
    ui->lineEditNumTel->setText("");
    ui->lineEditDateDeNaissance->setText("");
    ui->lineEditAdresse->setText("");
    ui->lineEditFormation->setText("");
}
