#ifndef MAPSCENE_H
#define MAPSCENE_H
#include <QGraphicsScene>
#include <QString>
#include "Entrepot.h"
#include <viewcreationdepot.h>

//class ViewCreationDepot;

class MapScene : public QGraphicsScene
{
public:
    MapScene();
    MapScene(QObject* parent);
    void setInfoDepot(int lon, int larg, QString nom);
    void SaveDepotDb();
    Entrepot getEntrepot();
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
   // friend void ViewCreationDepot::AfficherMap(int lon, int larg );
private:
    Entrepot e;
};

#endif // MAPSCENE_H
