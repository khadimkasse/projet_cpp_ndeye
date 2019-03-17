#include "supprimermatiere.h"
#include "ui_supprimermatiere.h"
#include "../dialogm.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "../connectdb.h"

SupprimerMatiere::SupprimerMatiere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerMatiere)
{
    ui->setupUi(this);
    loadComboBox();

}

void SupprimerMatiere::loadComboBox() {
    ui -> matieres -> clear();
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("select * from matieres order by nom;");
    qry->exec();
    int i = 0;
    while(qry->next()) {
        this -> matiere = new Matiere(qry -> value(0).toString().toStdString(), qry -> value(1).toInt());
        ui -> matieres -> addItem(QString::fromStdString(matiere->getNomMatiere()), i);
        i = i+1 ;
        delete matiere;
    }
}

SupprimerMatiere::~SupprimerMatiere()
{
    delete ui;
}

void SupprimerMatiere::on_supprimerMatiere_clicked() {
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString toDelete = ui -> matieres -> currentText();
    if(connectDB.dbIsOpened()){
        QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
        qry->prepare("delete from matieres where nom=:nomMatiere;");
        qry->bindValue(":nomMatiere", toDelete);
        bool queryOK = qry->exec();
        if(queryOK) {
            QMessageBox::information(this, "Suppression", "La matière -" + toDelete + " a bien été supprimé.");
            connectDB.closeConnexion();
            loadComboBox();
        } else {
            QMessageBox::critical(this,"Erreur","Une erreur s'est produite lors de la suppression des matières.");
        }
    }
}

void SupprimerMatiere::on_retour_clicked()
{
    hide();
    DialogM dialogm ;
    dialogm.setModal(true);
    dialogm.exec();
}
