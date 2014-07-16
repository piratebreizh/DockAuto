#include "viewcreationdepot.h"
#include "gestiondb.h"
#include "Entrepot.h"
#include <QString>
#include"mapscene.h"
#include "gestiondb.h"
#include <iostream>

ViewCreationDepot::ViewCreationDepot()
{
    positionneFenetre();
    initialisationComposantFenetreIdentificationDepot();
    definitionMainLayout();
}


void ViewCreationDepot::initialisationComposantFenetreIdentificationDepot()
{
    mainLayout = new QVBoxLayout(this);
    layout2pourFenetreIdentification = new QGridLayout();
    layout3PourBoutonSauvegarderAnnuler = new QGridLayout();

    labelNomDepot = new QLabel("Nom du dépôt");
    labelLongueurDepot = new QLabel("Hauteur (en nombre de cases)");
    labelLargeurDepot = new QLabel("Largeur (en nombre de cases)");
    labelMessageErreur = new QLabel();
    labelMessageErreur->hide();

    champNomDepot = new QLineEdit();
    champLongueurDepot = new QLineEdit();
    champLargeurDepot = new QLineEdit();

    champLongueurDepot->setValidator(new QIntValidator(champLongueurDepot));
    champLargeurDepot->setValidator(new QIntValidator(champLargeurDepot));

    sauvegarderEtEditerMap = new QPushButton("Sauvegarder et éditer la Map",this);
    annuler = new QPushButton("Annuler",this);

    QWidget::connect(sauvegarderEtEditerMap,SIGNAL(clicked()),this,SLOT(lancementFenetreCreationMap()));
    QWidget::connect(annuler,SIGNAL(clicked()),this,SLOT(close()));

}

void ViewCreationDepot::definitionMainLayout()
{
    layout2pourFenetreIdentification->addWidget(labelMessageErreur);
    layout2pourFenetreIdentification->addWidget(labelNomDepot,1,0);
    layout2pourFenetreIdentification->addWidget(champNomDepot,1,1);
    layout2pourFenetreIdentification->addWidget(labelLongueurDepot,2,0);
    layout2pourFenetreIdentification->addWidget(champLongueurDepot,2,1);
    layout2pourFenetreIdentification->addWidget(labelLargeurDepot,3,0);
    layout2pourFenetreIdentification->addWidget(champLargeurDepot,3,1);

    layout3PourBoutonSauvegarderAnnuler->addWidget(sauvegarderEtEditerMap,0,0);
    layout3PourBoutonSauvegarderAnnuler->addWidget(annuler,0,1);

    mainLayout->addLayout(layout2pourFenetreIdentification);
    mainLayout->addLayout(layout3PourBoutonSauvegarderAnnuler);

    this->setLayout(mainLayout);
}

/**
 * @brief Action du bouton Sauvegarder et Editer la Map
 *      Créer une nouvelle Map et la sauvegarde en base de données
 */
void ViewCreationDepot::lancementFenetreCreationMap()
{
    if(controleChamps() == true){
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
}
/**
 * @brief Masque tout le layout2 qui contient le nom , la longueur et la largeur d'un dépôt
 */
void ViewCreationDepot::masquerLayout2()
{
    labelNomDepot->hide();
    champNomDepot->hide();
    labelLongueurDepot->hide();
    champLongueurDepot->hide();
    labelLargeurDepot->hide();
    champLargeurDepot->hide();
    sauvegarderEtEditerMap->hide();
    annuler->hide();
    labelMessageErreur->hide();
}

/**
 * @brief Permet la création de la MAP en fonction de la longueur et largeur de case
 *      Lors de la sauvegarde
 * @return true si tout s'est bien passée
 */
bool ViewCreationDepot::initialisationDeLaMap()
{
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
 * @brief Sauvegarde de la map dans la base de données
 */
void ViewCreationDepot::SauvegardeMapDb()
{
    if(lamap->getNbZonesDepart()==0){
        this->labelMessageErreur->setText("Il doit y avoir au moins une zone de départ");
        this->labelMessageErreur->setStyleSheet("QLabel { color : red; }");
        this->labelMessageErreur->show();
    }else{
        sauvegardeModifMap->setEnabled(false);
        lamap->SaveDepotDb();
        this->close();
    }
}

/**
 * @brief Controle si tous les champs ont bien été remplis
 * @return true si c'est le cas sinon false
 */
bool ViewCreationDepot::controleChamps()
{
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
    if(largeur<5 || largeur>29 || longueur<5 || longueur>29){
        this->labelMessageErreur->setText("Les dimensions doivent être comprises entre 5 et 29");
        this->labelMessageErreur->setStyleSheet("QLabel { color : red; }");
        this->labelMessageErreur->show();
             return false;
     }

    return true;
}

/**
 * @brief Lance AfficherMap au clic sur la map
 */
void ViewCreationDepot::mousePressEvent()
{
    lamap->AfficherMap();
}

/**
 * @brief Positionne la fenêtre au centre de l'écran
 */
void ViewCreationDepot::positionneFenetre()
{
    const QRect screen = QApplication::desktop()->screenGeometry();
    const QPoint delta = QPoint(0,100);
    this->move( screen.center() - this->rect().center() - delta);
}
