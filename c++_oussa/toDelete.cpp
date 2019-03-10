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
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setConnectOptions("UNIX_SOCKET=/Applications/MAMP/tmp/mysql/mysql.sock");
    db.setHostName("localhost:8889");
    db.setDatabaseName("ProjetC++");
    db.setUserName("Oussama");
    db.setPassword("Sokhna");
    //db.setPort(8889);
    bool ok1 = db.open();

    QString Nom,Prénom,Num_Etudiant,Date_de_naissance,Num_de_Tél,Adresse;
    Nom=ui->txt_nom->text();
    Prénom=ui->txt_prenom->text();
    Num_Etudiant=ui->txt_Netud->text();
    Date_de_naissance =ui->txt_Datenaiss->text();
    Num_de_Tél=ui->txt_NTel->text();
    Adresse=ui->txt_Adresse->text();

    QSqlQuery qry(db);
    QString Etudiant;


    if(db.open()){

    qry.prepare("INSERT INTO Etudiant (Nom,Prénom,Num_Etudiant,Date_de_naissance,Num_de_Tél,Adresse)"
                "VALUES (:newNom,:newPrénom,:newNum_Etudiant,:newDate_de_naissance,:newNum_de_Tél,:newAdresse)");
    qry.bindValue(":newNom",Nom);
    qry.bindValue(":newPrénom",Prénom);
    qry.bindValue(":newNum_Etudiant",Num_Etudiant);
    qry.bindValue(":newDate_de_naissance",Date_de_naissance);
    qry.bindValue(":newNum_de_Tél",Num_de_Tél);
    qry.bindValue(":newAdresse",Adresse);
    qry.exec();

   if(qry.exec()){

    QMessageBox::information(this,"Reussite","Le nouveau étudiant a été ajouté avec succès");
    db.close();
    this->close();

   }else
      {
        QMessageBox::critical(this,"Erreur","Erreur lors de l'ajout de l'étudiant");
       }
    }
}
