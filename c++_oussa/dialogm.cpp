#include "dialogm.h"
#include "ui_dialogm.h"
#include "platforme1.h"
#include "Matiere_UI/ajoutermatiere.h"

DialogM::DialogM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogM)
{
    ui->setupUi(this);
}

DialogM::~DialogM()
{
    delete ui;
}

void DialogM::on_retour_clicked()
{
    hide();
    Platforme1 platforme1 ;
    platforme1.setModal(true);
    platforme1.exec();
}

void DialogM::on_ajouterMatiere_clicked()
{
    hide();
    AjouterMatiere ajouterMatiere;
    ajouterMatiere.setModal(true);
    ajouterMatiere.exec();
}
