#ifndef ROBOT_H
#define ROBOT_H
#include<string>

class Robot
{
public:
    Robot();

private:

    int idRobot;
    std::string nomRobot;

    //Position sur la map
    float xPositionRobot;
    float yPositionRobot;

    float vitesseRobot;
    float longueurRobot;
    float largeurRobot;

    //Afin de déterminer si le robit peut prendre une cargaison
    float poidsCapaciteDeCharge;
    float longueurCapaciteDeCharge;
    float largeurCapactiteDeCharge;

};

#endif // ROBOT_H
