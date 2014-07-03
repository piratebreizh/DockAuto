#ifndef MAPSCENE_H
#define MAPSCENE_H
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

private:
    Entrepot e;
};

#endif // MAPSCENE_H
