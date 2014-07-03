#include "mapscene.h"
#include "gestiondb.h"
#include "armoire.h"
#include "QGraphicsItem"
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsView>
#include"viewcreationdepot.h"

MapScene::MapScene(QObject* parent)
    : QGraphicsScene(parent)
{
}

void MapScene::setInfoDepot(int lon, int larg, QString nom){

    e.setLargeur(larg);
    e.setLongueur(lon);
    e.setNom(nom);
    //définition limites de la map
    e.RedefTab(lon,larg);
}

Entrepot MapScene::getEntrepot(){
    return e;
}

void MapScene::mousePressEvent(QGraphicsSceneMouseEvent *ev){

    int x =(int)(ev->scenePos().x()/20);
    int y =(int)(ev->scenePos().y()/20);

    switch (e.tab[x][y]){

    case MUR:
        break;
    case VIDE:
        //Armoire a;
        //e.AddArmoire(a);
        e.tab[x][y]=ARMOIREVIDE;
        break;
    case ARMOIREVIDE:
        e.tab[x][y]=ZONEDEP;
        break;
    default:
        e.tab[x][y]=VIDE;
        break;

    }
    this->AfficherMap();
}

void MapScene::AfficherMap()
{
  QGraphicsItem *item;
  QPixmap image;

  //Gestion de l'affichage
  for (int i = 0; i < LONGUEUR; i++)
    {
      for (int j = 0; j < LARGEUR; j++)
        {
          //Mur
          if (e.tab[i][j] == MUR)
            {
              image.load(":/res/images/mur.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Vide
          if (e.tab[i][j] == VIDE)
            {
              image.load(":/res/images/vide.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Armoire vide
          if (e.tab[i][j] == ARMOIREVIDE)
            {
              image.load(":/res/images/arm.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Armoire pleine
          if (e.tab[i][j] == ARMOIREPLEINE)
            {
              image.load(":/res/images/arm.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //ZoneDepart
          if (e.tab[i][j] == ZONEDEP)
            {
              image.load(":/res/images/dep.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Robot
          if (e.tab[i][j] > ZONEDEP)
            {
              image.load(":/res/images/rob.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
        }
    }
}



/**
 * @brief ViewCreationDepot::SaveDepotDb
 * Sauvegarde du depot dans la base de donnée
 */
void MapScene::SaveDepotDb(){
    GestionDB db;
    db.Requete("INSERT INTO entrepot (nom,longueur,largeur) VALUES ('" + e.getNom() +
               "','" + e.getLargeur() + "','" + e.getLongueur() + "')");
}
