/*Contitue la première vue sur 
laquelle on a le choix d'aller vers les espaces étudiant ou matière. */
#include "platforme1.h"
#include "ui_platforme1.h"
#include"dialog2.h"
#include "dialogm.h"
#include "Professeur_UI/menuprofesseur.h"

Platforme1::Platforme1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Platforme1)
{
    ui->setupUi(this);
}

Platforme1::~Platforme1()
{
    delete ui;
}

void Platforme1::on_pushButton_clicked()
{
    hide();
    Dialog2 dialog2;
    dialog2.setModal(true);
    dialog2.exec();


}

void Platforme1::on_pushButton_4_clicked()
{
    hide();
    DialogM dialogm;
    dialogm.setModal(true);
    dialogm.exec();


}

void Platforme1::on_espaceProfesseur_clicked()
{
    hide();
    MenuProfesseur menuProfesseur;
    menuProfesseur.setModal(true);
    menuProfesseur.exec()
}
