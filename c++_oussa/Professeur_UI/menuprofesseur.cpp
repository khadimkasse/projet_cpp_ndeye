#include "menuprofesseur.h"
#include "ui_menuprofesseur.h"
#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>

MenuProfesseur::MenuProfesseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuProfesseur)
{
    ui->setupUi(this);
}

MenuProfesseur::~MenuProfesseur()
{
    delete ui;
}

void MenuProfesseur::on_ajoutProfesseur_clicked()
{

}
