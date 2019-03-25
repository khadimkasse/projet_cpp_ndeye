#include "ajouterprofesseur.h"
#include "ui_ajouterprofesseur.h"
#include "menuprofesseur.h"
#include "../../sokhna_cpp/Matiere.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "../connectdb.h"

AjouterProfesseur::AjouterProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterProfesseur)
{
    ui->setupUi(this);
    loadComboBox();

}

void AjouterProfesseur::loadComboBox() {
    ui -> matieres -> clear();
    ui -> matieres ->blockSignals(true);
    ui -> matieres -> addItem("-", 0);
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("select * from matieres order by nom;");
    qry->exec();
    int i = 1;
    while(qry->next()) {
        this -> matiere = new Matiere(qry -> value(0).toString().toStdString(), qry -> value(1).toInt());
        ui -> matieres -> addItem(QString::fromStdString(matiere->getNomMatiere()), i);
        i = i+1 ;
        delete matiere;
    }
    ui -> matieres ->blockSignals(false);
}

AjouterProfesseur::~AjouterProfesseur()
{
    delete ui;
}

void AjouterProfesseur::on_retour_clicked()
{
    hide();
    MenuProfesseur menuPreofesseur;
    menuPreofesseur.setModal(true);
    menuPreofesseur.exec();
}

void AjouterProfesseur::on_ajouter_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQuery* qryMatiere = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qryMatiere->prepare("select * from matieres where nom=:newNom");
        qryMatiere->bindValue(":newNom", ui -> matieres -> currentText());
        qryMatiere->exec();
        qryMatiere->next();
    }
    this -> matiere = new Matiere(qryMatiere -> value(0).toString().toStdString(), qryMatiere -> value(1).toInt());
    this -> professeur = new Professeur(ui -> inputPrenom -> text().toStdString(), ui -> inputNom -> text().toStdString(),
    ui -> inputnumbprofesseur -> text().toInt(), ui -> inputnumbtelephone -> text().toStdString(), ui -> inputdatedenaissance -> text().toStdString(),
    ui -> inputadresse -> text().toStdString(),this -> matiere, false);
    QSqlQuery qry(connectDB.getConnexion());

    if(connectDB.dbIsOpened()){

    qry.prepare("INSERT INTO professeurs (numero_identification, nom, prenom, date_de_naissance, numero_de_telephone, adresse, matiere)"
                "VALUES (:newNum_identification,:newNom,:newPrenom,:newDate_de_naissance,:newNum_de_Tel,:newAdresse, :newMatiere)");
    qry.bindValue(":newNum_identification",professeur->getIdentifiant());
    qry.bindValue(":newNom", QString::fromStdString(professeur->getNom()));
    qry.bindValue(":newPrenom",QString::fromStdString(professeur->getPrenom()));
    qry.bindValue(":newDate_de_naissance",QString::fromStdString(professeur->getDateDeNaissance()));
    qry.bindValue(":newNum_de_Tel",QString::fromStdString(professeur->getNumeroTelephone()));
    qry.bindValue(":newAdresse",QString::fromStdString(professeur->getAdresse()));
    qry.bindValue(":newMatiere",QString::fromStdString(professeur->getMatiere() -> getNomMatiere()));
    bool ok2 = qry.exec();

   if(ok2){
        QMessageBox::information(this,"Reussite","Le nouveau professeur a été ajouté avec succès");
        connectDB.closeConnexion();
        loadComboBox();
        ui -> inputPrenom -> setText("");
        ui -> inputNom -> setText("");
        ui -> inputnumbprofesseur -> setText("");
        ui -> inputnumbtelephone -> setText("");
        ui -> inputdatedenaissance -> setText("");
        ui -> inputadresse -> setText("");
   }else
      {
        QMessageBox::critical(this,"Erreur","Erreur lors de l'ajout du professeur");
       }
    }

}
