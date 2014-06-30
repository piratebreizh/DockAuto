#ifndef LISTETACHE_H
#define LISTETACHE_H
#include <QList>
#include <tache.h>
#include <qstring.h>

class Listetache
{
public:
    Listetache();
    void setListDesTaches(QList<Tache> listeDesTache);
    QList<Tache> getListDesTaches;
    void setNomListeTache(QString nomListeTache);
    QString getNomListeTache();

private :
    QList<Tache> * listDesTache;
    QString * nomListeTache;
};

#endif // LISTETACHE_H
