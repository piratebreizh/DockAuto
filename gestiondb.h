#ifndef GESTIONDB_H
#define GESTIONDB_H

#include <QSqlDatabase>
#include <QString>
#include <QVariant>
#include <vector>
#include <string>

using namespace std;
class GestionDB
{
public:
    GestionDB();
    GestionDB(const QString&,const QString&,const QString&,const QString&);
    ~GestionDB();
    bool Requete(const QString&);
    void Select(const QString&);

private:
    QSqlDatabase db;
    vector<QVariant> ResultatRequete;
    int NbResultatRequete;
};

#endif // GESTIONDB_H
