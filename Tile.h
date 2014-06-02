#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile();
    int getX();
    int getY();
    void setX(int);
    void setY(int);

private:
    int x;
    int y;
};

#endif // TILE_H
