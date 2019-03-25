#ifndef MODIFIERPROFESSEUR_H
#define MODIFIERPROFESSEUR_H
#include "../../sokhna_cpp/Professeur.h"
#include "../../sokhna_cpp/Matiere.h"


#include <QDialog>

namespace Ui {
class ModifierProfesseur;
}

class ModifierProfesseur : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierProfesseur(QWidget *parent = 0);
    ~ModifierProfesseur();
    void loadComboBox();

private slots:
    void on_retour_clicked();

    void on_rechercher_clicked();

    void on_modifier_clicked();

private:
    Ui::ModifierProfesseur *ui;
    Professeur* professeur;
    Matiere* matiere;
};

#endif // MODIFIERPROFESSEUR_H
