#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include"ajouteretudiant.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog2 *ui;
    //AjouterEtudiant *ajouteretud;
};

#endif // DIALOG2_H
