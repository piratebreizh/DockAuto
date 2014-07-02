//http://fr.openclassrooms.com/forum/sujet/jeu-2d-tile-mapping-qt-93098s
//http://fr.openclassrooms.com/forum/sujet/quadrillage-sur-un-qgraphicsscene
//http://fr.openclassrooms.com/forum/sujet/dragamp-drop-dans-une-qgraphicsscene-75520

#include "viewcreationdepot.h"
#include "gestiondb.h"
#include "Entrepot.h"
#include <QString>
#include"mapscene.h"

ViewCreationDepot::ViewCreationDepot()
{
    initialisationConposantFenetreIdentificationDepot();

    definitionMainLayout();
}


void ViewCreationDepot::initialisationConposantFenetreIdentificationDepot(){
    mainLayout = new QVBoxLayout(this);
    layout2pourFenetreIdentification = new QGridLayout();
    layout3PourBoutonSauvegarderAnnuler = new QGridLayout();

    labelNomDepot = new QLabel("Nom du dépôt");
    labelLongueurDepot = new QLabel("Largeur (en nombre de case)");
    labelLargeurDepot = new QLabel("Longueur (en nombre de case)");
    labelMessageErreur = new QLabel();
    labelMessageErreur->hide();

    champNomDepot = new QLineEdit();
    champLongueurDepot = new QLineEdit();
    champLargeurDepot = new QLineEdit();

    champLongueurDepot->setValidator(new QIntValidator(champLongueurDepot));
    champLargeurDepot->setValidator(new QIntValidator(champLargeurDepot));

    sauvegardeEtEditerMap = new QPushButton("Sauvegarder et éditer la Map",this);
    annuler = new QPushButton("Annuler",this);

    QWidget::connect(sauvegardeEtEditerMap,SIGNAL(clicked()),this,SLOT(lancementFenetreCreationMap()));
    QWidget::connect(annuler,SIGNAL(clicked()),this,SLOT(close()));

}

void ViewCreationDepot::definitionMainLayout(){


    layout2pourFenetreIdentification->addWidget(labelMessageErreur);
    layout2pourFenetreIdentification->addWidget(labelNomDepot,1,0);
    layout2pourFenetreIdentification->addWidget(champNomDepot,1,1);
    layout2pourFenetreIdentification->addWidget(labelLongueurDepot,2,0);
    layout2pourFenetreIdentification->addWidget(champLongueurDepot,2,1);
    layout2pourFenetreIdentification->addWidget(labelLargeurDepot,3,0);
    layout2pourFenetreIdentification->addWidget(champLargeurDepot,3,1);

    layout3PourBoutonSauvegarderAnnuler->addWidget(sauvegardeEtEditerMap,0,0);
    layout3PourBoutonSauvegarderAnnuler->addWidget(annuler,0,1);

    mainLayout->addLayout(layout2pourFenetreIdentification);
    mainLayout->addLayout(layout3PourBoutonSauvegarderAnnuler);

    this->setLayout(mainLayout);
}

void ViewCreationDepot::lancementFenetreCreationMap(){

    if(controleTousChampsRempli() == true){
        masquerLayout2();
    }

    lamap = new MapScene(scene);

    //initialisation du depot
    lamap->setInfoDepot(champLargeurDepot->text().toInt(),champLongueurDepot->text().toInt(),champNomDepot->text());

    //Sauvegarde en bdd
    //lamap->SaveDepotDb();

    //Gestion de l'affichage de la map
    initialisationDeLaMap();

    //Affichage des éléments de la map
    AfficherMap(champLargeurDepot->text().toInt(),champLongueurDepot->text().toInt());

    //this->sauvegardeEtEdi     terMap->
    //mainLayout->removeItem(layout2pourFenetreIdentification);
    //mainLayout->removeItem(layout3PourBoutonSauvegarderAnnuler);
    //this->setLayout(mainLayout);*/
}
/**
 * @brief ViewCreationDepot::masquerLayout2
 * Masque tout le layout2 qui contient le nom , la longueur et la largeur d'un dépôt
 */

void ViewCreationDepot::masquerLayout2(){
    labelNomDepot->hide();
    champNomDepot->hide();
    labelLongueurDepot->hide();
    champLongueurDepot->hide();
    labelLargeurDepot->hide();
    champLargeurDepot->hide();
    sauvegardeEtEditerMap->hide();
    annuler->hide();
    labelMessageErreur->hide();
}


/**
 * @brief ViewCreationDepot::initialisationDeLaMap
 * Permet la création de la MAP en fonction de la longueur et largeur de case
 * Lors de la sauvegarde
 * @return true si tout c'est bien passé
 */
bool ViewCreationDepot::initialisationDeLaMap(){

    layoutpourLaVisualisationMap = new QGridLayout();
    layoutpourLesImages = new QGridLayout();
    vue = new QGraphicsView(lamap);
    vue->setMinimumSize(600,600);
    vue->setMaximumSize(600,600);
    vue->show();


    //LabelLesImages
    labelMur = new QLabel("Mur");
    labelRobot = new QLabel("Robot");
    labelArmoire = new QLabel("Armoire");
    labelZoneDep = new QLabel("Zone de départ");
    labelImageArmoire = new QLabel("");
    labelImageMur = new QLabel("");
    labelImageRobot = new QLabel("");
    labelImageZoneDep = new QLabel("");
    labelImageArmoire->setPixmap(QPixmap("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\arm.png", 0, Qt::AutoColor));
    labelImageZoneDep->setPixmap(QPixmap("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\dep.png", 0, Qt::AutoColor));
    labelImageMur->setPixmap(QPixmap("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\mur.png", 0, Qt::AutoColor));
    labelImageRobot->setPixmap(QPixmap("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\rob.png", 0, Qt::AutoColor));

    layoutpourLesImages->addWidget(labelArmoire,1,0);
    layoutpourLesImages->addWidget(labelImageArmoire,1,1);
    layoutpourLesImages->addWidget(labelMur,2,0);
    layoutpourLesImages->addWidget(labelImageMur,2,1);
    layoutpourLesImages->addWidget(labelZoneDep,1,2);
    layoutpourLesImages->addWidget(labelImageZoneDep,1,3);
    layoutpourLesImages->addWidget(labelRobot,2,2);
    layoutpourLesImages->addWidget(labelImageRobot,2,3);
    layoutpourLaVisualisationMap->addWidget(vue);

    mainLayout->addLayout(layoutpourLesImages);
    mainLayout->addLayout(layoutpourLaVisualisationMap);
}

/**
 * @brief ViewCreationDepot::controleTousChampRempli
 * Controle si tout les champs ont bien étaient remplis
 * @return true si tout les champs sont bien rempli false sinon
 */
bool ViewCreationDepot::controleTousChampsRempli(){
    if(this->champNomDepot->text().compare("")==0 ||
       this->champLargeurDepot->text().compare("")==0 ||
       this->champLongueurDepot->text().compare("")==0){
       this->labelMessageErreur->setText("Tous les champs sont obligatoires");
       this->labelMessageErreur->setStyleSheet("QLabel { color : red; }");
       this->labelMessageErreur->show();
            return false;
    }
    return true;

}

void ViewCreationDepot::AfficherMap(int lon, int larg )
{
  QGraphicsItem *item;
  QPixmap image;
  Entrepot e = lamap->getEntrepot();

  //Gestion de l'affichage
  for (int i = 0; i < LONGUEUR; i++)
    {
      for (int j = 0; j < LARGEUR; j++)
        {
          //Mur
          if (e.tab[i][j] == -1)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\mur.png", 0, Qt::AutoColor);
              item = lamap->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Vide
          if (e.tab[i][j] == 0)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\vide.png", 0, Qt::AutoColor);
              item = lamap->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Armoire
          if (e.tab[i][j] == 1)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\arm.png", 0, Qt::AutoColor);
              item = lamap->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //ZoneDepart
          if (e.tab[i][j] == 2)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\dep.png", 0, Qt::AutoColor);
              item = lamap->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
          //Robot
          if (e.tab[i][j] > 1)
            {
              image.load("C:\\Users\\Ludwig\\Documents\\COURS\\2013-2014\\Cpp\\Projet\\DockAuto\\res\\rob.png", 0, Qt::AutoColor);
              item = lamap->addPixmap(image);
              item->setPos(i*LONGUEURPIX, j*LARGEURPIX);
            }
        }
    }
}

void ViewCreationDepot::mousePressEvent(){
    AfficherMap(LONGUEUR,LARGEUR);
}
