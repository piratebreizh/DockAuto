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

void Map::AfficheMap(){
    for(int i=0;i<LONGUEUR;i++){
        for(int j=0;j<LARGEUR;j++){
            cout<<tab[i][j]<<" " ;
        }
        cout<<endl;
    }
}
