#ifndef MAPSCENE_H
#define MAPSCENE_H
#define LONGUEURPIX 20
#define LARGEURPIX 20
#include <QGraphicsScene>
#include <QString>
#include "Entrepot.h"
#include "Tile.h"
#include <viewdefinirtache.h>

class Tile;
class ViewDefinirTache;

class MapScene : public QGraphicsScene
{
public:
    MapScene();
    MapScene(QObject* parent);
    void setInfoDepot(int lon, int larg, QString nom);
    void SaveDepotDb();
    Entrepot* getEntrepot();
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    void AfficherMap();
    void setDepot(Entrepot *e);

    void entrerEnModeDefinitionTache(ViewDefinirTache * viewDefinirTache);
    bool flagEditionTache;
    bool flagEditerDepart;
    bool flagEditerArriver;
    bool lectureSeule;
    void coordonneeCliquer(int x,int y);
    Tile retournTileSelectionnee();
    ViewDefinirTache * viewDefinirTache;

    enum TilesNumbers{
        MUR = -1,
        VIDE = 0,
        ARMOIREVIDE = -3,
        ARMOIREPLEINE = -4,
        ZONEDEP = -5
    };

private:
    Entrepot *e;
};

#endif // MAPSCENE_H
