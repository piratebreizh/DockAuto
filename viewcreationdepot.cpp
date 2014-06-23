#include "viewcreationdepot.h"

ViewCreationDepot::ViewCreationDepot()
{
    initialisationCoposantFenetreIdentificationDepot();

    definitionMainLayout();
}


void ViewCreationDepot::initialisationCoposantFenetreIdentificationDepot(){
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

   initialisationDeLaMap();


    //this->sauvegardeEtEdi     terMap->
    //mainLayout->removeItem(layout2pourFenetreIdentification);
    //mainLayout->removeItem(layout3PourBoutonSauvegarderAnnuler);
    //this->setLayout(mainLayout);
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

    scene = new QGraphicsScene();
    vue = new QGraphicsView(scene);
    //Map m;
    //vue.setFixedSize(100,100);
    //mainLayout->addWidget(&vue);

    //this->setLayout(mainLayout);
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



//http://fr.openclassrooms.com/forum/sujet/jeu-2d-tile-mapping-qt-93098s
/*void viewEntrepot::initWindow()
{
  setWidth(520);
  setHeigth(520);
  setApple(0);
  setTete(0);
  setCorps(0);
  setQueue(0);
  setMur(0);
  scene = new QGraphicsScene;
}*/

void ViewCreationDepot::AfficherMap(int **tab, int size, QGraphicsScene *scene)
{
  QGraphicsItem *item;
  QPixmap image;
  int   width = 0;
  int   heigth = 0;

  /*for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
        {
          if (tab[i][j] == 1)
            {
              image.load("./res/mur.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 4)
            {
              image.load("./res/tete.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 2)
            {
              image.load("./res/queue.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 3)
            {
              image.load("./res/corps.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 7)
            {
              image.load("./res/apple.jpg", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 0)
            width += 20;
        }
      heigth += 20;
      width = 0;
    }*/
}







