#include "Map.h"
#include <iostream>

using namespace std;

Map::Map()
{
    /*for(int i=0;i<LONGUEUR;i++){
        for(int j=0;j<LARGEUR;j++){
            tab[i][j]=2 ;
        }
    }*/
}


Map::Map(int _ID, string _nom)
{
    this->idMap = _ID;
    this->nomMap = _nom;
}


void Map::AfficheMap(){
    for(int i=0;i<LARGEUR;i++){
        for(int j=0;j<LONGUEUR;j++){
            cout<<tab[i][j]<<" " ;
        }
        cout<<endl;
    }
}


void Map::setIDMap(int _ID){
    this->idMap=_ID;
}

int Map::getIDMap(){
    return this->idMap;
}


string Map::getNomMap(){
    return this->nomMap;
}

void Map::setNomMap(string _nom){
    this->nomMap = _nom;
}
