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

    void on_suppressionProfesseur_clicked();

    void on_retour_clicked();

    void on_modificationProfesseur_clicked();

    void on_affichageProfesseurs_clicked();

private:
    Ui::MenuProfesseur *ui;
};

#endif // MENUPROFESSEUR_H
