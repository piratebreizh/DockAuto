#ifndef NODE_H
#define NODE_H
#include <math.h>

class Noeud
{
    int xPos;
    int yPos;
    int distanceParcourue; // distance totale déjà parcourue jusqu'à ce noeud
    // priorite= distanceParcourue + Distance Restante Estimee
    int priorite;  // smaller: higher priorite

    public:
        Noeud(int, int, int, int);

        int getxPos() const ;
        int getyPos() const;
        int getDistanceParcourue() const;
        int getPriorite() const ;

        void majPriorite(const int &, const int &);
        void prochaineDistance();
        const int & getDistanceRestanteEstimee(const int &, const int &) const;

        friend bool operator<(const Noeud & a, const Noeud & b)
        {
          return a.getPriorite() > b.getPriorite();
        }
};


#endif // NODE_H
