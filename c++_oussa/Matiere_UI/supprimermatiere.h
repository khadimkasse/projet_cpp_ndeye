#ifndef SUPPRIMERMATIERE_H
#define SUPPRIMERMATIERE_H
#include "../sokhna_cpp/Matiere.h"

#include <QDialog>

namespace Ui {
class SupprimerMatiere;
}

class SupprimerMatiere : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerMatiere(QWidget *parent = 0);
    ~SupprimerMatiere();
    void loadComboBox();

private slots:
    void on_supprimerMatiere_clicked();

    void on_retour_clicked();

private:
    Ui::SupprimerMatiere *ui;
    Matiere* matiere;
};

#endif // SUPPRIMERMATIERE_H
