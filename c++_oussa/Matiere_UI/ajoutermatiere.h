#ifndef AJOUTERMATIERE_H
#define AJOUTERMATIERE_H
#include "../../sokhna_cpp/Matiere.h"

#include <QDialog>

namespace Ui {
class AjouterMatiere;
}

class AjouterMatiere : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterMatiere(QWidget *parent = 0);
    ~AjouterMatiere();

private slots:

    void on_cancel_clicked();

    void on_ajouterMatiere_clicked();

private:
    Ui::AjouterMatiere *ui;
    Matiere * matiere;
};

#endif // AJOUTERMATIERE_H
