//http://fr.openclassrooms.com/forum/sujet/jeu-2d-tile-mapping-qt-93098s
//http://fr.openclassrooms.com/forum/sujet/quadrillage-sur-un-qgraphicsscene
//http://fr.openclassrooms.com/forum/sujet/dragamp-drop-dans-une-qgraphicsscene-75520

#include "viewcreationdepot.h"
#include "gestiondb.h"
#include "Entrepot.h"
#include <QString>
#include"mapscene.h"
#include "gestiondb.h"
#include <iostream>

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

/**
 * @brief ViewCreationDepot::lancementFenetreCreationMap
 * Action du bouton Sauvegarder et Editer la Map
 * Créer un nouvelle Map et la sauvegarde en base de données
 */
void ViewCreationDepot::lancementFenetreCreationMap(){

    if(controleTousChampsRempli() == true){
        masquerLayout2();
    }else{
        return;
    }
    scene = new QGraphicsScene();
    lamap = new MapScene(scene);

    //initialisation du depot
    lamap->setInfoDepot(champLongueurDepot->text().toInt(),
                        champLargeurDepot->text().toInt(),
                        champNomDepot->text());

    //Gestion de l'affichage de la map
    initialisationDeLaMap();

    //Affichage des éléments de la map
    lamap->AfficherMap();

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

    //Init
    layoutpourLaVisualisationMap = new QGridLayout();
    layoutpourLesImages = new QGridLayout();
    layoutpourLaSauvegardeMap = new QGridLayout();

    //Map
    vue = new QGraphicsView(lamap);
    vue->setMinimumSize(LONGUEUR*LONGUEURPIX+5,LONGUEUR*LONGUEURPIX+5);
    vue->setMaximumSize(LONGUEUR*LONGUEURPIX+5,LONGUEUR*LONGUEURPIX+5);
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
    labelImageArmoire->setPixmap(QPixmap(":/res/images/arm.png", 0, Qt::AutoColor));
    labelImageZoneDep->setPixmap(QPixmap(":/res/images/dep.png", 0, Qt::AutoColor));
    labelImageMur->setPixmap(QPixmap(":/res/images/mur.png", 0, Qt::AutoColor));
    labelImageRobot->setPixmap(QPixmap(":/res/images/rob.png", 0, Qt::AutoColor));

    //Bouton sauvegarde db
    sauvegardeModifMap = new QPushButton("Sauvegarder",this);
    QWidget::connect(sauvegardeModifMap,SIGNAL(clicked()),this,SLOT(SauvegardeMapDb()));

    //GESTION DES LAYOUTS
    layoutpourLesImages->addWidget(labelArmoire,1,0);
    layoutpourLesImages->addWidget(labelImageArmoire,1,1);
    layoutpourLesImages->addWidget(labelMur,2,0);
    layoutpourLesImages->addWidget(labelImageMur,2,1);
    layoutpourLesImages->addWidget(labelZoneDep,1,2);
    layoutpourLesImages->addWidget(labelImageZoneDep,1,3);
    layoutpourLesImages->addWidget(labelRobot,2,2);
    layoutpourLesImages->addWidget(labelImageRobot,2,3);
    layoutpourLaVisualisationMap->addWidget(vue);
    layoutpourLaSauvegardeMap->addWidget(sauvegardeModifMap,1,0);

    mainLayout->addLayout(layoutpourLesImages);
    mainLayout->addLayout(layoutpourLaVisualisationMap);
    mainLayout->addLayout(layoutpourLaSauvegardeMap);

    return true;
}

/**
 * @brief ViewCreationDepot::SauvegardeMapDb
 * Sauvegarde de la map dans la base de données
 */
void ViewCreationDepot::SauvegardeMapDb(){
    lamap->SaveDepotDb();
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
    int largeur = this->champLargeurDepot->text().toInt();
    int longueur = this->champLongueurDepot->text().toInt();
    if(largeur<5 || largeur>30 || longueur<5 || longueur>30){
        this->labelMessageErreur->setText("Les dimensions doivent être comprise entre 5 et 30");
        this->labelMessageErreur->setStyleSheet("QLabel { color : red; }");
        this->labelMessageErreur->show();
             return false;
     }
    return true;

}

/**
 * @brief ViewCreationDepot::mousePressEvent
 * Lance AfficherMap au clic sur la map
 */
void ViewCreationDepot::mousePressEvent(){
    lamap->AfficherMap();
}
