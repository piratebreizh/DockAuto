#ifndef TACHE_H
#define TACHE_H
#include <Tile.h>

class Tache
{
public:
    Tache();
    Tache(double, int,int,int,int);

    double getPoids();
    void setPoids(double);
    Tile  * depart;
    Tile  * arrive;


private :
    double poids;

};

#endif // TACHE_H
