#ifndef MODIFIERMATIERE_H
#define MODIFIERMATIERE_H
#include "../../sokhna_cpp/Matiere.h"

#include <QDialog>

namespace Ui {
class ModifierMatiere;
}

class ModifierMatiere : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierMatiere(QWidget *parent = 0);
    ~ModifierMatiere();
    void loadComboBox();

private slots:
    void on_cancel_clicked();

    void on_matieres_currentIndexChanged(const QString &arg1);

    void on_save_clicked();

private:
    Ui::ModifierMatiere *ui;
    Matiere* matiere;
};

#endif // MODIFIERMATIERE_H
