#include "tache.h"

Tache::Tache()
{
    this->depart;
    this->arrive;
}

void Tache::setPoids(double _poids){
    this->poids = _poids;
}


double Tache::getPoids(){
    return this->poids;
}


void Tache::setDepart(int _x, int _y){
    this->depart.setX(_x);
    this->depart.setX(_y);
}

Depart Tache::getDepart(){
    return depart;
}

void Tache::setArrive(int _x, int _y){
    this->arrive.setX(_x);
    this->arrive.setX(_y);
}

Arrive Tache::getArrive(){
    return arrive;
}
