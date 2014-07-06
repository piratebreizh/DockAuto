#ifndef TACHE_H
#define TACHE_H
#include <Tile.h>
#include <Depart.h>
#include<arrive.h>

class Tache
{
public:
    Tache();
    Tache(double, int,int,int,int);

    double getPoids();
    void setPoids(double);
    /*void setDepart(int _x, int _y);
    Depart getDepart();
    void setArrive(int _x, int _y);
//    Arrive getArrive();*/
    Tile  * depart;
    Tile  * arrive;


private :
    double poids;

};

#endif // TACHE_H
