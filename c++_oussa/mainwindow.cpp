/*constitue la fenetre d'accueil sur laquelle on arrive pour se connecter.
Futures avancées : La méthode d'identification devrait alller taper 
dans la table des utilisateurs autorisés
qui serient genre des membres de l'administration et regarder à chaque connection
si la combinaison username-password est présente dans la base de données.*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/khadim/Downloads/academics_surface.png");
    int w = ui->label_picture->width();
    int h = ui->label_picture->height();
    ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();

    QString password = ui->lineEdit_password->text();

    if (username == "Hiouas" && password == "Sokhna")
    {
        QMessageBox::information(this,"Identification","Données valides");
        hide();
        Platforme = new Platforme1(this);
        Platforme->show();



    } else

    {
        QMessageBox::warning(this,"identification","Données erronées");

    }
}
