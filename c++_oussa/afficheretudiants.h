#ifndef AFFICHERETUDIANTS_H
#define AFFICHERETUDIANTS_H

#include <QDialog>

namespace Ui {
class AfficherEtudiants;
}

class AfficherEtudiants : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherEtudiants(QWidget *parent = 0);
    ~AfficherEtudiants();

private slots:
    void on_cancel_clicked();


private:
    Ui::AfficherEtudiants *ui;
};

#endif // AFFICHERETUDIANTS_H
