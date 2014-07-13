#include "FenetrePrincipale.h"
#include <QtWidgets>
//#include "ui_mainwindow.h"

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
    verficationConnexionBaseDeDonnee();
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

    barreLancement->addWidget(messageControl);
    barreLancement->addWidget(nouvelleSimulation);
    barreLancement->addWidget(gestionDesEquipe);
    barreLancement->addWidget(gestionDesDepots);
    barreLancement->addWidget(demarrerSimulation);
    barreLancement->addWidget(pauseSimulation);

    QWidget::connect(gestionDesEquipe, SIGNAL(clicked()), this, SLOT(lancementViewCreationEquipe()));
    QWidget::connect(gestionDesDepots, SIGNAL(clicked()), this, SLOT(lancementViewCreationDepot()));
    QWidget::connect(nouvelleSimulation, SIGNAL(clicked()), this, SLOT(lancementViewMenuSimulation()));
    QWidget::connect(demarrerSimulation, SIGNAL(clicked()), this, SLOT(lancerSimulation()));

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
    boolean resultat = simulation->LancerSimulation();
    qDebug() << "resultat simulation : " << resultat;
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
 * A VOUS DE CODER A PARTIR DE LA
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

    simulation->mapScene = lamap;
    lamap->setDepot(simulation->getEntrepot());
    lamap->lectureSeule = true;
    lamap->AfficherMap();
}



void FenetrePrincipale::verficationConnexionBaseDeDonnee(){
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
