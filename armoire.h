#ifndef ARMOIRE_H
#define ARMOIRE_H
#include "Tile.h"
#include<string>

class Armoire : public Tile
{
public:
    Armoire();
    //~Armoire();

private:
    int IdArmoire;
    std::string NomArmoire;
};

#endif // ARMOIRE_H
