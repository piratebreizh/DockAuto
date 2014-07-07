#ifndef TACHE_H
#define TACHE_H
#include <Tile.h>
#include <robot.h>

class Robot;

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
    Robot * robot;


private :
    double poids;

};

#endif // TACHE_H
