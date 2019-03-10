/*Contient, avec sa UI, la logique pour récupérer toutes les informations utiles
à l'ajout d'nu étudaint et les stocke dans la BDD.
Futures évolutions : Cette classe ne sert qu'à récupérer des infos de la UI et
à les insérer dans la BDD. Il faudrait donc le binder dans une classe et faire
toute la logique de sauvegarde avec des classes comme il faut. */
#include "ajouteretudiant.h"
#include "ui_ajouteretudiant.h"
#include "dialog2.h"
#include <QMessageBox>
#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlDatabase>

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

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
{   db.setHostName("localhost");
    db.setDatabaseName("bdd_projet_cpp");
    db.setUserName("user_projet_cpp");
    db.setPassword("Sokhna");
    db.open();

    QString Nom,Prenom,Num_Etudiant,Date_de_naissance,Num_de_Tel,Adresse;
    Nom=ui->lineEditNom->text();
    Prenom=ui->lineEditPrenom->text();
    Num_Etudiant=ui->lineEditNumeroEtudiant->text();
    Date_de_naissance =ui->lineEditDateDeNaissance->text();
    Num_de_Tel=ui->lineEditNumTel->text();
    Adresse=ui->lineEditAdresse->text();

    QSqlQuery qry(db);
    QString Etudiant;


    if(db.open()){

    qry.prepare("INSERT INTO etudiants (numero_etudiant, nom, prenom, date_de_naissance, numero_de_telephone, adresse)"
                "VALUES (:newNum_Etudiant,:newNom,:newPrenom,:newDate_de_naissance,:newNum_de_Tel,:newAdresse)");
    qry.bindValue(":newNum_Etudiant",Num_Etudiant);
    qry.bindValue(":newNom", Nom);
    qry.bindValue(":newPrenom",Prenom);
    qry.bindValue(":newDate_de_naissance",Date_de_naissance);
    qry.bindValue(":newNum_de_Tel",Num_de_Tel);
    qry.bindValue(":newAdresse",Adresse);
    bool ok2 = qry.exec();

   if(ok2){

    QMessageBox::information(this,"Reussite","Le nouveau étudiant a été ajouté avec succès");
    db.close();
    this->close();

   }else
      {
        QMessageBox::critical(this,"Erreur","Erreur lors de l'ajout de l'étudiant");
       }
    }
}
