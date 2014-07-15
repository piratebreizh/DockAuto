#include "FenetrePrincipale.h"
#include <QtWidgets>
#include <QMessageBox>

#include "simulation.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("DockAuto"));
    positionne();

    //initialisation mainlayout
    mainLayout = new QHBoxLayout();
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);

    createBarreDeLancement();
    createMap();
    verificationConnexionBaseDeDonnees();
}

/**
 * @brief Positionne la fenêtre au centre de l'écran
 */
void FenetrePrincipale::positionne()
{
    const QRect screen = QApplication::desktop()->screenGeometry();
    const QPoint delta = QPoint(0,100);
    this->move( screen.center() - this->rect().center() - delta);
}

void FenetrePrincipale::createBarreDeLancement()
{
    barreLancement = new QGridLayout;

    messageControl = new QLabel();
    messageControl->hide();


    gestionDesEquipe = new QPushButton(tr("&Gestion des équipes"));
    gestionDesEquipe->setFocusPolicy(Qt::NoFocus);

    nouvelleSimulation = new QPushButton(tr("&Simulation"));
    nouvelleSimulation->setFocusPolicy(Qt::NoFocus);
    gestionDesDepots = new QPushButton(tr("&Gestion des dépôts"));
    demarrerSimulation = new QPushButton(tr("&Start"));
    demarrerSimulation->setEnabled(false);
    demarrerSimulation->setFocusPolicy(Qt::NoFocus);
    pauseSimulation = new QPushButton(tr("&Stop"));
    pauseSimulation->setFocusPolicy(Qt::NoFocus);
    pauseSimulation->setEnabled(false);


    QLabel * labelImageArmoire = new QLabel();
    QLabel  * labelImageZoneDep = new QLabel();
    QLabel * labelImageMur = new QLabel();
    QLabel * labelImageRobot = new QLabel();

    labelImageArmoire->setPixmap(QPixmap(":/res/images/arm.png", 0, Qt::AutoColor));
    labelImageZoneDep->setPixmap(QPixmap(":/res/images/dep.png", 0, Qt::AutoColor));
    labelImageMur->setPixmap(QPixmap(":/res/images/mur.png", 0, Qt::AutoColor));
    labelImageRobot->setPixmap(QPixmap(":/res/images/rob.png", 0, Qt::AutoColor));



    barreLancement->addWidget(messageControl,0,0,1,2);
    barreLancement->addWidget(nouvelleSimulation,1,0,1,2);
    barreLancement->addWidget(gestionDesEquipe,2,0,1,2);
    barreLancement->addWidget(gestionDesDepots,3,0,1,2);
    barreLancement->addWidget(demarrerSimulation,4,0,1,2);
    barreLancement->addWidget(pauseSimulation,5,0,1,2);
    barreLancement->addWidget(new QLabel("Mur"),6,0,1,1);
    barreLancement->addWidget(labelImageMur,6,1,1,1);
    barreLancement->addWidget(new QLabel("Armoire"),7,0,1,1);
    barreLancement->addWidget(labelImageArmoire,7,1,1,1);
    barreLancement->addWidget(new QLabel("Zone de départ"),8,0,1,1);
    barreLancement->addWidget(labelImageZoneDep,8,1,1,1);
    barreLancement->addWidget(new QLabel("Robot"),9,0,1,1);
    barreLancement->addWidget(labelImageRobot,9,1,1,1);
    barreLancement->setSpacing(30);

    QWidget::connect(gestionDesEquipe, SIGNAL(clicked()), this, SLOT(lancementViewCreationEquipe()));
    QWidget::connect(gestionDesDepots, SIGNAL(clicked()), this, SLOT(lancementViewCreationDepot()));
    QWidget::connect(nouvelleSimulation, SIGNAL(clicked()), this, SLOT(lancementViewMenuSimulation()));
    QWidget::connect(demarrerSimulation, SIGNAL(clicked()), this, SLOT(lancerSimulation()));
    QWidget::connect(pauseSimulation, SIGNAL(clicked()), this, SLOT(arretSimulation()));

    mainLayout->addLayout(barreLancement);
}

void FenetrePrincipale::lancementViewCreationEquipe()
{
    viewGestionEquipe = new ViewGestionEquipe();
    viewGestionEquipe->exec();
}

void FenetrePrincipale::lancementViewCreationDepot()
{
    viewCreationDepot = new ViewCreationDepot();
    viewCreationDepot->exec();
}

void FenetrePrincipale::lancementViewMenuSimulation()
{
    viewMenuSimulation = new ViewMenuSimulation(this);
    viewMenuSimulation->exec();
}

void FenetrePrincipale::lancerSimulation()
{
    QMessageBox msgBox;
    bool lancerSimulationEnVrai = true;
    boolean resultat = simulation->LancerSimulation(false);


    if(resultat==false){
        QMessageBox::StandardButton confirmLancement;
        confirmLancement = QMessageBox::question(this,
                                                 "Erreur simulation",
                                                 "La simulation va échouer. Voulez-vous malgré tout la lancer ?",
                                                 QMessageBox::Yes|QMessageBox::No);
        if (confirmLancement == QMessageBox::Yes) {
            lancerSimulationEnVrai = true;
        } else {
            lancerSimulationEnVrai = false;
        }
    }
    if(lancerSimulationEnVrai){
        resetSimulation();
        resultat = simulation->LancerSimulation(true);
        if(resultat==true){
            msgBox.setText("La simulation s'est bien déroulée ! ");
        }else{
            msgBox.setText("La simulation a échouée !");
        }
        msgBox.exec();
    }
}


void FenetrePrincipale::createMap()
{
    map=new QGridLayout();
    scene = new QGraphicsScene();
    lamap = new MapScene(scene);
    lamap->lectureSeule = true;
    //Map
    vue = new QGraphicsView(lamap);
    vue->setMinimumSize(LONGUEUR*LONGUEURPIX+5,LONGUEUR*LONGUEURPIX+5);
    vue->setMaximumSize(LONGUEUR*LONGUEURPIX+5,LONGUEUR*LONGUEURPIX+5);
    vue->show();
    map->addWidget(vue);
    mainLayout->addLayout(map);
}

/*
 * Cette fonction est appelé lors de la définition d'une simulation dans l'interface Simulation (viewMenuSimulation)
 * Que ce soit une ancienne simulation ou une nouvelle
 * */
void FenetrePrincipale::definirSimulation(Simulation *_simulation)
{

    int iddep;
    simulation = _simulation;
    demarrerSimulation->setEnabled(true);
    pauseSimulation->setEnabled(true);
    GestionDB * db = GestionDB::getInstance();
    try{
        db->Select("SELECT Id_Entrepot, ID_Equipe, ID_Liste_Taches FROM simulation WHERE ID_Simulation=" + QString::number(simulation->IdSimulation));
    }catch(exception e){
        qDebug()<<e.what();
    }
    iddep = db->getResultat(0).toInt();
    simulation->ChargerDepot(iddep);
    int ID_Equipe = db->getResultat(1).toInt();
    simulation->ChargerEquipe(ID_Equipe);
    int ID_Liste_Taches = db->getResultat(2).toInt();
    simulation->ChargerListeTaches(ID_Liste_Taches);

    simulation->stopSimulation=false;

    simulation->mapScene = lamap;
    lamap->setDepot(simulation->getEntrepot());
    lamap->lectureSeule = true;
    lamap->AfficherMap();
}

void FenetrePrincipale::verificationConnexionBaseDeDonnees()
{
    GestionDB * db = GestionDB::getInstance();
    if(!db->baseConnecter()){
        messageControl->setText("Aucune connexion à la base de données \n Contacter votre administrateur informatique");
        messageControl->setStyleSheet("QLabel { color : red; }");
        messageControl->show();

        nouvelleSimulation->setEnabled(false);
        gestionDesDepots->setEnabled(false);
        gestionDesEquipe->setEnabled(false);
        demarrerSimulation->setEnabled(false);
        pauseSimulation->setEnabled(false);
    }
}

void FenetrePrincipale::arretSimulation()
{
    simulation->stopSimulation = true;
    this->demarrerSimulation->setEnabled(false);
    this->pauseSimulation->setEnabled(false);
}

void FenetrePrincipale::resetSimulation()
{
    Simulation * simReset = new Simulation();
    simReset->IdSimulation = simulation->IdSimulation;
    delete simulation;
    definirSimulation(simReset);
}
