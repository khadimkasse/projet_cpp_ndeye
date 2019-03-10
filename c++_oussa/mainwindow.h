/*constitue la fenetre d'accueil sur laquelle on arrive pour se connecter.
Futures avancées : La méthode d'identification devrait alller taper 
dans la table des utilisateurs autorisés
qui serient genre des membres de l'administration et regarder à chaque connection
si la combinaison username-password est présente dans la base de données.*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "platforme1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Platforme1 *Platforme;
};

#endif // MAINWINDOW_H
