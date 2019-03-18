#include "menugestion.h"
#include "ui_menugestion.h"
#include "../platforme1.h"

MenuGestion::MenuGestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuGestion)
{
    ui->setupUi(this);
}

MenuGestion::~MenuGestion()
{
    delete ui;
}

void MenuGestion::on_retour_clicked()
{
    hide();
    Platforme1 plf1;
    plf1.setModal(true);
    plf1.exec();
}
