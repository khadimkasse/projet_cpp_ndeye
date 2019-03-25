#ifndef AFFICHERPAIEMENTS_H
#define AFFICHERPAIEMENTS_H

#include <QDialog>

namespace Ui {
class AfficherPaiements;
}

class AfficherPaiements : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherPaiements(QWidget *parent = 0);
    ~AfficherPaiements();

private slots:
    void on_retour_clicked();

    void on_rechercher_clicked();

private:
    Ui::AfficherPaiements *ui;
};

#endif // AFFICHERPAIEMENTS_H
