#include "connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>


QSqlDatabase ConnectDB::getConnexion() {
    return db;
}

bool ConnectDB::dbIsOpened() {
    return dbOpened;
}

void ConnectDB::setDBOpened(bool dbOK) {
    this -> dbOpened = dbOK;
}

void ConnectDB::openConnexion()
{
    this -> db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("bdd_projet_cpp");
    db.setUserName("user_projet_cpp");
    db.setPassword("Sokhna");
    setDBOpened(db.open());
    if(dbOpened) {
        qInfo( "Connection à la base de données établie avec succès !" );
    } else {
        qCritical( "La connection a échoué !" );
    }
}

void ConnectDB::closeConnexion() {
    db.close();
    qInfo( "Connection à la base de données fermée !" );
}
