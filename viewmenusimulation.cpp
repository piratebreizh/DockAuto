#include "viewmenusimulation.h"

ViewMenuSimulation::ViewMenuSimulation()
{
    initialisationComposantFenetreMenuSimulation();
    definitionMainLayout();
}


void ViewMenuSimulation::initialisationComposantFenetreMenuSimulation(){
    mainLayout = new QVBoxLayout(this);
    layoutMenuChoixSauvegardCharger = new QGridLayout();

    nouvelleSimulation = new QPushButton("Nouvelle simulation");
    chargerSimulation = new QPushButton("Charger simulation");

    labelNomSimulation = new QLabel("Nom simulation");
    champNomSimulation = new QLineEdit();
    labelChoixEquipe = new QLabel("Choix équipe");
    labelTache = new QLabel ("Définir tâche");
    labelConfirmationEquipe = new QLabel();
    labelConfirmationTache = new QLabel();

}

void ViewMenuSimulation::definitionMainLayout(){
    layoutMenuChoixSauvegardCharger->addWidget(nouvelleSimulation);
    layoutMenuChoixSauvegardCharger->addWidget(chargerSimulation);
    layoutMenuChoixSauvegardCharger->addWidget(labelNomSimulation);
    layoutMenuChoixSauvegardCharger->addWidget(champNomSimulation);
    layoutMenuChoixSauvegardCharger->addWidget(labelChoixEquipe);
    layoutMenuChoixSauvegardCharger->addWidget(boutonChoisirEquipe);
    layoutMenuChoixSauvegardCharger->addWidget(labelConfirmationEquipe);
    layoutMenuChoixSauvegardCharger->addWidget(labelTache);
    layoutMenuChoixSauvegardCharger->addWidget(boutonDefinirTache);
    layoutMenuChoixSauvegardCharger->addWidget(labelConfirmationTache);


    //QWidget::connect(nouvelleSimulation,SIGNAL(clicked()),this,SLOT(layoutNouvelleSimulation()));
    //QWidget::connect(chargerSimulation,SIGNAL(clicked()),this,SLOT(()));

    mainLayout->addLayout(layoutMenuChoixSauvegardCharger);

    this->setLayout(mainLayout);
}


void ViewMenuSimulation::definitionLayoutMenuChoixSauvegardeCharger(){
    labelNomSimulation->hide();
    champNomSimulation->hide();
    labelChoixEquipe->hide();
    boutonChoisirEquipe->hide();
    labelConfirmationEquipe->hide();
    boutonChoisirEquipe->hide();
    labelTache->hide();
    boutonDefinirTache->hide();
    labelConfirmationTache->hide();
}


/*void ViewMenuSimulation::layoutNouvelleSimulation(){
    nouvelleSimulation->hide();
    chargerSimulation->hide();

    labelNomSimulation->show();
    champNomSimulation->show();
    labelChoixEquipe->show();
    boutonChoisirEquipe->show();
    labelConfirmationEquipe->show();
    boutonChoisirEquipe->show();
    labelTache->show();
    boutonDefinirTache->show();
    labelConfirmationTache->show();
}*/
