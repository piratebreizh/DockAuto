#include "gestiondb.h"
#include <QSqlQuery>
#include <QString>
#include <iostream>

using namespace std;

GestionDB::GestionDB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("DockAutodb");
}

GestionDB::GestionDB(const QString &HostName, const QString& UserName, const QString& Password, const QString& DatabaseName){

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(HostName);
    db.setUserName(UserName);
    db.setPassword(Password);
    db.setDatabaseName(DatabaseName);
}

bool GestionDB::Requete(const QString &req){
    QSqlQuery query;
    return query.exec(req);
}

void GestionDB::Select(const QString &sel){
    QSqlQuery query;
    if(query.exec(sel))
    {
        NbResultatRequete=query.size();
        while(query.next())
        {
            ResultatRequete.push_back(query.value(0));
        }
    }
}

GestionDB::~GestionDB(){
    db.close();
}
