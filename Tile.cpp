#include "Tile.h"

using namespace std;

Tile::Tile()
{
}

Tile::Tile(int x, int y)
{
    this->x=x;
    this->y=y;
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
