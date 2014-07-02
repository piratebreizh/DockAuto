#ifndef TACHE_H
#define TACHE_H
#include <Tile.h>
//#include <Depart.h>
//#include<arrive.h>

class Tache
{
public:
    Tache();
    double getPoids();
    void setPoids(double);
    void setDepart(int _x, int _y);
    //Depart getDepart();
    void setArrive(int _x, int _y);
    //Arrive getArrive();

private :
    double poids;
    //Depart  depart;
    //Arrive  arrive;

};

#endif // TACHE_H
