#include "modifiermatiere.h"
#include "ui_modifiermatiere.h"
#include "../dialogm.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "../connectdb.h"

ModifierMatiere::ModifierMatiere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierMatiere)
{
    ui->setupUi(this);
    loadComboBox();
}

void ModifierMatiere::loadComboBox() {
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

ModifierMatiere::~ModifierMatiere()
{
    delete ui;
}

void ModifierMatiere::on_cancel_clicked()
{
    hide();
    DialogM dialogm ;
    dialogm.setModal(true);
    dialogm.exec();
}

void ModifierMatiere::on_matieres_currentIndexChanged(const QString &arg1)
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString toModify = ui -> matieres -> currentText();
    if(connectDB.dbIsOpened()){
        QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
        qry->prepare("select * from matieres where nom=:nomMatiere;");
        qry->bindValue(":nomMatiere", toModify );
        bool queryOK = qry->exec();
        if(queryOK) {
           while(qry->next()) {
                this -> matiere = new Matiere(qry -> value(0).toString().toStdString(), qry -> value(1).toInt());
                ui -> nouveauNom -> setText(QString::fromStdString(matiere->getNomMatiere()));
                ui -> nouveauCoefficient -> setText(QString::number(matiere->getCoefficient()));
            }
            //delete matiere;
            connectDB.closeConnexion();
        } else {
            QMessageBox::critical(this,"Erreur","Une erreur s'est produite lors de la modification de la matière.");
        }
    }
}

void ModifierMatiere::on_save_clicked()
{
    ConnectDB connectDB;
    connectDB.openConnexion();
    QString toModify = ui -> matieres -> currentText();
    this -> matiere = new Matiere(ui -> nouveauNom -> text().toStdString(), ui -> nouveauCoefficient -> text().toInt());
    QSqlQuery* qry = new QSqlQuery(connectDB.getConnexion());
    if(connectDB.dbIsOpened()){
        qry->prepare("update matieres set "
                     "nom=:new_nom, coefficient=:new_coefficient "
                     "where nom=:toModify");
        qry->bindValue(":new_nom", QString::fromStdString(matiere -> getNomMatiere()));
        qry->bindValue(":new_coefficient",QString::number(matiere->getCoefficient()));
        qry->bindValue(":toModify", toModify);
        bool queryOK = qry->exec();
        if(queryOK) {
            connectDB.closeConnexion();
            QMessageBox::information(this, "Modification", "Les informations de la matière ont bien été modifiés.");
        } else {
            QMessageBox::critical(this,"Erreur","Une erreur s'est produite lors de la modification de la matière.");
        }
    }
    ui -> nouveauNom -> setText("");
    ui -> nouveauCoefficient -> setText("");
    loadComboBox();
}
