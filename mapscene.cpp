#include "mapscene.h"
#include "gestiondb.h"
#include "armoire.h"
#include "QGraphicsItem"
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsView>

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

    case -1:
        break;
    case 0:
        //Armoire a;
        //e.AddArmoire(a);
        e.tab[x][y]=1;
        break;
    case 1:
        e.tab[x][y]=2;
        break;
    default:
        e.tab[x][y]=0;
        break;

    }

}
/*
void MapScene::AfficherMap(int lon, int larg )
{
  QGraphicsItem *item;
  QPixmap image;

  //Gestion de l'affichage
  for (int i = 0; i < LONGUEUR; i++)
    {
      for (int j = 0; j < LARGEUR; j++)
        {
          if (e.tab[i][j] == -1)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\mur.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(i*20, j*20);
            }
          if (e.tab[i][j] == 1)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\arm.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(i*20, j*20);
            }
          if (e.tab[i][j] > 1)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\rob.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(i*20, j*20);
            }
        }
    }
}
*/

/**
 * @brief ViewCreationDepot::SaveDepotDb
 * Sauvegarde du depot dans la base de donnée
 */
void MapScene::SaveDepotDb(){
    GestionDB db;
    db.Requete("INSERT INTO entrepot (nom,longueur,largeur) VALUES ('" + e.getNom() +
               "','" + e.getLargeur() + "','" + e.getLongueur() + "')");
}
