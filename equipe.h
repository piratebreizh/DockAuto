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
    void AddEquipe(Robot &);
    void RemoveEquipe(Robot&);
    void AfficheEquipe();
    int idEquipe;
    string nomEquipe;
    QString nomEquipe2;


private:

    map<int,Robot> listeRobotEquipe;
};

#endif // EQUIPE_H

