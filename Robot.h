#ifndef ROBOT_H
#define ROBOT_H
#include<string>
#include "Tile.h"

class Robot : public Tile
{
public:
    Robot();
    std::string getNom();
    void setNom(std::string);
    int getId();
    void setId(int);

private:

    int idRobot;
    std::string nomRobot;

    //Position sur la map
    int xPositionRobot;
    int yPositionRobot;

    float vitesseRobot;
    int longueurRobot;
    int largeurRobot;

    //Afin de déterminer si le robit peut prendre une cargaison
    float poidsCapaciteDeCharge;
    int longueurCapaciteDeCharge;
    int largeurCapactiteDeCharge;
};

#endif // ROBOT_H
