#ifndef AJOUTERETUDIANT_H
#define AJOUTERETUDIANT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AjouterEtudiant;
}

class AjouterEtudiant : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterEtudiant(QWidget *parent = 0);
    ~AjouterEtudiant();

private slots:
    void on_pushButton_2_clicked();


    void on_pushButton_AjouterEtud_clicked();

private:
    Ui::AjouterEtudiant *ui;
};

#endif // AJOUTERETUDIANT_H
