#ifndef DIALOGM_H
#define DIALOGM_H

#include <QDialog>

namespace Ui {
class DialogM;
}

class DialogM : public QDialog
{
    Q_OBJECT

public:
    explicit DialogM(QWidget *parent = 0);
    ~DialogM();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::DialogM *ui;
};

#endif // DIALOGM_H