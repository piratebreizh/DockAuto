#ifndef GESTIONDB_H
#define GESTIONDB_H

#include <QSqlDatabase>
#include <QString>
#include <QVariant>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class GestionDB
{
public:
    static GestionDB * getInstance()
    {
        if (NULL == _singleton)
            _singleton =  new GestionDB;

        return _singleton;
    }

    static void kill()
    {
      if (NULL != _singleton)
        {
          delete _singleton;
          _singleton = NULL;
        }
    }

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
    static GestionDB * _singleton;
    QSqlDatabase db;
    int NbResultatRequete;
    QString HostName;
    QString UserName;
    QString Password;
    QString DatabaseName;
    GestionDB();
    ~GestionDB();
};

#endif // GESTIONDB_H
