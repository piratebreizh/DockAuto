#ifndef MAP_H
#define MAP_H
#define LONGUEUR 30
#define LARGEUR 30
#include <string>

using namespace std;

class Map
{
public:
    Map();
    int tab[LONGUEUR][LARGEUR]={{0}};
    void AfficheMap();
private :
    int idMap;
    string nomMap;
};

#endif // MAP_H
