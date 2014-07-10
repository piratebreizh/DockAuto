#include "listetache.h"

Listetache::Listetache()
{
    this->listDesTache = new QList<Tache>();
}

void Listetache::ajoutNouvelleTacheDansListe(Tache _tache)
{
    this->listDesTache->append(_tache);
}

QList<Tache> * Listetache::getListeDesTaches()
{
    return this->listDesTache;
}
