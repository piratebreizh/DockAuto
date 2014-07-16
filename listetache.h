#ifndef LISTETACHE_H
#define LISTETACHE_H
#include <QList>
#include <tache.h>
#include <qstring.h>

class Tache;

class Listetache
{
public:
    Listetache();
    QList<Tache*> * getListeDesTaches();

    void ajoutTache(Tache*);
    Tache * getTacheNonEffectuee();

    void setNomListeTaches(QString);
    QString getNomListeTaches();

    int IDListeTache;

private :
    QList<Tache*> * listDesTaches;
    QString * nomListeTaches;
};

#endif // LISTETACHE_H
