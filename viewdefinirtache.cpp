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


    messageConfirmationAjout = new QLabel();
    messageConfirmationAjout->hide();

    labelRobot = new QLabel("Robot");
    listeDeroulanteRobot = new QComboBox();

    labelPoids = new QLabel("Poids");
    champPoids = new QLineEdit();
    champPoids->setValidator(new QDoubleValidator(champPoids));

    labelDepart = new QLabel("Départ");
    champDepart = new QLabel();
    champDepart->hide();
    pushDefinirDepart = new QPushButton("Définir");
    estDefinitDepart = false;

    labelArrive = new QLabel("Arrivée");
    champArrive = new QLabel();
    champArrive->hide();
    pushDefinirArrive = new QPushButton("Définir");
    pushDefinirArrive->setEnabled(false);
    estDefiniArrive =false;


    sauvegarder = new QPushButton("Ajouter la tâche");
    sauvegarder->setEnabled(false);
    annuler = new QPushButton("Annuler");

    QWidget::connect(pushDefinirDepart, SIGNAL(clicked()), this, SLOT(cliqueAjouterDepart()));
    QWidget::connect(pushDefinirArrive, SIGNAL(clicked()), this, SLOT(cliqueAjouterArrive()));
    QWidget::connect(sauvegarder, SIGNAL(clicked()), this, SLOT(ajouterNouvelleTacheALaListeDeTache()));
    QWidget::connect(sauvegarder, SIGNAL(clicked()), menuListeDesTaches, SLOT(ajouterTacheDansListe()));
    QWidget::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));

    chargerListeDeroulanteDesRobot();


}


void ViewDefinirTache::definitonLayout(){
    layoutMenuDroiteSelection->addWidget(messageConfirmationAjout,0,0,1,2);

    layoutMenuDroiteSelection->addWidget(labelRobot,1,0);
    layoutMenuDroiteSelection->addWidget(listeDeroulanteRobot,1,1);

    layoutMenuDroiteSelection->addWidget(labelPoids,2,0);
    layoutMenuDroiteSelection->addWidget(champPoids,2,1);

    layoutMenuDroiteSelection->addWidget(labelDepart,3,0);
    layoutMenuDroiteSelection->addWidget(champDepart,3,1);
    layoutMenuDroiteSelection->addWidget(pushDefinirDepart,3,1);


    layoutMenuDroiteSelection->addWidget(labelArrive,4,0);
    layoutMenuDroiteSelection->addWidget(champArrive,4,1);
    layoutMenuDroiteSelection->addWidget(pushDefinirArrive,4,1);

    layoutMenuDroiteSelection->addWidget(sauvegarder,5,0);
    layoutMenuDroiteSelection->addWidget(annuler,5,1);
    mainLayout->addLayout(layoutMenuDroiteSelection,1,1);

    this->setLayout(mainLayout);
}



void ViewDefinirTache::switchBoutonLabelDefinir(){
    if(estDefinitDepart){
        pushDefinirDepart->hide();
        champDepart->show();
        pushDefinirArrive->setEnabled(true);
    }else{
        pushDefinirDepart->show();
        champDepart->hide();
        pushDefinirArrive->setEnabled(false);
        sauvegarder->setEnabled(false);
    }

    if(estDefiniArrive){
        pushDefinirArrive->hide();
        champArrive->show();
        sauvegarder->setEnabled(true);
    }else{
         pushDefinirArrive->show();
         champArrive->hide();
         sauvegarder->setEnabled(false);
    }

}



/**
 * @brief ViewDefinirTache::chargerListeDeroulanteDesRobot
 * Charge toutes les robot présent dans l'équipe définit dans l'IHM ViewMenuSimulation
 */
void ViewDefinirTache::chargerListeDeroulanteDesRobot(){


    int ID_Equipe = menuListeDesTaches->viewMenuSimulation->equipeSelectionne->idEquipe;
    // A DECOMENTER
    chargerListeRobotEnBase(ID_Equipe);
    //qDebug() << ID_Equipe;


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


/**
 * @brief ViewDefinirTache::ajouterNouvelleTacheALaListeDeTache
 * se déclenche lors du click sur le bouton sauvegarder 'ajouter tache' pour l'inserrer dans la liste des tâches
 */
void ViewDefinirTache::ajouterNouvelleTacheALaListeDeTache(){

    menuListeDesTaches->nouveauRobotTemp->setId(listeDeroulanteRobot->currentData().toInt());
    menuListeDesTaches->nouveauRobotTemp->setNom(listeDeroulanteRobot->currentText().toStdString());

    menuListeDesTaches->nouvelleTacheTemp->setPoids(champPoids->text().replace(',','.').toDouble());

    // A MODIFIER
    menuListeDesTaches->nouvelleTacheTemp->setDepart(champDepart->text().toInt(),champDepart->text().toInt());

    // A MODIFIER
    menuListeDesTaches->nouvelleTacheTemp->setArrive(champDepart->text().toInt(),champDepart->text().toInt());


    messageConfirmationAjout->show();
    messageConfirmationAjout->setText("La nouvelle tâche a été rajouté");
    messageConfirmationAjout->setStyleSheet("QLabel { color : green; }");
    viderTousLesChamps();
}

void ViewDefinirTache::viderTousLesChamps(){
    estDefinitDepart = false;
    estDefiniArrive = false;
    champDepart->setText("");
    champArrive->setText("");
    switchBoutonLabelDefinir();
}


void ViewDefinirTache::cliqueAjouterDepart(){
    // A COMPLETER
    estDefinitDepart=true;
    champDepart->setText("22");
    switchBoutonLabelDefinir();

}

void ViewDefinirTache::cliqueAjouterArrive(){
    estDefiniArrive = true;
    champArrive->setText("33");
    switchBoutonLabelDefinir();
}



