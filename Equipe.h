#include <string>
#include "Robot.h"
#include <map>
#ifndef EQUIPE_H
#define EQUIPE_H

using namespace std;

class Robot;

class Equipe
{
public:
    Equipe();
    Equipe(int,string);
    void AddEquipe(Robot &);
    void RemoveEquipe(Robot&);
    void AfficheEquipe();
private:
    int idEquipe;
    string nomEquipe;
    map<int,Robot> listeRobotEquipe;
};

#endif // EQUIPE_H
