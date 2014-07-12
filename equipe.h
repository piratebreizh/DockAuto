#include <string>
#include "Robot.h"
#include <map>
#include <QString>
#ifndef EQUIPE_H
#define EQUIPE_H

using namespace std;

class Robot;

class Equipe
{
public:
    Equipe();
    Equipe(int,string);
    Equipe(int,QString);
    void AddRobot(Robot &);
    void RemoveEquipe(Robot&);
    int idEquipe;
    QString nomEquipe;


private:

    map<int,Robot> listeRobotEquipe;
};

#endif // EQUIPE_H

