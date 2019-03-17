#ifndef AFFICHERMATIERES_H
#define AFFICHERMATIERES_H

#include <QDialog>

namespace Ui {
class AfficherMatieres;
}

class AfficherMatieres : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherMatieres(QWidget *parent = 0);
    ~AfficherMatieres();

private slots:
    void on_retour_clicked();

private:
    Ui::AfficherMatieres *ui;
};

#endif // AFFICHERMATIERES_H
