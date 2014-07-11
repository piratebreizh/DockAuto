#ifndef ROBOT_H
#define ROBOT_H
#include<string>
#include "Tile.h"
#include "Entrepot.h"
#include <QtSql>

using namespace std;

class Entrepot;
class Tile;

class Robot : public Tile
{
public:
    Robot();
    Robot(int,QString);
    QString getNom();
    void setNom(string);
    int getId();
    void setId(int);
    void move(Entrepot&, int,int);



    int idRobot;
    QString nomRobot;

    //PositnomRobota map
    //int xPositionRobot;
    //int yPositionRobot;

    double vitesseRobot;
    double longueurRobot;
    double largeurRobot;

    //Afin de déterminer si le robot peut prendre une cargaison
    double poidsCapaciteDeCharge;
    double longueurCapaciteDeCharge;
    double largeurCapactiteDeCharge;

private:


};

#endif // ROBOT_H
