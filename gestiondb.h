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
    void Requete(const QString&);
    void Select(const QString&);
    void SelectFirst(const QString&);
    void AfficheResultatsSelect();
    QString getResultat(int);
    void selectMutliLigne(const QString &);
    void afficherResultatSelectMultiple();

    QList< QList<QVariant> > reusltatSelectMultiLignes;
    vector<QVariant> ResultatRequete;

private:
    QSqlDatabase db;
    int NbResultatRequete;
    QString HostName="localhost";
    QString UserName="root";
    QString Password="";
    QString DatabaseName="DockAutodb";


};

#endif // GESTIONDB_H
