#ifndef PLATFORME1_H
#define PLATFORME1_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Platforme1;
}

class Platforme1 : public QDialog
{
    Q_OBJECT

public:
    explicit Platforme1(QWidget *parent = 0);
    ~Platforme1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Platforme1 *ui;
};

#endif // PLATFORME1_H
