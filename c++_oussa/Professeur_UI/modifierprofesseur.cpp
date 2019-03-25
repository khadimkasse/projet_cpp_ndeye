#include "modifierprofesseur.h"
#include "ui_modifierprofesseur.h"
#include "menuprofesseur.h"
#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>

ModifierProfesseur::ModifierProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierProfesseur)
{
    ui->setupUi(this);
}

ModifierProfesseur::~ModifierProfesseur()
{
    delete ui;
}

void ModifierProfesseur::on_retour_clicked()
{
    hide();
    MenuProfesseur menuprofesseur;
    menuprofesseur.setModal(true);
    menuprofesseur.exec();
}

void ModifierProfesseur::on_rechercher_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString numeroId = ui -> inputprofesseur -> text();
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qry->prepare("select * from professeurs where numero_identification=:num_identification");
        qry->bindValue(":num_identification",numeroId.toInt());
        qry->exec();
        qry->next();

        QSqlQuery* qryMatiere = new QSqlQuery(connectDB.getConnexion());
        qryMatiere->prepare("select * from matieres where nom=:newNom");
        qryMatiere->bindValue(":newNom",  qry->value(6).toString());
        qryMatiere->exec();
        qryMatiere->next();

        this -> matiere = new Matiere(qryMatiere->value(0).toString().toStdString(),qryMatiere->value(0).toString().toInt());
        this -> professeur = new Professeur(qry->value(2).toString().toStdString(), qry->value(1).toString().toStdString(),qry->value(0).toInt(),
                                qry->value(4).toString().toStdString(), qry->value(3).toString().toStdString(), qry->value(5).toString().toStdString(),
                                this -> matiere, qry->value(7).toString() == "true");
        ui->inputnom->setText(QString::fromStdString(professeur->getNom()));
        ui->inputprenom->setText(QString::fromStdString(professeur->getPrenom()));
        ui->inputnumbprofesseur->setText(QString::number(professeur->getIdentifiant()));
        ui->inputdatedenaissance->setText(QString::fromStdString(professeur->getDateDeNaissance()));
        ui->inputnumbtelephone->setText(QString::fromStdString(professeur->getNumeroTelephone()));
        ui->inputadresse->setText(QString::fromStdString(professeur->getAdresse()));
        loadComboBox();
        ui->matieres->setCurrentText(QString::fromStdString(professeur->getMatiere()->getNomMatiere()));

    }

    connectDB.closeConnexion();
}

void ModifierProfesseur::loadComboBox() {
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

void ModifierProfesseur::on_modifier_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString numberProf = ui -> inputprofesseur-> text();
    QSqlQuery* qryMatiere = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qryMatiere->prepare("select * from matieres where nom=:newNom");
        qryMatiere->bindValue(":newNom", ui -> matieres -> currentText());
        qryMatiere->exec();
        qryMatiere->next();
    }
    this -> matiere = new Matiere(qryMatiere -> value(0).toString().toStdString(), qryMatiere -> value(1).toInt());
    this -> professeur = new Professeur(ui -> inputprenom -> text().toStdString(), ui -> inputnom -> text().toStdString(),
    ui -> inputnumbprofesseur -> text().toInt(), ui -> inputnumbtelephone -> text().toStdString(), ui -> inputdatedenaissance -> text().toStdString(),
    ui -> inputadresse -> text().toStdString(),this -> matiere, false);
    QSqlQuery qry(connectDB.getConnexion());

    if(connectDB.dbIsOpened()){

    qry.prepare("update professeurs set "
                "numero_identification=:new_numero_identification, nom=:new_nom, prenom=:new_prenom, "
                "date_de_naissance=:new_date_de_naissance, numero_de_telephone=:new_numero_de_telephone, "
                "adresse=:new_adresse, matiere=:new_matiere where numero_identification=:numero_prof");
    qry.bindValue(":numero_prof",numberProf);
    qry.bindValue(":new_numero_identification",professeur->getIdentifiant());
    qry.bindValue(":new_nom", QString::fromStdString(professeur->getNom()));
    qry.bindValue(":new_prenom",QString::fromStdString(professeur->getPrenom()));
    qry.bindValue(":new_date_de_naissance",QString::fromStdString(professeur->getDateDeNaissance()));
    qry.bindValue(":new_numero_de_telephone",QString::fromStdString(professeur->getNumeroTelephone()));
    qry.bindValue(":new_adresse",QString::fromStdString(professeur->getAdresse()));
    qry.bindValue(":new_matiere",QString::fromStdString(professeur->getMatiere() -> getNomMatiere()));
    bool ok2 = qry.exec();

   if(ok2){
        QMessageBox::information(this,"Reussite","Le nouveau professeur a été modifié avec succès");
        connectDB.closeConnexion();
        loadComboBox();
        ui -> inputprenom -> setText("");
        ui -> inputnom -> setText("");
        ui -> inputnumbprofesseur -> setText("");
        ui -> inputnumbtelephone -> setText("");
        ui -> inputdatedenaissance -> setText("");
        ui -> inputadresse -> setText("");
        ui -> inputprofesseur -> setText("");
   }else
      {
        QMessageBox::critical(this,"Erreur","Erreur lors de l'ajout du professeur");
       }
    }
}
