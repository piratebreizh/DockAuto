#ifndef SIMULATION_H
#define SIMULATION_H
#include <listetache.h>
#include "Entrepot.h"

class Simulation
{
public:
    Simulation();
    void LancerSimulation();
    Listetache * listeTache;
    QString * nomSimulation;
    int IdSimulation;
    Entrepot e;

private :

};

#endif // SIMULATION_H
