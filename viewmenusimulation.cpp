#include "viewmenusimulation.h"
#include <stdio.h>

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



}

void ViewMenuSimulation::definitionMainLayout(){


    layoutMenuChoixSauvegardCharger->addWidget(nouvelleSimulation);
    layoutMenuChoixSauvegardCharger->addWidget(chargerSimulation);

    layoutNomSimulation->addWidget(labelNomSimulation);
    layoutNomSimulation->addWidget(champNomSimulation);

    LayoutEquipe->addWidget(labelChoixEquipe,0,0,1,2);
    LayoutEquipe->addWidget(listeDeroulanteChoixEquipe,1,0,1,2);
    LayoutEquipe->addWidget(pushBloquerChoixEquipe,2,0);
    LayoutEquipe->addWidget(labelConfirmationEquipe,2,1);

    LayoutTache->addWidget(labelTache,0,0,1,2);
    LayoutTache->addWidget(boutonDefinirTache,1,0);
    LayoutTache->addWidget(labelConfirmationTache,1,1);

    LayoutSauvegarderAnnuler->addWidget(sauvegarderSimulation);
    LayoutSauvegarderAnnuler->addWidget(definirCommeSimulation);




    QWidget::connect(pushBloquerChoixEquipe,SIGNAL(clicked()),this,SLOT(bloquerSelectionEquipe()));
    QWidget::connect(nouvelleSimulation,SIGNAL(clicked()),this,SLOT(layoutNouvelleSimulation()));
    QWidget::connect(boutonDefinirTache,SIGNAL(clicked()),this,SLOT(executionViewMenuListeDesTaches()));


    mainLayout->addLayout(layoutMenuChoixSauvegardCharger);
    mainLayout->addLayout(layoutNomSimulation);
    mainLayout->addLayout(LayoutEquipe);
    mainLayout->addLayout(LayoutTache);
    mainLayout->addLayout(LayoutSauvegarderAnnuler);


    this->setLayout(mainLayout);
}


 void ViewMenuSimulation::definitionLayoutMenuChoixSauvegardeCharger(){
    labelNomSimulation->hide();
    champNomSimulation->hide();
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
    labelChoixEquipe->show();
    listeDeroulanteChoixEquipe->show();
    labelConfirmationEquipe->show();
    labelTache->show();
    boutonDefinirTache->show();
    labelConfirmationTache->show();
    sauvegarderSimulation->show();
    definirCommeSimulation->show();
    pushBloquerChoixEquipe->show();
    initialisationDeLaListeDeroulanteEquipe();
}


void ViewMenuSimulation::verificationlabelConfirmation(){
    if(confirmationEquipe){
        labelConfirmationEquipe->setText("Equipe selectionnée");
        labelConfirmationEquipe->setStyleSheet("QLabel { color : green; }");
    }else{
        labelConfirmationEquipe->setText("Aucune équipe selectionnée");
        labelConfirmationEquipe->setStyleSheet("QLabel { color : red; }");
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

    /* POUR TESTER A SUPPRIMER A remplacer par la fonction SQL ci dessou*/


    //chargeToutesLesEquipesDeLaBase();

    QString p = "equpe 1";
    QString o = "equpe 2";
    QString i = "equpe 3";

    Equipe a (1,p);
    Equipe b (2,o);
    Equipe c (3,i);

    listeEquipe->append(a);
    listeEquipe->append(b);
    listeEquipe->append(c);

    if(listeEquipe->size()>0){
        qDebug() << listeEquipe->size();
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

    /*A COMPLETER PAR ANTOINE POUR LA BASE DE DONNE */
    QString requeteSelect = "SELECT ID_Equipe, Nom_Equipe FROM EQUIPE";
}

/**
 * @brief ViewMenuSimulation::bloquerSelectionEquipe
 * Permet de valider une équipe selectionné dans la liste déroulante
 */
void ViewMenuSimulation::bloquerSelectionEquipe(){
    confirmationEquipe = true;

   /* qDebug() << listeDeroulanteChoixEquipe->currentText();
    qDebug() << listeDeroulanteChoixEquipe->currentData().toInt();*/

    equipeSelectionne = new Equipe( listeDeroulanteChoixEquipe->currentData().toInt(),listeDeroulanteChoixEquipe->currentText() );

    verificationlabelConfirmation();

}


















