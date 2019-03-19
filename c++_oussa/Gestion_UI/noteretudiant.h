#ifndef NOTERETUDIANT_H
#define NOTERETUDIANT_H
#include "../../sokhna_cpp/Matiere.h"
#include "../../sokhna_cpp/Note.h"

#include <QDialog>

namespace Ui {
class NoterEtudiant;
}

class NoterEtudiant : public QDialog
{
    Q_OBJECT

public:
    explicit NoterEtudiant(QWidget *parent = 0);
    void loadComboBox();
    ~NoterEtudiant();

private slots:
    void on_retour_clicked();

    void on_enregistrerNote_clicked();

private:
    Ui::NoterEtudiant *ui;
    Matiere* matiere;
    Note* note;
};

#endif // NOTERETUDIANT_H
