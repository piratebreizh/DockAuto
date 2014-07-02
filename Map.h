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
    Map(int, string );

    int tab[LONGUEUR][LARGEUR]={{0}};
    void AfficheMap();
    int getIDMap();
    void setIDMap(int);
    string getNomMap();
    void setNomMap(string);

private :
    int idMap;
    string nomMap;
};

#endif // MAP_H
