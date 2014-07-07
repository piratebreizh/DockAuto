#ifndef MAPSCENE_H
#define MAPSCENE_H
#define LONGUEURPIX 20
#define LARGEURPIX 20
#define VIDE 0
#define ARMOIREVIDE 1
#define ARMOIREPLEINE 2
#define ZONEDEP 3
#include <QGraphicsScene>
#include <QString>
#include "Entrepot.h"

class MapScene : public QGraphicsScene
{
public:
    MapScene();
    MapScene(QObject* parent);
    void setInfoDepot(int lon, int larg, QString nom);
    void SaveDepotDb();
    Entrepot getEntrepot();
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void AfficherMap();

    enum TilesNumbers{
        MUR = -1,
        VIDE = 0,
        ARMOIREVIDE = 1,
        ARMOIREPLEINE = 2,
        ZONEDEP = 3
    };

private:
    Entrepot e;
};

#endif // MAPSCENE_H
