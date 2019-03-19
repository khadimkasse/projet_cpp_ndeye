#ifndef DETAILSNOTES_H
#define DETAILSNOTES_H

#include <QDialog>

namespace Ui {
class DetailsNotes;
}

class DetailsNotes : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsNotes(QWidget *parent = 0);
    ~DetailsNotes();

private slots:
    void on_retour_clicked();

    void on_rechercheEtudiants_clicked();

private:
    Ui::DetailsNotes *ui;
};

#endif // DETAILSNOTES_H
