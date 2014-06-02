#ifndef MAP_H
#define MAP_H
#include <string>

class Map
{
public:
    Map();
    int tab[30][30]={{0}};
private :
    int idMap;
    std::string nomMap;
};

#endif // MAP_H
