#ifndef SIMULATION_H
#define SIMULATION_H
#include <listetache.h>
#include "Entrepot.h"

class Simulation
{
public:
    Simulation();
    void LancerSimulation();
    void ChargerDepot(int);
    Listetache * listeTache;
    QString * nomSimulation;
    int IdSimulation;


private :
    Entrepot *e;
};

#endif // SIMULATION_H
