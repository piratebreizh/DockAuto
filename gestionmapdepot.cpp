#define LONGUEURPIX 20
#define LARGEURPIX 20
#define VIDE 0
#define ARMOIREVIDE 1
#define ARMOIREPLEINE 2
#define ZONEDEP 3
#include "gestionmapdepot.h"
#include <QGraphicsItem>
#include "Entrepot.h"
#include "mapscene.h"

GestionMapDepot::GestionMapDepot()
{
}

void GestionMapDepot::AfficherMap(MapScene &lamap){
    QGraphicsItem *item;
    QPixmap image;
    Entrepot e = lamap.getEntrepot();

    //Gestion de l'affichage
    for (int i = 0; i < LONGUEUR; i++)
      {
        for (int j = 0; j < LARGEUR; j++)
          {
            //Mur
            if (e.tab[i][j] == -1)
              {
                image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\mur.png", 0, Qt::AutoColor);
                item = lamap.addPixmap(image);
                item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
              }
            //Vide
            if (e.tab[i][j] == 0)
              {
                image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\vide.png", 0, Qt::AutoColor);
                item = lamap.addPixmap(image);
                item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
              }
            //Armoire
            if (e.tab[i][j] == 1)
              {
                image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\arm.png", 0, Qt::AutoColor);
                item = lamap.addPixmap(image);
                item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
              }
            //ZoneDepart
            if (e.tab[i][j] == 2)
              {
                image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\dep.png", 0, Qt::AutoColor);
                item = lamap.addPixmap(image);
                item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
              }
            //Robot
            if (e.tab[i][j] > 1)
              {
                image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\rob.png", 0, Qt::AutoColor);
                item = lamap.addPixmap(image);
                item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
              }
          }
      }
}
