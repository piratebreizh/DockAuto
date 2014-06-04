#include <string>
#include<Robot.h>
#include<QPointer>
#ifndef EQUIPE_H
#define EQUIPE_H

using namespace std;

class Equipe
{
public:
    Equipe();
private:
    int idEquipe;
    string nomEquipe;
    QPointer<Robot> listeRobotEquipe;
};

#endif // EQUIPE_H
