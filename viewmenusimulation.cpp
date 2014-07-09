#include "viewmenusimulation.h"
#include <stdio.h>
#include <gestiondb.h>

ViewMenuSimulation::ViewMenuSimulation(FenetrePrincipale * _fenetrePrincipal)
{
    fenetrePrincipale = &*_fenetrePrincipal;
    initialisationComposantFenetreMenuSimulation();
    controleEquipeExist();
    controleDepotExist();
    controleSimulationExist();
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


    labelConfirmationEnregistremetnSimulation = new QLabel();
    labelConfirmationEnregistremetnSimulation->hide();
    sauvegarderSimulation = new QPushButton("Sauvegarder simulation");
    definirCommeSimulation =  new QPushButton("Définir comme simulation courante");
    pushRetour = new QPushButton("Retour");

    listeEquipe = new  QList<Equipe>;
    listeDepot = new QList<Entrepot>;

    simulation = new Simulation();

    messageControleDesDonneesExistante = new QString();

    listeDeroulanteChoixSimulationCharger = new QComboBox();
    definirSimulation = new QPushButton("Définir");
    labelSimulationChargerDefinit = new QLabel();
    LayoutSimulation = new QGridLayout();
    definirCommeSimualtionCharger = new QPushButton("Définir comme simulatin courante");

}

void ViewMenuSimulation::definitionMainLayout(){


    layoutMenuChoixSauvegardCharger->addWidget(nouvelleSimulation);
    layoutMenuChoixSauvegardCharger->addWidget(chargerSimulation);

    layoutNomSimulation->addWidget(labelConfirmationEnregistremetnSimulation);
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

    LayoutSimulation->addWidget(listeDeroulanteChoixSimulationCharger,1,0,1,2);
    LayoutSimulation->addWidget(definirSimulation,2,0);
    LayoutSimulation->addWidget(labelSimulationChargerDefinit,2,1);
    LayoutSimulation->addWidget(definirCommeSimualtionCharger,3,0,1,2);


    LayoutSauvegarderAnnuler->addWidget(sauvegarderSimulation);
    LayoutSauvegarderAnnuler->addWidget(definirCommeSimulation);
    LayoutSauvegarderAnnuler->addWidget(pushRetour);
    definirCommeSimulation->setEnabled(false);

    QWidget::connect(boutonDefinirDepot,SIGNAL(clicked()),this,SLOT(bloquerSelectionDepot()));
    QWidget::connect(pushBloquerChoixEquipe,SIGNAL(clicked()),this,SLOT(bloquerSelectionEquipe()));
    QWidget::connect(nouvelleSimulation,SIGNAL(clicked()),this,SLOT(layoutNouvelleSimulation()));
    QWidget::connect(chargerSimulation,SIGNAL(clicked()),this,SLOT(layoutChargerSimulation()));
    QWidget::connect(boutonDefinirTache,SIGNAL(clicked()),this,SLOT(executionViewMenuListeDesTaches()));
    QWidget::connect(sauvegarderSimulation,SIGNAL(clicked()),this,SLOT(cliqueSauvegarderSimulation()));
    QWidget::connect(definirCommeSimulation,SIGNAL(clicked()),this,SLOT(cliqueDefinirSimulation()));
    QWidget::connect(pushRetour,SIGNAL(clicked()),this,SLOT(close()));
    QWidget::connect(definirSimulation,SIGNAL(clicked()),this,SLOT(pushBoutonDefinirSimulationCharger()));
    QWidget::connect(definirCommeSimualtionCharger,SIGNAL(clicked()),this,SLOT(cliqueDefinirSimulationPourCharger()));





    mainLayout->addLayout(layoutMenuChoixSauvegardCharger);
    mainLayout->addLayout(layoutNomSimulation);
    mainLayout->addLayout(layoutDepot);
    mainLayout->addLayout(LayoutEquipe);
    mainLayout->addLayout(LayoutTache);
    mainLayout->addLayout(LayoutSimulation);
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

    listeDeroulanteChoixSimulationCharger->hide();
    definirSimulation->hide();
    labelSimulationChargerDefinit->hide();

    definirCommeSimualtionCharger->hide();
}


void ViewMenuSimulation::layoutNouvelleSimulation(){

    messageControleDesDonneesExistante->clear();
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
        sauvegarderSimulation->setEnabled(true);
    }else{
        labelConfirmationTache->setText("Aucune list de tâche");
        labelConfirmationTache->setStyleSheet("QLabel { color : red; }");
        sauvegarderSimulation->setEnabled(false);
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

    GestionDB * db = GestionDB::getInstance();
    try{
        db->selectMutliLigne("SELECT ID_Equipe, Nom_Equipe FROM equipe ;");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
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

    GestionDB * db = GestionDB::getInstance();
    try{
        db->selectMutliLigne("SELECT ID_Entrepot, Nom_Entrepot FROM entrepot");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
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
    qDebug()<<listeDeroulanteChoixEquipe->currentData().toInt();
    depotSelectionne = new Entrepot(listeDeroulanteChoixEquipe->currentData().toInt(),listeDeroulanteChoixEquipe->currentText());
    verificationlabelConfirmation();
}



void ViewMenuSimulation::setConfirmationTache(bool _tache){
    this->confirmationTache = _tache;
}


void ViewMenuSimulation::cliqueSauvegarderSimulation(){
    if(confirmationTache && confirmationEquipe && confirmationDepot && (champNomSimulation->text().size() != 0)){
        sauvegardeEnBaseDeLaSimulation();
        labelConfirmationEnregistremetnSimulation->setText("La nouvelle simulation a été sauvegardée");
        labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : green; }");
        labelConfirmationEnregistremetnSimulation->show();
        definirCommeSimulation->setEnabled(true);
        initialisationDelaSimulation();
    }else{
        labelConfirmationEnregistremetnSimulation->setText("Tous les champs doivent être remplis");
        labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : red; }");
        labelConfirmationEnregistremetnSimulation->show();
    }
}

void ViewMenuSimulation::sauvegardeEnBaseDeLaSimulation(){

    QString requeteInsert("INSERT INTO SIMULATION ( Nom_Simulation, ID_Entrepot, ID_Equipe, ID_Liste_Taches) VALUES ('");
    requeteInsert.append(this->champNomSimulation->text());
    requeteInsert.append("',");
    requeteInsert.append(QString::number(this->depotSelectionne->getId()));
    requeteInsert.append(",");
    requeteInsert.append(QString::number(this->equipeSelectionne->idEquipe));
    requeteInsert.append(",");
    requeteInsert.append(QString::number(this->viewMenuListeDesTaches->listeTache->IDListeTache));
    requeteInsert.append(");");
    GestionDB * db = GestionDB::getInstance();
    qDebug()<<requeteInsert;
    db->Requete(requeteInsert);
}

void ViewMenuSimulation::initialisationDelaSimulation(){
    simulation->IdSimulation = derniereIDSimulation();
    simulation->nomSimulation = new QString(champNomSimulation->text());
}

void ViewMenuSimulation::cliqueDefinirSimulation(){
    fenetrePrincipale->definirSimulation(simulation);
    labelConfirmationEnregistremetnSimulation->setText("Simulation définit");
    labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : orange; }");
    labelConfirmationEnregistremetnSimulation->show();
}


int ViewMenuSimulation::derniereIDSimulation(){
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT MAX(ID_Simulation) FROM simulation;");
    return  db->resultatSelectMultiLignes.at(0).at(0).toInt();
}



void ViewMenuSimulation::controleDepotExist(){
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT count(ID_Entrepot) FROM entrepot;");
    if(db->resultatSelectMultiLignes.at(0).at(0).toInt() == 0){
        messageControleDesDonneesExistante->append("La création d'une nouvelle simulation nécessite au moins un dépôt existant \n");
        labelConfirmationEnregistremetnSimulation->setText(*messageControleDesDonneesExistante);
        labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : red; }");
        labelConfirmationEnregistremetnSimulation->show();
        nouvelleSimulation->setEnabled(false);
    }
}

void ViewMenuSimulation::controleEquipeExist(){
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT count(ID_Equipe) FROM equipe;");
    int res1 = db->resultatSelectMultiLignes.at(0).at(0).toInt();

    db->selectMutliLigne("SELECT count(ID_Robot) FROM robot;");
    if(res1 == 0 || db->resultatSelectMultiLignes.at(0).at(0).toInt() == 0){
            messageControleDesDonneesExistante->append("La création d'une nouvelle simulation nécessite au moins une équipe existante \n");
            labelConfirmationEnregistremetnSimulation->setText(*messageControleDesDonneesExistante);
            labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : red; }");
            labelConfirmationEnregistremetnSimulation->show();
            nouvelleSimulation->setEnabled(false);
    }
}

void ViewMenuSimulation::controleSimulationExist(){
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT count(ID_Simulation) FROM simulation;");
    if(db->resultatSelectMultiLignes.at(0).at(0).toInt() == 0){
        messageControleDesDonneesExistante->append("Aucune simulation enregistré");
        labelConfirmationEnregistremetnSimulation->setText(*messageControleDesDonneesExistante);
        labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : red; }");
        labelConfirmationEnregistremetnSimulation->show();
        chargerSimulation->setEnabled(false);
    }
}


void ViewMenuSimulation::layoutChargerSimulation(){

    messageControleDesDonneesExistante->clear();
    nouvelleSimulation->hide();
    chargerSimulation->hide();

    labelSimulationChargerDefinit->setText("Aucune simulation définit");
    labelSimulationChargerDefinit->setStyleSheet("QLabel { color : red; }");

    listeDeroulanteChoixSimulationCharger->show();
    definirSimulation->show();
    labelSimulationChargerDefinit->show();
    definirCommeSimualtionCharger->show();
    chargerListeSimulationDepuisLaBase();
    //cliqueDefinirSimulation();
}


void ViewMenuSimulation::chargerListeSimulationDepuisLaBase(){
    GestionDB * db = GestionDB::getInstance();
    try{
        db->selectMutliLigne("SELECT ID_Simulation, Nom_Simulation FROM simulation");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        listeDeroulanteChoixSimulationCharger->addItem(qlistTemp.at(1).toString(),qlistTemp.at(0).toInt());
    }
}



void ViewMenuSimulation::pushBoutonDefinirSimulationCharger(){
    labelSimulationChargerDefinit->setText("Simulation selectionnée");
    labelSimulationChargerDefinit->setStyleSheet("QLabel { color : green; }");

    simulation = new Simulation();
    simulation->IdSimulation = listeDeroulanteChoixSimulationCharger->currentIndex();
    simulation->nomSimulation = new QString (listeDeroulanteChoixSimulationCharger->currentData().toString());
}



void ViewMenuSimulation::cliqueDefinirSimulationPourCharger(){

}
















