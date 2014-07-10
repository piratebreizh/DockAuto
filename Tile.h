#ifndef TILE_H
#define TILE_H

using namespace std;

class Tile
{
public:
    Tile();
    Tile(int,int);
    int getX();
    int getY();
    void setX(int);
    void setY(int);

private:
    int x;
    int y;
};

#endif // TILE_H
