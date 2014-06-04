#ifndef ENTREPOT_H
#define ENTREPOT_H
#include <string>
#include <vector>
#include "Armoire.h"
#include "Robot.h"
#include "Map.h"
#endif // ENTREPOT_H

using namespace std;

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
    vector<Armoire> lesArmoires;
    vector<Robot> lesRobots;

};

