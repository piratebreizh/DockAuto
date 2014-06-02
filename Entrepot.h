#ifndef ENTREPOT_H
#define ENTREPOT_H
#include <string>
#include <vector>
#include "armoire.h"
#include "Robot.h"
#include "Map.h"
#endif // ENTREPOT_H

class Entrepot : public Map
{
public:
    Entrepot();
    ~Entrepot();
    void AddArmoire(Armoire&);
    void RemoveArmoire(Armoire&);
    void AddRobot(Robot&);
    void RemoveRobot(Robot&);

private:
    std::vector<Armoire> lesArmoires;
    std::vector<Robot> lesRobots;

};

