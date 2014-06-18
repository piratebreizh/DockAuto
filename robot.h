#ifndef ROBOT_H
#define ROBOT_H
#include<string>
#include <qstring.h>
class Robot
{
public:
    Robot();

    int idRobot;
    QString nomRobot;

    //Position sur la map
    double xPositionRobot;
    double yPositionRobot;

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
