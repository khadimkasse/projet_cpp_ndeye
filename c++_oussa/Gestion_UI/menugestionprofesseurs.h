#ifndef MENUGESTIONPROFESSEURS_H
#define MENUGESTIONPROFESSEURS_H

#include <QDialog>

namespace Ui {
class MenuGestionProfesseurs;
}

class MenuGestionProfesseurs : public QDialog
{
    Q_OBJECT

public:
    explicit MenuGestionProfesseurs(QWidget *parent = 0);
    ~MenuGestionProfesseurs();

private slots:
    void on_retour_clicked();

    void on_payerProfesseur_clicked();

    void on_afficherPaiements_clicked();

private:
    Ui::MenuGestionProfesseurs *ui;
};

#endif // MENUGESTIONPROFESSEURS_H
