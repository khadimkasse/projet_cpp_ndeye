#include "gestionprofesseurs.h"
#include "ui_gestionprofesseurs.h"
#include "menugestionprofesseurs.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include "connectdb.h"
#include <QMessageBox>

GestionProfesseurs::GestionProfesseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionProfesseurs)
{
    ui->setupUi(this);
}

GestionProfesseurs::~GestionProfesseurs()
{
    delete ui;
}

void GestionProfesseurs::on_retour_clicked()
{
    hide();
    MenuGestionProfesseurs menuGestionProfesseurs;
    menuGestionProfesseurs.setModal(true);
    menuGestionProfesseurs.exec();
}

void GestionProfesseurs::on_enregistrer_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("insert into paiements_professeurs(numero_identification, mois, montant) "
                   "values(:new_numero, :new_mois, :new_montant);");
    qry->bindValue(":new_numero", ui -> inputIdentifiant -> text());
    qry->bindValue(":new_mois", ui -> inputMois -> text());
    qry->bindValue(":new_montant", ui -> inputMontant -> text());

    bool okQuery = qry->exec();
    if(okQuery){
         QMessageBox::information(this,"Reussite","Le paiement a été enregistré avec succès");
         connectDB.closeConnexion();
         ui -> inputIdentifiant -> setText("");
         ui -> inputMois -> setText("");
         ui -> inputMontant -> setText("");
    }else
       {
         QMessageBox::critical(this,"Erreur","Erreur lors de l'ajout du paiement.");
        }
}
