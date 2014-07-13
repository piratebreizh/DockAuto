#include "viewdefinirtache.h"
#include <gestiondb.h>

ViewDefinirTache::ViewDefinirTache(ViewMenuListeDesTaches * _menuListeDesTaches)
{
    positionneFenetre();
    menuListeDesTaches =  &*_menuListeDesTaches;
    initialisationComposant();
    definitonLayout();
}

void ViewDefinirTache::initialisationComposant()
{
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
    annuler = new QPushButton("Retour");


    this->menuListeDesTaches->viewMenuSimulation->simulation->ChargerDepot(this->menuListeDesTaches->viewMenuSimulation->depotSelectionne->getId());
    map=new QGridLayout();
    scene = new QGraphicsScene();
    lamap = new MapScene(scene);
    lamap->setDepot(this->menuListeDesTaches->viewMenuSimulation->simulation->getEntrepot());
    //lamap->lectureSeule = true;
    lamap->AfficherMap();
    lamap->entrerEnModeDefinitionTache(this);

    //Map
    vue = new QGraphicsView(lamap);
    vue->setMinimumSize(LONGUEUR*LONGUEURPIX+5,LONGUEUR*LONGUEURPIX+5);
    vue->setMaximumSize(LONGUEUR*LONGUEURPIX+5,LONGUEUR*LONGUEURPIX+5);

    QWidget::connect(pushDefinirDepart, SIGNAL(clicked()), this, SLOT(cliqueAjouterDepart()));
    QWidget::connect(pushDefinirArrive, SIGNAL(clicked()), this, SLOT(cliqueAjouterArrive()));
    QWidget::connect(sauvegarder, SIGNAL(clicked()), this, SLOT(ajouterNouvelleTacheALaListeDeTache()));
    QWidget::connect(sauvegarder, SIGNAL(clicked()), menuListeDesTaches, SLOT(ajouterTacheDansListe()));
    QWidget::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));

    chargerListeDeroulanteDesRobots();
}

void ViewDefinirTache::definitonLayout()
{
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

    map->addWidget(vue);

    mainLayout->addLayout(map,0,0,20,1);
    mainLayout->addLayout(layoutMenuDroiteSelection,0,1);

    this->setLayout(mainLayout);
}

void ViewDefinirTache::switchBoutonLabelDefinir()
{
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
 * @brief Charge toutes les robot présent dans l'équipe définit dans l'IHM ViewMenuSimulation
 */
void ViewDefinirTache::chargerListeDeroulanteDesRobots()
{
    int ID_Equipe = menuListeDesTaches->viewMenuSimulation->equipeSelectionne->idEquipe;

    chargerListeRobotEnBase(ID_Equipe);

    if(listeRobot->size()>0){
        for (int i = 0; i<listeRobot->size();i++) {
            Robot robotTemp  = listeRobot->at(i);
            listeDeroulanteRobot->addItem(robotTemp.nomRobot,robotTemp.getId());
        }
    }
}

/**
 * @brief Charge à partir d'une ID_EQUIPE la liste des robots
 */
void ViewDefinirTache::chargerListeRobotEnBase(int ID_Equipe)
{
    listeRobot = new QList<Robot>;

    GestionDB * db = GestionDB::getInstance();
    try{
        QString requetteSelect = "SELECT ID_Robot, Nom_Robot FROM robot WHERE ID_Equipe = ";
        requetteSelect.append(QString::number(ID_Equipe));
        requetteSelect.append(";");
        db->selectMutliLigne(requetteSelect);
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        if(qlistTemp.size() == 2){
            Robot robotTemp ;
            robotTemp.setId(qlistTemp.at(0).toInt());
            robotTemp.nomRobot=qlistTemp.at(1).toString();
            listeRobot->append(robotTemp);
        }
    }
}

/**
 * @brief Se déclenche lors du click sur le bouton sauvegarder 'ajouter tache'
 *      pour l'insérer dans la liste des tâches
 */
void ViewDefinirTache::ajouterNouvelleTacheALaListeDeTache()
{
    menuListeDesTaches->nouvelleTacheTemp = new Tache();

    menuListeDesTaches->nouveauRobotTemp->setId(listeDeroulanteRobot->currentData().toInt());
    menuListeDesTaches->nouveauRobotTemp->setNom(listeDeroulanteRobot->currentText().toStdString());

    menuListeDesTaches->nouvelleTacheTemp->setPoids(champPoids->text().replace(',','.').toDouble());

    // A MODIFIER
    menuListeDesTaches->nouvelleTacheTemp->depart->setX(departX);
    menuListeDesTaches->nouvelleTacheTemp->depart->setY(departY);

    // A MODIFER
    menuListeDesTaches->nouvelleTacheTemp->arrivee->setX(arriveX);
    menuListeDesTaches->nouvelleTacheTemp->arrivee->setY(arriveY);

    menuListeDesTaches->listeTache->ajoutTache(menuListeDesTaches->nouvelleTacheTemp);

    messageConfirmationAjout->show();
    messageConfirmationAjout->setText("La nouvelle tâche a été ajoutée");
    messageConfirmationAjout->setStyleSheet("QLabel { color : green; }");
    viderTousLesChamps();
}

void ViewDefinirTache::viderTousLesChamps()
{
    estDefinitDepart = false;
    estDefiniArrive = false;
    champDepart->setText("");
    champArrive->setText("");
    switchBoutonLabelDefinir();
}

void ViewDefinirTache::cliqueAjouterDepart()
{
    estDefinitDepart = true;
    lamap->flagEditerDepart = true;
    lamap->flagEditerArriver = false;
}

void ViewDefinirTache::cliqueAjouterArrive(){
    estDefiniArrive = true;
    lamap->flagEditerDepart = false;
    lamap->flagEditerArriver = true;
}

/**
 * @brief Positionne la fenêtre au centre de l'écran
 */
void ViewDefinirTache::positionneFenetre()
{
    const QRect screen = QApplication::desktop()->screenGeometry();
    const QPoint delta = QPoint(0,100);
    this->move( screen.center() - this->rect().center() - delta);
}
