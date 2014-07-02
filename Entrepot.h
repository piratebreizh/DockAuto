#ifndef ENTREPOT_H
#define ENTREPOT_H
#include <QString>
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
    int getLargeur();
    void setLargeur(int);
    int getLongueur();
    void setLongueur(int);
    QString getNom();
    void setNom(QString);
    void RedefTab(int, int);


private:
    map<int,Armoire> lesArmoires;
    map<int,Equipe> lesEquipes;
    int longueur;
    int largeur;
    QString nom;

};

#endif // ENTREPOT_H

