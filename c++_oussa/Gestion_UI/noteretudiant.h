#ifndef NOTERETUDIANT_H
#define NOTERETUDIANT_H

#include <QDialog>

namespace Ui {
class NoterEtudiant;
}

class NoterEtudiant : public QDialog
{
    Q_OBJECT

public:
    explicit NoterEtudiant(QWidget *parent = 0);
    ~NoterEtudiant();

private:
    Ui::NoterEtudiant *ui;
};

#endif // NOTERETUDIANT_H
