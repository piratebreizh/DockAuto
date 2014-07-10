#include "Tile.h"

using namespace std;

Tile::Tile()
{
}

void Tile::setX(int x)
{
    this->x=x;
}

void Tile::setY(int y)
{
    this->y=y;
}

int Tile::getX()
{
    return x;
}

int Tile::getY()
{
    return y;
}
