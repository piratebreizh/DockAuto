#ifndef TACHE_H
#define TACHE_H
#include <Tile.h>

class Tache
{
public:
    Tache();
    Tache(double, int,int,int,int);

    int statut;
    Tile  * depart;
    Tile  * arrivee;

    double getPoids();
    void setPoids(double);

    enum Status{
        A_EFFECTUER = -1,
        CARGAISON_RECUP = 0,
        EFFECTUEE = 1
    };

private :
    double poids;

};

#endif // TACHE_H
