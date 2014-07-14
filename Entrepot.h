#ifndef ENTREPOT_H
#define ENTREPOT_H
#include <QString>
#include <map>
#include "Robot.h"
#include "Map.h"
#include "Equipe.h"

using namespace std;

class Robot;
class Equipe;
class Map;

class Entrepot : public Map
{
public:
    Entrepot();
    Entrepot(int,QString);
    Entrepot(Entrepot *e);
    ~Entrepot();

    void AddRobot(Robot&);
    void RemoveRobot(Robot&);

    int getLargeur();
    void setLargeur(int);
    int getLongueur();
    void setLongueur(int);
    int getId();
    void setId(int);
    QString getNom();
    void setNom(QString);

    bool isTileDisponible(int,int);

    void RedefTab(int, int);

private:
    int longueur;
    int largeur;
    QString nom;
    int id;

};

#endif // ENTREPOT_H

