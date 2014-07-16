#include "noeud.h"


Noeud::Noeud(int xp, int yp, int d, int p)
{
    xPos=xp;
    yPos=yp;
    distanceParcourue=d;
    priorite=p;
}

int Noeud::getxPos() const
{
    return xPos;
}
int Noeud::getyPos() const {
    return yPos;
}
int Noeud::getDistanceParcourue() const {
    return distanceParcourue;
}
int Noeud::getPriorite() const {
    return priorite;
}

void Noeud::majPriorite(const int & xArrivee, const int & yArrivee)
{
     priorite=distanceParcourue+getDistanceRestanteEstimee(xArrivee, yArrivee)*10; //A*
}

void Noeud::prochaineDistance()
{
     distanceParcourue+=10;
}

const int & Noeud::getDistanceRestanteEstimee(const int & xArrivee, const int & yArrivee) const
{
    static int xd, yd, d;
    xd=xArrivee-xPos;
    yd=yArrivee-yPos;

    // distance de Manhattan
    d=abs(xd)+abs(yd);

    return(d);
}
