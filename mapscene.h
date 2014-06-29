#ifndef MAPSCENE_H
#define MAPSCENE_H
#include <QGraphicsView>
#include <QString>
#include "Entrepot.h"

class MapScene : public QGraphicsView
{
public:
    MapScene();
    void AfficherMap(int lon, int larg);
    void setInfoDepot(int lon, int larg, QString nom);
    void SaveDepotDb();
private:
    QGraphicsScene *scene ;
    Entrepot e;
};

#endif // MAPSCENE_H
