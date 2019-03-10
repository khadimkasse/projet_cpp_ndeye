/*main de l'applicatio. On y centralise toutes les classes nécessaires à l'application et 
la logique de liens entre elles.*/
#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlDatabase>

#include <iostream>

#define q2c(string) string.toStdString()


int main(int argc, char *argv[])
{
    //qputenv("QT_DEBUG_PLUGINS", "1");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    /*QSqlDatabase defaut = QSqlDatabase::addDatabase("QMYSQL");
    //defaut.setConnectOptions("UNIX_SOCKET=/Applications/MAMP/tmp/mysql/mysql.sock");
    defaut.setHostName("localhost");
    defaut.setDatabaseName("etudiants");
    defaut.setUserName("projetcpp");
    defaut.setPassword("Sokhn");
    //defaut.setPort(8889);
    defaut.open();

    if(defaut.open())
    {
        std::cout << "Vous êtes maintenant connecté à la DB " << q2c(defaut.hostName()) << std::endl;

    }
    else
    {
        std::cout << "La connexion a échoué " << std::endl;
    }
*/
}
