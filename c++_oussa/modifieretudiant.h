#ifndef MODIFIERETUDIANT_H
#define MODIFIERETUDIANT_H
#include "../sokhna_cpp/Etudiant.h"


#include <QDialog>

namespace Ui {
class ModifierEtudiant;
}

class ModifierEtudiant : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierEtudiant(QWidget *parent = 0);
    ~ModifierEtudiant();

private slots:
    void on_rechercher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ModifierEtudiant *ui;
    Etudiant* etudiant;
};

#endif // MODIFIERETUDIANT_H
