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
    ~GestionDB();
    void Requete(const QString&);
    void Select(const QString&);
    void SelectFirst(const QString&);
    void AfficheResultatsSelect();
    QString getResultat(unsigned int);
    void selectMutliLigne(const QString &);
    void afficherResultatSelectMultiple();
    int getNbResultat();

    QList< QList<QVariant> > resultatSelectMultiLignes;
    vector<QVariant> ResultatRequete;

private:
    QSqlDatabase db;
    int NbResultatRequete;
    QString HostName;
    QString UserName;
    QString Password;
    QString DatabaseName;
};

#endif // GESTIONDB_H
