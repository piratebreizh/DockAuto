<<<<<<< HEAD:equipe.h
#include <string>
#include<Robot.h>
#include<QPointer>
#ifndef EQUIPE_H
#define EQUIPE_H

class Equipe
{
public:
    Equipe();
private:
    int idEquipe;
    std::string nomEquipe;
    QPointer<Robot> listeRobotEquipe;
};

#endif // EQUIPE_H
=======
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
>>>>>>> remotes/origin/antoine:Equipe.h
