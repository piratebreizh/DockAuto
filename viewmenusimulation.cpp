#include "viewmenusimulation.h"
#include <stdio.h>
#include <gestiondb.h>

ViewMenuSimulation::ViewMenuSimulation(FenetrePrincipale * _fenetrePrincipal)
{
    fenetrePrincipale = &*_fenetrePrincipal;
    initialisationComposantsFenetreMenuSimulation();
    controleEquipeExist();
    controleDepotExist();
    controleSimulationExist();
    verificationLabelConfirmation();
    definitionMainLayout();
    definitionLayoutMenuChoixSauvegardeCharger();
}


void ViewMenuSimulation::initialisationComposantsFenetreMenuSimulation()
{
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
    labelSimulationChargeeDefinie = new QLabel();
    LayoutSimulation = new QGridLayout();
    definirCommeSimulationChargee = new QPushButton("Définir comme simulation courante");
}

void ViewMenuSimulation::definitionMainLayout()
{
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
    LayoutSimulation->addWidget(labelSimulationChargeeDefinie,2,1);
    LayoutSimulation->addWidget(definirCommeSimulationChargee,3,0,1,2);


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
    QWidget::connect(definirCommeSimulationChargee,SIGNAL(clicked()),this,SLOT(cliqueDefinirSimulation()));

    mainLayout->addLayout(layoutMenuChoixSauvegardCharger);
    mainLayout->addLayout(layoutNomSimulation);
    mainLayout->addLayout(layoutDepot);
    mainLayout->addLayout(LayoutEquipe);
    mainLayout->addLayout(LayoutTache);
    mainLayout->addLayout(LayoutSimulation);
    mainLayout->addLayout(LayoutSauvegarderAnnuler);

    this->setLayout(mainLayout);
}

 void ViewMenuSimulation::definitionLayoutMenuChoixSauvegardeCharger()
 {
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
    labelSimulationChargeeDefinie->hide();

    definirCommeSimulationChargee->hide();
}


void ViewMenuSimulation::layoutNouvelleSimulation()
{
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


void ViewMenuSimulation::verificationLabelConfirmation()
{
    if(confirmationDepot){
        labelConfirmationDepot->setText("Dépôt sélectionné");
        labelConfirmationDepot->setStyleSheet("QLabel { color : green; }");
        pushBloquerChoixEquipe->setEnabled(true);
    }else{
        labelConfirmationDepot->setText("Aucun dépôt sélectionné");
        labelConfirmationDepot->setStyleSheet("QLabel { color : red; }");
        pushBloquerChoixEquipe->setEnabled(false);
    }

    if(confirmationEquipe){
        labelConfirmationEquipe->setText("Equipe sélectionnée");
        labelConfirmationEquipe->setStyleSheet("QLabel { color : green; }");
        boutonDefinirTache->setEnabled(true);
    }else{
        labelConfirmationEquipe->setText("Aucune équipe sélectionnée");
        labelConfirmationEquipe->setStyleSheet("QLabel { color : red; }");
        boutonDefinirTache->setEnabled(false);
    }

    if(confirmationTache){
        labelConfirmationTache->setText("Liste de tâches créée");
        labelConfirmationTache->setStyleSheet("QLabel { color : green; }");
        sauvegarderSimulation->setEnabled(true);
    }else{
        labelConfirmationTache->setText("Aucune liste de tâches");
        labelConfirmationTache->setStyleSheet("QLabel { color : red; }");
        sauvegarderSimulation->setEnabled(false);
    }
}

void ViewMenuSimulation::executionViewMenuListeDesTaches()
{
    viewMenuListeDesTaches = new ViewMenuListeDesTaches(this);
    viewMenuListeDesTaches->exec();
}


/**
 * @brief Initialise toutes les équipes dans la liste déroulante pour le choix de l'équipe
 */
void ViewMenuSimulation::initialisationDeLaListeDeroulanteEquipe()
{
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
  * @brief Récuperation de toutes les équipes de la base de données
  */
void ViewMenuSimulation::chargeToutesLesEquipesDeLaBase()
{
    GestionDB * db = GestionDB::getInstance();
    try{
        db->selectMutliLigne("SELECT ID_Equipe, Nom_Equipe FROM equipe ;");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        if(qlistTemp.size()==2){
            Equipe equipeTemp ;
            equipeTemp.idEquipe = qlistTemp.at(0).toInt();
            equipeTemp.nomEquipe2 = qlistTemp.at(1).toString();
            listeEquipe->append(equipeTemp);
        }
    }

}

/**
 * @brief Permet de valider une équipe selectionné dans la liste déroulante
 *      et d'initilaser l'équipe selectionné
 */
void ViewMenuSimulation::bloquerSelectionEquipe()
{
    //TODO : RAJOUTER ICI DU CODE POUR VOIRS SI IL Y A PLUS OU MOINS DE ZONE DE DEPART QUE DE ROBOT DANS L EQUIPE
    confirmationEquipe = true;

    /*
    qDebug() << listeDeroulanteChoixEquipe->currentText();
    qDebug() << listeDeroulanteChoixEquipe->currentData().toInt();
    */

    equipeSelectionne = new Equipe( listeDeroulanteChoixEquipe->currentData().toInt(),listeDeroulanteChoixEquipe->currentText() );
    verificationLabelConfirmation();
}


/**
 * @brief Initialise tous les dépôts dans la liste déroulante pour le choix du dépôt
 */
void ViewMenuSimulation::initialisationDeLaListeDeroulanteDepot()
{
    chargeTousLesDepotsDeLaBase();

    if(listeDepot->size()>0){
        for (int i = 0; i<listeDepot->size();i++) {
            Entrepot depotTemp  = listeDepot->at(i);
            listeDeroulanteChoixDepot->addItem(QString::fromStdString(depotTemp.getNomMap()),depotTemp.getId());
        }
    }
}

/**
  * @brief Récuperation de tous les dépôts de la base de données
  */
void ViewMenuSimulation::chargeTousLesDepotsDeLaBase()
{
    GestionDB * db = GestionDB::getInstance();
    try{
        db->selectMutliLigne("SELECT ID_Entrepot, Nom_Entrepot FROM entrepot");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        Entrepot entrepotTemp;
        if(qlistTemp.size() == 2){
            entrepotTemp.setId(qlistTemp.at(0).toInt());
            entrepotTemp.setNomMap(qlistTemp.at(1).toString().toStdString());
            listeDepot->append(entrepotTemp);
        }
    }
}

/**
 * @brief Permet de valider un dépôt sélectionné dans la liste déroulante
 *      et d'initialiser le dépôt sélectionné
 */
void ViewMenuSimulation::bloquerSelectionDepot()
{
    confirmationDepot = true;
    depotSelectionne = new Entrepot(listeDeroulanteChoixDepot->currentData().toInt(),listeDeroulanteChoixDepot->currentText());
    verificationLabelConfirmation();
}

void ViewMenuSimulation::setConfirmationTache(bool _tache)
{
    this->confirmationTache = _tache;
}

void ViewMenuSimulation::cliqueSauvegarderSimulation()
{
    if(confirmationTache
            && confirmationEquipe
            && confirmationDepot
            && (champNomSimulation->text().size() != 0)){
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

void ViewMenuSimulation::sauvegardeEnBaseDeLaSimulation()
{
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
    db->Requete(requeteInsert);
}

void ViewMenuSimulation::initialisationDelaSimulation()
{
    simulation->IdSimulation = derniereIDSimulation();
    simulation->nomSimulation = new QString(champNomSimulation->text());
}

void ViewMenuSimulation::cliqueDefinirSimulation()
{
    fenetrePrincipale->definirSimulation(simulation);
    labelConfirmationEnregistremetnSimulation->setText("Simulation définie");
    labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : orange; }");
    labelConfirmationEnregistremetnSimulation->show();
}

int ViewMenuSimulation::derniereIDSimulation()
{
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT MAX(ID_Simulation) FROM simulation;");
    return  db->resultatSelectMultiLignes.at(0).at(0).toInt();
}

void ViewMenuSimulation::controleDepotExist()
{
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

void ViewMenuSimulation::controleEquipeExist()
{
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

void ViewMenuSimulation::controleSimulationExist()
{
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT count(*) FROM simulation;");
    if(db->resultatSelectMultiLignes.at(0).at(0).toInt() == 0){
        messageControleDesDonneesExistante->append("Aucune simulation enregistré");
        labelConfirmationEnregistremetnSimulation->setText(*messageControleDesDonneesExistante);
        labelConfirmationEnregistremetnSimulation->setStyleSheet("QLabel { color : red; }");
        labelConfirmationEnregistremetnSimulation->show();
        chargerSimulation->setEnabled(false);
    }
}

void ViewMenuSimulation::layoutChargerSimulation()
{
    messageControleDesDonneesExistante->clear();
    nouvelleSimulation->hide();
    chargerSimulation->hide();

    labelSimulationChargeeDefinie->setText("Aucune simulation définie");
    labelSimulationChargeeDefinie->setStyleSheet("QLabel { color : red; }");

    listeDeroulanteChoixSimulationCharger->show();
    definirSimulation->show();
    labelSimulationChargeeDefinie->show();
    definirCommeSimulationChargee->show();
    chargerListeSimulationDepuisLaBase();
    //cliqueDefinirSimulation();
}

void ViewMenuSimulation::chargerListeSimulationDepuisLaBase()
{
    GestionDB * db = GestionDB::getInstance();
    try{
        db->selectMutliLigne("SELECT ID_Simulation, Nom_Simulation FROM simulation");
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        if(qlistTemp.size()==2)
            listeDeroulanteChoixSimulationCharger->addItem(qlistTemp.at(1).toString(),qlistTemp.at(0).toInt());
    }
}

void ViewMenuSimulation::pushBoutonDefinirSimulationCharger()
{
    labelSimulationChargeeDefinie->setText("Simulation sélectionnée");
    labelSimulationChargeeDefinie->setStyleSheet("QLabel { color : green; }");

    simulation = new Simulation();
    simulation->IdSimulation = listeDeroulanteChoixSimulationCharger->currentData().toInt();
    simulation->nomSimulation = new QString (listeDeroulanteChoixSimulationCharger->currentText());
}
