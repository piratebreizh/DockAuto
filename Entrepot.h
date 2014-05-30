#ifndef ENTREPOT_H
#define ENTREPOT_H
#include <string>
#include <vector>
#include "armoire.h"
#include "Robot.h"

#endif // ENTREPOT_H

class Entrepot
{
public:
    Entrepot();
    ~Entrepot();
    void AddArmoire(Armoire);
    void RemoveArmoire(Armoire);
    void AddRobot(Robot);
    void RemoveRobot(Robot);

private:
    int IdEntrepot;
    std::string NomEntrepot;
    std::vector<Armoire> lesArmoires;
    std::vector<Robot> lesRobots;

};

