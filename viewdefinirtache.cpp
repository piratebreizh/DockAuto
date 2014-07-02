#include "viewdefinirtache.h"

ViewDefinirTache::ViewDefinirTache(ViewMenuListeDesTaches * _menuListeDesTaches)
{
    menuListeDesTaches =  &*_menuListeDesTaches;
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

    //chargerListeDeroulanteDesRobot();


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

/**
 * @brief ViewDefinirTache::chargerListeDeroulanteDesRobot
 * Charge toutes les robot présent dans l'équipe définit dans l'IHM ViewMenuSimulation
 */
void ViewDefinirTache::chargerListeDeroulanteDesRobot(){
    if(menuListeDesTaches->viewMenuSimulation->equipeSelectionne != NULL && menuListeDesTaches->viewMenuSimulation->equipeSelectionne->nomEquipe2 != NULL ){

        int ID_Equipe = menuListeDesTaches->viewMenuSimulation->equipeSelectionne->idEquipe;
        // A DECOMENTER
        //chargerListeRobotEnBase(ID_Equipe);
        //qDebug() << ID_Equipe;
    }else{
        //qDebug() << "Equipe NULL";
    }

    if(listeRobot->size()>0){
        qDebug() << listeRobot->size();
        for (int i = 0; i<listeRobot->size();i++) {
            Robot robotTemp  = listeRobot->at(i);
            listeDeroulanteRobot->addItem(robotTemp.nomRobot2,robotTemp.getId());        }
    }
}

/**
 * @brief ViewDefinirTache::chargerListeRobotEnBase
 *  Charge à partir d'une ID_EQUIPE la liste des robots
 */
void ViewDefinirTache::chargerListeRobotEnBase(int ID_Equipe){
    /* A COMPLETER ET SUPPRIMER LES TESTS */
    QString requetteSelect = "SELECT ID_Robot, Nom_Robot FROM robot WHERE ID_Equipe = ";
    requetteSelect.append(ID_Equipe);
    requetteSelect.append( " ;");

    listeRobot = new QList<Robot>;
    //TEST !!! en attente de connexion a la base de donnée
    QString p = "Robot 1";
    QString o = "Robot 2";
    QString i = "Robot 3";

    Robot a (1,p);
    Robot b (2,o);
    Robot c (3,i);

    listeRobot->append(a);
    listeRobot->append(b);
    listeRobot->append(c);

}






