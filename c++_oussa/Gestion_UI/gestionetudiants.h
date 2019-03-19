#ifndef GESTIONETUDIANTS_H
#define GESTIONETUDIANTS_H

#include <QDialog>

namespace Ui {
class GestionEtudiants;
}

class GestionEtudiants : public QDialog
{
    Q_OBJECT

public:
    explicit GestionEtudiants(QWidget *parent = 0);
    ~GestionEtudiants();

private slots:

    void on_retour_clicked();

    void on_noterEtudiant_clicked();

    void on_consulterNotes_clicked();

private:
    Ui::GestionEtudiants *ui;
};

#endif // GESTIONETUDIANTS_H
