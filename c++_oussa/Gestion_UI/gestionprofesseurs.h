#ifndef GESTIONPROFESSEURS_H
#define GESTIONPROFESSEURS_H

#include <QDialog>

namespace Ui {
class GestionProfesseurs;
}

class GestionProfesseurs : public QDialog
{
    Q_OBJECT

public:
    explicit GestionProfesseurs(QWidget *parent = 0);
    ~GestionProfesseurs();

private slots:
    void on_retour_clicked();

    void on_enregistrer_clicked();

private:
    Ui::GestionProfesseurs *ui;
};

#endif // GESTIONPROFESSEURS_H
