#ifndef MODIFIERPROFESSEUR_H
#define MODIFIERPROFESSEUR_H

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

private slots:
    void on_retour_clicked();

private:
    Ui::ModifierProfesseur *ui;
};

#endif // MODIFIERPROFESSEUR_H
