#include "mapscene.h"
#include "gestiondb.h"
#include "armoire.h"
#include "QGraphicsItem"
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsView>
#include"viewcreationdepot.h"
#include <iostream>

MapScene::MapScene(QObject* parent)
    : QGraphicsScene(parent)
{
    e=new Entrepot();
    flagEditionTache = false;
    flagEditerArriver = false;
    flagEditerDepart = false;
    lectureSeule = false;
}

void MapScene::setInfoDepot(int lon, int larg, QString nom){

    e->setLargeur(larg);
    e->setLongueur(lon);
    e->setNom(nom);
    //définition limites de la map
    e->RedefTab(lon,larg);
}

Entrepot* MapScene::getEntrepot(){
    return e;
}

void MapScene::mousePressEvent(QGraphicsSceneMouseEvent *ev){

    if(!lectureSeule){
        int x =(int)(ev->scenePos().x()/LONGUEURPIX);
        int y =(int)(ev->scenePos().y()/LARGEURPIX);


        if(flagEditionTache){
            QString affichage("X : " + QString::number(x) + "       Y : " + QString::number(y));
            if(flagEditerDepart){
                viewDefinirTache->champDepart->setText(affichage);
                viewDefinirTache->champDepart->show();
                viewDefinirTache->pushDefinirArrive->setEnabled(true);
                viewDefinirTache->switchBoutonLabelDefinir();
                viewDefinirTache->departX = x;
                viewDefinirTache->departY = y;
                flagEditerDepart = false;
            }else if(flagEditerArriver){
                viewDefinirTache->champArrive->setText(affichage);
                viewDefinirTache->champArrive->show();
                viewDefinirTache->switchBoutonLabelDefinir();
                viewDefinirTache->sauvegarder->setEnabled(true);
                viewDefinirTache->arriveX=x;
                viewDefinirTache->arriveY=y;
            }
        }else{
            switch (e->tab[x][y]){
                case MUR:
                    break;
                case VIDE:
                    //Armoire a;
                    //e.AddArmoire(a);
                    e->tab[x][y]=ARMOIREVIDE;
                    break;
                case ARMOIREVIDE:
                    e->tab[x][y]=ZONEDEP;
                    break;
                default:
                    e->tab[x][y]=VIDE;
                    break;
            }
            this->AfficherMap();
        }
    }
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
          if (e->tab[i][j] == MapScene::MUR)
            {
              image.load(":/res/images/mur.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
                item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Vide
          if (e->tab[i][j] == MapScene::VIDE)
            {
              image.load(":/res/images/vide.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Armoire
          if (e->tab[i][j] == MapScene::ARMOIREVIDE)
            {
              image.load(":/res/images/arm.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          if (e->tab[i][j] == MapScene::ARMOIREPLEINE)
            {
              image.load(":/res/images/armp.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //ZoneDepart
          if (e->tab[i][j] == MapScene::ZONEDEP)
            {
              image.load(":/res/images/dep.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Robot
          if (e->tab[i][j] > MapScene::ZONEDEP)
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
    GestionDB * db = GestionDB::getInstance();
    db->Requete("INSERT INTO entrepot (Nom_Entrepot,Longueur_Entrepot,Largeur_Entrepot) VALUES ('" + e->getNom() +
               "'," + QString::number(e->getLargeur()) + "," + QString::number(e->getLongueur()) + ")");
    db->Select("SELECT ID_Entrepot FROM entrepot ORDER BY ID_Entrepot DESC");
    e->setId(db->getResultat(0).toInt());


    //sauvegarde en base
    for (int i = 0; i < LONGUEUR; i++)
      {
        for (int j = 0; j < LARGEUR; j++)
          {
            //Armoire
            if (e->tab[i][j] == MapScene::ARMOIREVIDE)
              {
                db->Requete("INSERT INTO tile (X,Y,ID_Type,ID_Entrepot) VALUES (" + QString::number(i) + "," + QString::number(j) + ",1," + QString::number(e->getId()) + ")");
              }
            //Zone dep
            if (e->tab[i][j] == MapScene::ZONEDEP)
              {
                db->Requete("INSERT INTO tile (X,Y,ID_Type,ID_Entrepot) VALUES (" + QString::number(i) + "," + QString::number(j) + ",3," + QString::number(e->getId()) + ")");
              }
        }
    }

}

/**
 * @brief MapScene::setDepot
 * @param _e
 * redéfini le dépot
 */
void MapScene::setDepot(Entrepot *_e){
    e=new Entrepot();
    e->copieEntrepot(_e);
    e->RedefTab(e->getLongueur(),e->getLargeur());
}



void MapScene::entrerEnModeDefinitionTache(ViewDefinirTache * viewDefinirTache){
    flagEditionTache = true;
    this->viewDefinirTache = &*viewDefinirTache;

}







