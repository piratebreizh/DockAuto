#include "viewdefinirtache.h"

ViewDefinirTache::ViewDefinirTache(ViewMenuListeDesTaches * _menuListeDesTaches)
{
    initialisationComposant();
    definitonLayout();
}


void ViewDefinirTache::initialisationComposant(){
    mainLayout = new QGridLayout();
    layoutMenuDroiteSelection = new QGridLayout();

    labelRobot = new QLabel("Robot");
    listeDeroulanteRobot = new QComboBox();
    labelPoids = new QLabel("Poids");
    champPoids = new QLineEdit();
    labelDepart = new QLabel("Départ");
    champDepart = new QLabel();
    labelArrive = new QLabel("Arrivée");
    champArrive = new QLabel();
    sauvegarder = new QPushButton("Sauvegarder");
    annuler = new QPushButton("Annuler");
}


void ViewDefinirTache::definitonLayout(){

    layoutMenuDroiteSelection->addWidget(labelRobot,1,0);
    layoutMenuDroiteSelection->addWidget(listeDeroulanteRobot,1,1);
    layoutMenuDroiteSelection->addWidget(labelPoids,2,0);
    layoutMenuDroiteSelection->addWidget(champPoids,2,1);
    layoutMenuDroiteSelection->addWidget(labelDepart,3,0);
    layoutMenuDroiteSelection->addWidget(champDepart,3,1);
    layoutMenuDroiteSelection->addWidget(labelArrive,4,0);
    layoutMenuDroiteSelection->addWidget(champArrive,4,1);
    layoutMenuDroiteSelection->addWidget(sauvegarder,5,0);
    layoutMenuDroiteSelection->addWidget(annuler,5,1);
    mainLayout->addLayout(layoutMenuDroiteSelection,1,1);

    this->setLayout(mainLayout);
}
