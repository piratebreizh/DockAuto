#include "Entrepot.h"
#include "MapScene.h"
#include <QString>

using namespace std;

Entrepot::Entrepot(){

}

Entrepot::~Entrepot(){

}
Entrepot::Entrepot(Entrepot *_e){
    nom=_e->getNom();
    largeur=_e->getLargeur();
    longueur=_e->getLongueur();
    for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = 0; j < LONGUEUR; j++)
        {
            this->tab[i][j]=_e->tab[i][j];
        }
    }
}

Entrepot::Entrepot(int _id,QString _nom){
    this->id =_id;
    this->nom = _nom;
}


void Entrepot::AddRobot(Robot &rob){
    if(isTileDisponible(rob.getX(), rob.getY()))
        tab[rob.getX()][rob.getY()]=rob.getId();
}

void Entrepot::RemoveRobot(Robot &rob){
    if(tab[rob.getX()][rob.getY()]>0)
        tab[rob.getX()][rob.getY()]=0;
}

void Entrepot::RedefTab(int _lon, int _lar){
    for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = _lon+1; j < LONGUEUR; j++)
        {
            tab[i][j]=MapScene::MUR;
        }
    }

    for (int i = _lar+1; i < LARGEUR; i++)
    {
        for (int j = 0; j < LONGUEUR; j++)
        {
            tab[i][j]=MapScene::MUR;
        }
    }
}

void Entrepot::setLargeur(int _larg){
    largeur=_larg;
}

void Entrepot::setLongueur(int _long){
    longueur=_long;
}

int Entrepot::getLargeur(){
    return largeur;
}

int Entrepot::getLongueur(){
    return longueur;
}

void Entrepot::setNom(QString _nom){
    nom=_nom;
}

QString Entrepot::getNom(){
    return nom;
}

void Entrepot::setId(int _id){
    id=_id;
}

int Entrepot::getId(){
    return id;
}

bool Entrepot::isTileDisponible(int X, int Y)
{
    return tab[X][Y]==MapScene::VIDE || tab[X][Y]==MapScene::ZONEDEP;
}

int Entrepot::getNbZonesDepart()
{
    int nb_zp = 0;
    for (int i = 0; i < LARGEUR; i++){
        for (int j = 0; j < LONGUEUR; j++){
            if (this->tab[i][j] == MapScene::ZONEDEP)
                nb_zp++;
        }
    }
    return nb_zp;
}
