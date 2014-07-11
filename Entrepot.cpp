#include "Entrepot.h"
#include "MapScene.h"
#include <QString>

using namespace std;

Entrepot::Entrepot(){

}

Entrepot::~Entrepot(){

}


Entrepot::Entrepot(int _id,QString _nom){
    this->id =_id;
    this->nom = _nom;
}


void Entrepot::AddArmoire(Armoire &arm){
    if(tab[arm.getX()][arm.getY()]==0)
        tab[arm.getX()][arm.getY()]=1;
}

void Entrepot::AddRobot(Robot &rob){
    if(isTileDisponible(rob.getX(), rob.getY()))
        tab[rob.getX()][rob.getY()]=rob.getId();
}

void Entrepot::RemoveArmoire(Armoire &arm){
    if(tab[arm.getX()][arm.getY()]==1)
        tab[arm.getX()][arm.getY()]=0;
}

void Entrepot::RemoveRobot(Robot &rob){
    if(tab[rob.getX()][rob.getY()]>0)
        tab[rob.getX()][rob.getY()]=0;
}

void Entrepot::RedefTab(int _lon, int _lar){
    for (int i = _lon+1; i < LONGUEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
            tab[i][j]=MapScene::MUR;
        }
    }

    for (int i = 0; i < LONGUEUR; i++)
    {
        for (int j = _lar+1; j < LARGEUR; j++)
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

void Entrepot::copieEntrepot(Entrepot *_e){
    nom=_e->getNom();
    largeur=_e->getLargeur();
    longueur=_e->getLongueur();
    RedefTab(longueur,largeur);
    for (int i = 0; i < longueur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            tab[i][j]=_e->tab[i][j];
        }
    }
}

bool Entrepot::isTileDisponible(int X, int Y)
{
    return tab[X][Y]==MapScene::VIDE || tab[X][Y]==MapScene::ZONEDEP;
}
