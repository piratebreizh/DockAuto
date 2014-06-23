#ifndef ENTREPOT_H
#define ENTREPOT_H
#include <string>
#include <map>
#include "Armoire.h"
#include "Robot.h"
#include "Map.h"
#include "Equipe.h"

using namespace std;

class Robot;
class Equipe;
class Map;
class Armoir;

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
    map<int,Armoire> lesArmoires;
    map<int,Equipe> lesEquipes;

};

#endif // ENTREPOT_H
