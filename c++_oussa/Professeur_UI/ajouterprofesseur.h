#ifndef AJOUTERPROFESSEUR_H
#define AJOUTERPROFESSEUR_H
#include "../../sokhna_cpp/Professeur.h"

#include <QDialog>

namespace Ui {
class AjouterProfesseur;
}

class AjouterProfesseur : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterProfesseur(QWidget *parent = 0);
    ~AjouterProfesseur();
    void loadComboBox();

private slots:
    void on_retour_clicked();

    void on_ajouter_clicked();

private:
    Ui::AjouterProfesseur *ui;
    Matiere* matiere;
    Professeur* professeur;
};

#endif // AJOUTERPROFESSEUR_H
