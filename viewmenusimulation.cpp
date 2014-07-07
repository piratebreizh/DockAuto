#include "viewmenusimulation.h"
#include <stdio.h>
#include <gestiondb.h>

ViewMenuSimulation::ViewMenuSimulation()
{
    initialisationComposantFenetreMenuSimulation();
    verificationlabelConfirmation();
    definitionMainLayout();
    definitionLayoutMenuChoixSauvegardeCharger();
}


void ViewMenuSimulation::initialisationComposantFenetreMenuSimulation(){
    mainLayout = new QVBoxLayout(this);
    layoutMenuChoixSauvegardCharger = new QGridLayout();
    LayoutEquipe = new QGridLayout();
    layoutNomSimulation= new QGridLayout();
    LayoutTache = new QGridLayout();
    LayoutSauvegarderAnnuler = new QGridLayout();

    nouvelleSimulation = new QPushButton("Nouvelle simulation");
    chargerSimulation = new QPushButton("Charger simulation");

    labelNomSimulation = new QLabel("Nom simulation");
    champNomSimulation = new QLineEdit();

    layoutDepot = new QGridLayout();
    labelDepot = new QLabel("Choix du dépôt");
    confirmationDepot = false;
    labelConfirmationDepot = new QLabel();
    boutonDefinirDepot = new QPushButton("Définir");
    listeDeroulanteChoixDepot = new QComboBox();

    labelChoixEquipe = new QLabel("Choix équipe");
    listeDeroulanteChoixEquipe = new QComboBox();
    pushBloquerChoixEquipe = new QPushButton("Définir");

    labelTache = new QLabel ("Définir tâche");
    boutonDefinirTache = new QPushButton("Définir");
    labelConfirmationEquipe = new QLabel();

    confirmationEquipe = false;
    labelConfirmationTache = new QLabel();
    confirmationTache = false;

    sauvegarderSimulation = new QPushButton("Sauvegarder simulation");
    definirCommeSimulation =  new QPushButton("Définir comme simulation courante");

   listeEquipe = new  QList<Equipe>;
   listeDepot = new QList<Entrepot>;

   simulation = new Simulation();

   // A SUPPRIMER !!!!!!!!!!!
   simulation->IdSimulation = 3;



}

void ViewMenuSimulation::definitionMainLayout(){


    layoutMenuChoixSauvegardCharger->addWidget(nouvelleSimulation);
    layoutMenuChoixSauvegardCharger->addWidget(chargerSimulation);

    layoutNomSimulation->addWidget(labelNomSimulation);
    layoutNomSimulation->addWidget(champNomSimulation);


    layoutDepot->addWidget(labelDepot,0,0,1,2);
    layoutDepot->addWidget(listeDeroulanteChoixDepot,1,0,1,2);
    layoutDepot->addWidget(boutonDefinirDepot,2,0);
    layoutDepot->addWidget(labelConfirmationDepot,2,1);

    LayoutEquipe->addWidget(labelChoixEquipe,0,0,1,2);
    LayoutEquipe->addWidget(listeDeroulanteChoixEquipe,1,0,1,2);
    LayoutEquipe->addWidget(pushBloquerChoixEquipe,2,0);
    LayoutEquipe->addWidget(labelConfirmationEquipe,2,1);

    LayoutTache->addWidget(labelTache,0,0,1,2);
    LayoutTache->addWidget(boutonDefinirTache,1,0);
    LayoutTache->addWidget(labelConfirmationTache,1,1);

    LayoutSauvegarderAnnuler->addWidget(sauvegarderSimulation);
    LayoutSauvegarderAnnuler->addWidget(definirCommeSimulation);



    QWidget::connect(boutonDefinirDepot,SIGNAL(clicked()),this,SLOT(bloquerSelectionDepot()));
    QWidget::connect(pushBloquerChoixEquipe,SIGNAL(clicked()),this,SLOT(bloquerSelectionEquipe()));
    QWidget::connect(nouvelleSimulation,SIGNAL(clicked()),this,SLOT(layoutNouvelleSimulation()));
    QWidget::connect(boutonDefinirTache,SIGNAL(clicked()),this,SLOT(executionViewMenuListeDesTaches()));


    mainLayout->addLayout(layoutMenuChoixSauvegardCharger);
    mainLayout->addLayout(layoutNomSimulation);
    mainLayout->addLayout(layoutDepot);
    mainLayout->addLayout(LayoutEquipe);
    mainLayout->addLayout(LayoutTache);
    mainLayout->addLayout(LayoutSauvegarderAnnuler);

    this->setLayout(mainLayout);
}


 void ViewMenuSimulation::definitionLayoutMenuChoixSauvegardeCharger(){
    labelNomSimulation->hide();
    champNomSimulation->hide();

    labelDepot->hide();
    labelConfirmationDepot->hide();
    boutonDefinirDepot->hide();
    listeDeroulanteChoixDepot->hide();

    labelChoixEquipe->hide();
    listeDeroulanteChoixEquipe->hide();
    labelConfirmationEquipe->hide();
    pushBloquerChoixEquipe->hide();

    labelTache->hide();
    boutonDefinirTache->hide();

    labelConfirmationTache->hide();
    sauvegarderSimulation->hide();
    definirCommeSimulation->hide();
}


void ViewMenuSimulation::layoutNouvelleSimulation(){
    nouvelleSimulation->hide();
    chargerSimulation->hide();

    labelNomSimulation->show();
    champNomSimulation->show();

    labelDepot->show();
    labelConfirmationDepot->show();
    boutonDefinirDepot->show();
    listeDeroulanteChoixDepot->show();

    labelChoixEquipe->show();
    listeDeroulanteChoixEquipe->show();
    labelConfirmationEquipe->show();

    labelTache->show();
    boutonDefinirTache->show();
    labelConfirmationTache->show();

    sauvegarderSimulation->show();
    definirCommeSimulation->show();
    pushBloquerChoixEquipe->show();

    initialisationDeLaListeDeroulanteDepot();
    initialisationDeLaListeDeroulanteEquipe();
}


void ViewMenuSimulation::verificationlabelConfirmation(){


    if(confirmationDepot){
        labelConfirmationDepot->setText("Dépôt selectionné");
        labelConfirmationDepot->setStyleSheet("QLabel { color : green; }");
        pushBloquerChoixEquipe->setEnabled(true);
    }else{
        labelConfirmationDepot->setText("Aucune dépôt selectionné");
        labelConfirmationDepot->setStyleSheet("QLabel { color : red; }");
        pushBloquerChoixEquipe->setEnabled(false);
    }

    if(confirmationEquipe){
        labelConfirmationEquipe->setText("Equipe selectionnée");
        labelConfirmationEquipe->setStyleSheet("QLabel { color : green; }");
        boutonDefinirTache->setEnabled(true);
    }else{
        labelConfirmationEquipe->setText("Aucune équipe selectionnée");
        labelConfirmationEquipe->setStyleSheet("QLabel { color : red; }");
        boutonDefinirTache->setEnabled(false);
    }

    if(confirmationTache){
        labelConfirmationTache->setText("Liste de tâches créée");
        labelConfirmationTache->setStyleSheet("QLabel { color : green; }");
    }else{
        labelConfirmationTache->setText("Aucune list de tâche");
        labelConfirmationTache->setStyleSheet("QLabel { color : red; }");
    }

}


void ViewMenuSimulation::executionViewMenuListeDesTaches(){

    viewMenuListeDesTaches = new ViewMenuListeDesTaches(this);
    viewMenuListeDesTaches->exec();
}


/**
 * @brief ViewMenuSimulation::initialisationDeLaListeDeroulanteEquipe
 * Initialise toutes les équipe dans la liste déroulante pour le choix de l'équipe
 */
void ViewMenuSimulation::initialisationDeLaListeDeroulanteEquipe(){


    chargeToutesLesEquipesDeLaBase();

    if(listeEquipe->size()>0){
        //qDebug() << listeEquipe->size();
        for (int i = 0; i<listeEquipe->size();i++) {
            Equipe equipeTemp  = listeEquipe->at(i);
            listeDeroulanteChoixEquipe->addItem(equipeTemp.nomEquipe2,equipeTemp.idEquipe);
        }
    }
}


/**
  * @brief ViewMenuSimulation::chargeToutesLesEquipesDeLaBase
  * recupertion de toutes les équipe de la base de données
  * */
void ViewMenuSimulation::chargeToutesLesEquipesDeLaBase(){

    GestionDB db;
    try{
        db.selectMutliLigne("SELECT ID_Equipe, Nom_Equipe FROM equipe ;");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db.reusltatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db.reusltatSelectMultiLignes.at(i);
        Equipe equipeTemp ;
        equipeTemp.idEquipe = qlistTemp.at(0).toInt();
        equipeTemp.nomEquipe2 = qlistTemp.at(1).toString();
        listeEquipe->append(equipeTemp);
    }

}

/**
 * @brief ViewMenuSimulation::bloquerSelectionEquipe
 * Permet de valider une équipe selectionné dans la liste déroulante et d'initilaser l'équipe selectionné
 */
void ViewMenuSimulation::bloquerSelectionEquipe(){

    // A COMPLETER RAJOUTER ICI DU CODE POUR VOIRS SI IL Y A PLUS OU MOINS DE ZONE DE DEPART QUE DE ROBOT DANS L EQUIPE
    confirmationEquipe = true;
   /* qDebug() << listeDeroulanteChoixEquipe->currentText();
    qDebug() << listeDeroulanteChoixEquipe->currentData().toInt();*/
    equipeSelectionne = new Equipe( listeDeroulanteChoixEquipe->currentData().toInt(),listeDeroulanteChoixEquipe->currentText() );
    verificationlabelConfirmation();
}





/**
 * @brief ViewMenuSimulation::initialisationDeLaListeDeroulanteDepot
 * Initialise tous les dépôt dans la liste déroulante pour le choix du dépôt
 */
void ViewMenuSimulation::initialisationDeLaListeDeroulanteDepot(){

    chargeToutesLesDepotsDeLaBase();


    if(listeDepot->size()>0){
        qDebug() << listeDepot->size();
        for (int i = 0; i<listeDepot->size();i++) {
            Entrepot depotTemp  = listeDepot->at(i);
            listeDeroulanteChoixDepot->addItem(QString::fromStdString(depotTemp.getNomMap()),depotTemp.getIDMap());
        }
    }
}


/**
  * @brief ViewMenuSimulation::chargeTousLesDepotDeLaBase
  * recupertion de tous les dépôt de la base de données
  * */
void ViewMenuSimulation::chargeToutesLesDepotsDeLaBase(){

    GestionDB db;
    try{
        db.selectMutliLigne("SELECT ID_Entrepot, Nom_Entrepot FROM entrepot");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db.reusltatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db.reusltatSelectMultiLignes.at(i);
        Entrepot entrepotTemp;
        entrepotTemp.setIDMap(qlistTemp.at(0).toInt());
        entrepotTemp.setNomMap(qlistTemp.at(1).toString().toStdString());
        listeDepot->append(entrepotTemp);
    }
}

/**
 * @brief ViewMenuSimulation::bloquerSelectionDepot
 * Permet de valider un depot selectionné dans la liste déroulante et d'initilaser le depot selectionné
 */
void ViewMenuSimulation::bloquerSelectionDepot(){
    confirmationDepot = true;
    depotSelectionne = new Entrepot(listeDeroulanteChoixEquipe->currentData().toInt(),listeDeroulanteChoixEquipe->currentText() );
    verificationlabelConfirmation();
}














