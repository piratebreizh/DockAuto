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

void Tile::setCoordonnees(Tile t)
{
    this->x=t.getX();
    this->y=t.getY();
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
