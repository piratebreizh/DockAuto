#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include "noeud.h"
#include "recherchecheminastar.h"
#include "MapScene.h"

RechercheCheminAStar::RechercheCheminAStar(Entrepot *e)
{
    haut = e->getLongueur();
    larg = e->getLargeur();

    entrepot = e;

    //Initialisation des directions possibles
    dx[0] = 1;
    dx[1] = 0;
    dx[2] = -1;
    dx[3] = 0;

    dy[0] = 0;
    dy[1] = 1;
    dy[2] = 0;
    dy[3] = -1;
}

void RechercheCheminAStar::redefGraphe()
{
    //On met à 0 les graphes
    for(int y=0 ; y<30 ; y++)
    {
        for(int x=0 ; x<30 ; x++)
        {
            graphe_noeuds_fermes[x][y] = 0;
            graphe_noeud_ouverts[x][y] = 0;
        }
    }
}

QString RechercheCheminAStar::calculChemin( const int & xDepart, const int & yDepart,
                                            const int & xArrivee, const int & yArrivee )
{
    static priority_queue<Noeud> noeuds_a_visiter[2]; // Listes de Noeuds pas encore visités
    static int index_NAV; // index noeuds à visiter
    static Noeud* n0;
    static Noeud* nEnfant;
    static int i, j, x, y, xEnfant, yEnfant;
    static char c;
    index_NAV=0;

    //On met à 0 les graphes
    redefGraphe();

    // Création du noeud de départ et on le met dans les noeuds à visiter
    n0 = new Noeud(xDepart, yDepart, 0, 0);
    n0->majPriorite(xArrivee, yArrivee);
    noeuds_a_visiter[index_NAV].push(*n0);
    graphe_noeud_ouverts[xDepart][yDepart] = n0->getPriorite();

    // Tant qu'il y a des noeuds à visiter
    while(!noeuds_a_visiter[index_NAV].empty())
    {
        //On récupère le noeud ayant la priorité la plus élevée
        n0=new Noeud( noeuds_a_visiter[index_NAV].top().getxPos(),
                      noeuds_a_visiter[index_NAV].top().getyPos(),
                      noeuds_a_visiter[index_NAV].top().getDistanceParcourue(),
                      noeuds_a_visiter[index_NAV].top().getPriorite());

        x=n0->getxPos();
        y=n0->getyPos();

        //On le marque comme noeud visité
        noeuds_a_visiter[index_NAV].pop();
        graphe_noeud_ouverts[x][y] = 0;
        graphe_noeuds_fermes[x][y] = 1;

        //Si on a atteint l'arrivée
        if(x==xArrivee && y==yArrivee)
        {
            //On génére le chemin parcourue en suivant les directions prises
            QString path = "";
            while(!(x==xDepart && y==yDepart))
            {
                j = dir_map[x][y];
                c = '0' + (j+nb_dir/2)%nb_dir;
                path = c + path;
                x +=dx[j];
                y+=dy[j];
            }

            // on supprime le noeud déjà visité
            delete n0;
            // on vide les noeuds restants
            while(!noeuds_a_visiter[index_NAV].empty())
                noeuds_a_visiter[index_NAV].pop();

            //Il faudra retourner juste la direction que le robot doit prendre
            return path;
        }

        // Création des noeuds enfants visitables
        for(i=0;i<nb_dir;i++)
        {
            // coordonnées noeuds enfant
            xEnfant=x+dx[i];
            yEnfant=y+dy[i];

            bool nEnfantEgalDepart = xEnfant == xDepart && yEnfant == yDepart;
            bool nEnfantEgalArrivee = xEnfant == xArrivee && yEnfant == yArrivee;

            //Si le noeud enfant peut être visité
            if(!(xEnfant<0 || xEnfant>LARGEUR
                 || yEnfant<0 || yEnfant>LONGUEUR
                 || !(entrepot->tab[xEnfant][yEnfant]==MapScene::VIDE
                      || nEnfantEgalArrivee || nEnfantEgalDepart)
                 || entrepot->tab[xEnfant][yEnfant]==MapScene::MUR
                 || graphe_noeuds_fermes[xEnfant][yEnfant]==1))
            {
                // Création du noeud enfant
                nEnfant = new Noeud( xEnfant,
                                     yEnfant,
                                     n0->getDistanceParcourue(),
                                     n0->getPriorite());
                nEnfant->prochaineDistance();
                nEnfant->majPriorite(xArrivee, yArrivee);

                //S'il n'est pas déjà dans les Noeuds à visiter, on l'y ajoute
                if(graphe_noeud_ouverts[xEnfant][yEnfant]==0)
                {
                    graphe_noeud_ouverts[xEnfant][yEnfant] = nEnfant->getPriorite();
                    noeuds_a_visiter[index_NAV].push(*nEnfant);

                    //On marque la direction prise
                    dir_map[xEnfant][yEnfant]=(i+nb_dir/2)%nb_dir;
                }
                // Sinon si la priorité déjà
                else if(graphe_noeud_ouverts[xEnfant][yEnfant] > nEnfant->getPriorite())
                {
                    //On met à jour la priorité
                    graphe_noeud_ouverts[xEnfant][yEnfant]=nEnfant->getPriorite();
                    // On met à jour la direction prise à partir du noeud précédant
                    dir_map[xEnfant][yEnfant]=(i+nb_dir/2)%nb_dir;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    //
                    //
                    while(!(noeuds_a_visiter[index_NAV].top().getxPos()==xEnfant
                            && noeuds_a_visiter[index_NAV].top().getyPos()==yEnfant))
                    {
                        noeuds_a_visiter[1-index_NAV].push(noeuds_a_visiter[index_NAV].top());
                        noeuds_a_visiter[index_NAV].pop();
                    }
                    noeuds_a_visiter[index_NAV].pop(); // on supprime le noeud enfant visité

                    // On sélectionne la liste de Noeux à visiter la plus grande
                    if(noeuds_a_visiter[index_NAV].size() > noeuds_a_visiter[1-index_NAV].size())
                        index_NAV=1-index_NAV;

                    while(!noeuds_a_visiter[index_NAV].empty())
                    {
                        noeuds_a_visiter[1-index_NAV].push(noeuds_a_visiter[index_NAV].top());
                        noeuds_a_visiter[index_NAV].pop();
                    }
                    index_NAV=1-index_NAV;
                    noeuds_a_visiter[index_NAV].push(*nEnfant); // on ajoute le meilleur noeud
                }
                else{
                    delete nEnfant;
                }
            }
        }
        delete n0;
    }

    return "";
}
