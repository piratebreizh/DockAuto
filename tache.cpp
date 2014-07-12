#include "tache.h"

Tache::Tache()
{
    this->depart = new Tile();
    this->arrivee = new Tile();
}

Tache::Tache(double _poids, int _departX, int _departY, int _arriveX, int _arriveY)
{
    this->depart = new Tile();
    this->arrivee = new Tile();

    this->poids = _poids;
    this->depart->setX(_departX);
    this->depart->setY(_departY);
    this->arrivee->setX(_arriveX);
    this->arrivee->setY(_arriveY);

    this->statut = A_EFFECTUER;
}

void Tache::setPoids(double _poids)
{
    this->poids = _poids;
}

double Tache::getPoids()
{
    return this->poids;
}

