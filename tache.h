#ifndef TACHE_H
#define TACHE_H
//#include <robot.h>
#include <Tile.h>

//class Robot;
class Tile;

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

    int idRobot;

    enum Status{
        A_EFFECTUER = -1,
        CARGAISON_RECUP = 0,
        EFFECTUEE = 1
    };

private :
    double poids;

};

#endif // TACHE_H
