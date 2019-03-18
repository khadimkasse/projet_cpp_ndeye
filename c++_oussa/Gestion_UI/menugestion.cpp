#include "menugestion.h"
#include "ui_menugestion.h"

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
