#ifndef SIMULATION_H
#define SIMULATION_H
#include "Entrepot.h"
#include "Robot.h"
#include "Listetache.h"
#include "Tile.h"
#include "gestiondb.h"

class MapScene;

class Simulation
{

public:
    Simulation();
    QString * nomSimulation;
    int IdSimulation;
    MapScene * mapScene;

    bool LancerSimulation();

    Tile getZoneDepartLibre();

    void ChargerDepot(int);
    bool ChargerEquipe(int);
    void ChargerListeTaches(int);
    Entrepot* getEntrepot();


    void RaffraichirMap();

    float stopSimulation;

private :
    Entrepot * entrepot;
    QMap<int, Robot*> listeRobots;
    Listetache taches;
    QList<Tile> listeZonesDepart;
};

#endif // SIMULATION_H
