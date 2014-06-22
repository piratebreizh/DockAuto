#ifndef ARMOIRE_H
#define ARMOIRE_H
#include "Tile.h"
#include<string>

using namespace std;

class Armoire : public Tile
{
public:
    Armoire();
    //~Armoire();

private:
    int IdArmoire;
    string NomArmoire;
};

#endif // ARMOIRE_H
