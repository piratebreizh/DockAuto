#include "mapscene.h"
#include "gestiondb.h"
#include "QGraphicsItem"

MapScene::MapScene()
{
    scene = new QGraphicsScene();
}

void MapScene::setInfoDepot(int lon, int larg, QString nom){

    e.setLargeur(larg);
    e.setLongueur(lon);
    e.setNom(nom);
}

void MapScene::AfficherMap(int lon, int larg )
{
  QGraphicsItem *item;
  QPixmap image;

  //définition limites de la map
  e.RedefTab(lon,larg);

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


/**
 * @brief ViewCreationDepot::SaveDepotDb
 * Sauvegarde du depot dans la base de donnée
 */
void MapScene::SaveDepotDb(){
    GestionDB db;
    db.Requete("INSERT INTO entrepot (nom,longueur,largeur) VALUES ('" + e.getNom() +
               "','" + e.getLargeur() + "','" + e.getLongueur() + "')");
}
