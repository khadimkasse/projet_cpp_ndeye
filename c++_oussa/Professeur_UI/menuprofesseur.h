#ifndef MENUPROFESSEUR_H
#define MENUPROFESSEUR_H

#include <QDialog>

namespace Ui {
class MenuProfesseur;
}

class MenuProfesseur : public QDialog
{
    Q_OBJECT

public:
    explicit MenuProfesseur(QWidget *parent = 0);
    ~MenuProfesseur();

private slots:
    void on_ajoutProfesseur_clicked();

private:
    Ui::MenuProfesseur *ui;
};

#endif // MENUPROFESSEUR_H
