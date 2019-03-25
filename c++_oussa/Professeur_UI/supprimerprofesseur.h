#ifndef SUPPRIMERPROFESSEUR_H
#define SUPPRIMERPROFESSEUR_H

#include <QDialog>

namespace Ui {
class SupprimerProfesseur;
}

class SupprimerProfesseur : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerProfesseur(QWidget *parent = 0);
    ~SupprimerProfesseur();

private slots:

    void on_Retour_clicked();

    void on_Rechercher_clicked();

    void on_supprimer_clicked();

private:
    Ui::SupprimerProfesseur *ui;
};

#endif // SUPPRIMERPROFESSEUR_H
