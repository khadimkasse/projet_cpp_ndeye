#include "dialogm.h"
#include "ui_dialogm.h"
#include "platforme1.h"

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

void DialogM::on_pushButton_4_clicked()
{
    hide();
    Platforme1 platforme1 ;
    platforme1.setModal(true);
    platforme1.exec();
}
