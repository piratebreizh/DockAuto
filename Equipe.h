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
