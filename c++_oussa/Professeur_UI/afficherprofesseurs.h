#ifndef AFFICHERPROFESSEURS_H
#define AFFICHERPROFESSEURS_H

#include <QDialog>

namespace Ui {
class AfficherProfesseurs;
}

class AfficherProfesseurs : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherProfesseurs(QWidget *parent = 0);
    ~AfficherProfesseurs();

private slots:
    void on_retour_clicked();

private:
    Ui::AfficherProfesseurs *ui;
};

#endif // AFFICHERPROFESSEURS_H
