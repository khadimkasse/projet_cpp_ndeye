#ifndef MENUGESTION_H
#define MENUGESTION_H

#include <QDialog>

namespace Ui {
class MenuGestion;
}

class MenuGestion : public QDialog
{
    Q_OBJECT

public:
    explicit MenuGestion(QWidget *parent = 0);
    ~MenuGestion();

private slots:
    void on_retour_clicked();

    void on_gestioEtudiantsn_clicked();

    void on_gestionProfesseurs_clicked();

private:
    Ui::MenuGestion *ui;
};

#endif // MENUGESTION_H
