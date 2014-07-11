#ifndef ROBOT_H
#define ROBOT_H
#include<string>
#include "Tile.h"
#include "Entrepot.h"
#include <QtSql>
#include "Tache.h"

using namespace std;

class Entrepot;
class Tache;

class Robot : public Tile
{
public:
    Robot();
    Robot(int,QString);

    QString getNom();
    void setNom(string);
    int getId();
    void setId(int);

    void move(Entrepot&, int,int);

    void addTache(Tache);
    Tache * getTacheNonEffectuee();

    int idRobot;
    QString nomRobot;

    double vitesseRobot;
    double longueurRobot;
    double largeurRobot;

    //Afin de déterminer si le robot peut prendre une cargaison
    double poidsCapaciteDeCharge;
    double longueurCapaciteDeCharge;
    double largeurCapactiteDeCharge;

    QList<Tache> listeTaches;

private:


};

#endif // ROBOT_H
