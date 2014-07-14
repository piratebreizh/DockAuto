#ifndef RECHERCHECHEMINASTAR_H
#define RECHERCHECHEMINASTAR_H
#define nb_dir 4
#include "noeud.h"
#include "Entrepot.h"

using namespace std;

class RechercheCheminAStar
{
public:
    RechercheCheminAStar(Entrepot *);
    QString calculChemin(const int &, const int &, const int &, const int &);
    void redefGraphe();

    Entrepot * entrepot;

    //Dimensions
    int larg;
    int haut;

    //Graphes
    int graphe_noeuds_fermes[30][30]; // Graphe noeuds visités
    int graphe_noeud_ouverts[30][30]; // Graphe noeuds à visiter

    //Directions
    int dir_map[30][30]; // Graphe des directions prises
    int dx[nb_dir];
    int dy[nb_dir];
};

#endif // RECHERCHECHEMINASTAR_H



