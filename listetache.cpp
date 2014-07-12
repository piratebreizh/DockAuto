#include "listetache.h"

Listetache::Listetache()
{
    this->listDesTaches = new QList<Tache*>();
}

void Listetache::ajoutTache(Tache *_tache)
{
    this->listDesTaches->append(_tache);
}

Tache * Listetache::getTacheNonEffectuee()
{
    for(int i=0 ; i < listDesTaches->size() ; i++){
        if(listDesTaches->at(i)->statut != Tache::EFFECTUEE)
            return listDesTaches->at(i);
    }
    return NULL;
}

QList<Tache*> * Listetache::getListeDesTaches()
{
    return this->listDesTaches;
}
