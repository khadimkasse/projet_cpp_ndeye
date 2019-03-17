#ifndef SUPPRIMERETUDIANT_H
#define SUPPRIMERETUDIANT_H
#include "../sokhna_cpp/Note.h"
#include "../sokhna_cpp/Etudiant.h"
#include "../sokhna_cpp/Personne.h"

#include <QDialog>

namespace Ui {
class SupprimerEtudiant;
}

class SupprimerEtudiant : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerEtudiant(QWidget *parent = 0);
    ~SupprimerEtudiant();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_cancel_clicked();

private:
    Ui::SupprimerEtudiant *ui;
    Etudiant etudiant;
};

#endif // SUPPRIMERETUDIANT_H
