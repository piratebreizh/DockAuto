#include "tache.h"

Tache::Tache()
{
    this->depart = new Tile();
    this->arrive = new Tile();

}

Tache::Tache(double _poids, int _departX, int _departY, int _arriveX, int _arriveY){
    this->depart = new Tile();
    this->arrive = new Tile();

    this->poids = _poids;
    this->depart->setX(_departX);
    this->depart->setY(_departY);
    this->arrive->setX(_arriveX);
    this->arrive->setY(_arriveY);
}

void Tache::setPoids(double _poids){
    this->poids = _poids;
}


double Tache::getPoids(){
    return this->poids;
}

/*
void Tache::setDepart(int _x, int _y){
    //this->depart.setX(_x);
    //this->depart.setX(_y);
}

Depart Tache::getDepart(){
    //return depart;
}

void Tache::setArrive(int _x, int _y){
    //this->arrive.setX(_x);
    //this->arrive.setX(_y);
}

Arrive Tache::getArrive(){
    //return arrive;
}

*/
