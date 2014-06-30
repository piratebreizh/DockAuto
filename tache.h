#ifndef TACHE_H
#define TACHE_H
#include <Tile.h>

class Tache : Tile
{
public:
    Tache();
    double getPoids();
    void setPoids();

private :
    double poids;

};

#endif // TACHE_H
