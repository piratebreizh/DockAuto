#ifndef ROBOT_H
#define ROBOT_H
#include<string>
#include "Tile.h"
#include "Entrepot.h"

using namespace std;

class Entrepot;

class Robot : public Tile
{
public:
    Robot();
    Robot(int,string);
    string getNom();
    void setNom(string);
    int getId();
    void setId(int);
    void move(Entrepot&, int,int);

    int idRobot;
    string nomRobot;

    //Position sur la map
    int xPositionRobot;
    int yPositionRobot;

    double vitesseRobot;
    double longueurRobot;
    double largeurRobot;

    //Afin de déterminer si le robit peut prendre une cargaison
    double poidsCapaciteDeCharge;
    double longueurCapaciteDeCharge;
    double largeurCapactiteDeCharge;

private:


};

#endif // ROBOT_H
