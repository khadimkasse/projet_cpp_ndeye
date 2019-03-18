#include "noteretudiant.h"
#include "ui_noteretudiant.h"

NoterEtudiant::NoterEtudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoterEtudiant)
{
    ui->setupUi(this);
}

NoterEtudiant::~NoterEtudiant()
{
    delete ui;
}
