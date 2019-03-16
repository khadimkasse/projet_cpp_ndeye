#ifndef CONNECTDB_H
#define CONNECTDB_H
#include <QSqlDatabase>

class ConnectDB
{
public :
QSqlDatabase getConnexion();
bool dbIsOpened();
void setDBOpened(bool dbOK);
void openConnexion();
void closeConnexion();

private :
QSqlDatabase db;
bool dbOpened;
};
#endif // CONNECTDB_H
