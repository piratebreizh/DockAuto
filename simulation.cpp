#include "simulation.h"
#include "MapScene.h"
#include <QThread>

Simulation::Simulation()
{
    entrepot = new Entrepot();
    listeZonesDepart = new QList<Tile>();

}

/**
 * @brief Lancement de la simulation
 */
void Simulation::LancerSimulation()
{

    Robot robot;
    /*foreach (robot, listeRobots) {
        entrepot->AddRobot();
    }
    */
    robot.setId(10);
    robot.setX(2);
    robot.setY(2);
    entrepot->AddRobot(robot);

    for(int i =0 ; i<5; i++){
        QThread::msleep(200);
        robot.move(*entrepot,robot.getX()+1,robot.getY());
        RaffraichirMap();
    }

    //parcours de la liste des tâches
    //for chaque tache
        //effectue la tache (déplacement ou rangement)
        //tu peux utiliser les fonctions dans robot pour les déplacer
        //tu peux accéder au tableau par e.tab[][] (il est en public)
        //les constantes LONGEUR et LARGEUR définisse la taille max du tableau
    //fin for
}

/**
 * @brief Réaffiche la map avec l'entrepot courant
 */
void Simulation::RaffraichirMap()
{
    mapScene->setDepot(entrepot);
    mapScene->AfficherMap();
    mapScene->update();
    QApplication::processEvents();
}

/**
 * @brief Simulation::ChargerDepot
 * @param id
 * Charge l'entrepot choisi
 */
void Simulation::ChargerDepot(int id)
{
    QList <QVariant> qlistTemp;
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT X,Y,ID_Type FROM tile WHERE ID_Entrepot=" + QString::number(id));
    for(int i = 0 ; i<db->resultatSelectMultiLignes.size();i++){
        qlistTemp = db->resultatSelectMultiLignes.at(i);
        int posX = qlistTemp.at(0).toInt();
        int posY = qlistTemp.at(1).toInt();
        int type = qlistTemp.at(2).toInt();
        if(type == MapScene::ZONEDEP)
            listeZonesDepart->append(Tile(posX,posY));
        entrepot->tab[posX][posY]=type;
    }
    db->selectMutliLigne("SELECT Nom_Entrepot,Longueur_Entrepot,Largeur_entrepot FROM entrepot WHERE ID_Entrepot=" + QString::number(id));
    for(int i = 0 ; i<db->resultatSelectMultiLignes.size();i++){
        qlistTemp = db->resultatSelectMultiLignes.at(i);
        entrepot->setNom(qlistTemp.at(0).toString());
        entrepot->setLongueur(qlistTemp.at(1).toInt());
        entrepot->setLargeur(qlistTemp.at(2).toInt());
    }
}

void Simulation::ChargerEquipe(int ID_Equipe)
{
    GestionDB * db = GestionDB::getInstance();

    try{
        QString requeteSelect = "SELECT ID_Robot, Longueur_Robot, Largeur_Robot, Vitesse_Robot, Longueur_Capacite_De_Charge_Robot,";
        requeteSelect.append(" Largeur_Capactite_De_Charge_Robot, Poids_Capacite_De_Charge_Robot");
        requeteSelect.append(" FROM robot WHERE ID_Equipe = ");
        requeteSelect.append(QString::number(ID_Equipe));
        requeteSelect.append(";");
        db->selectMutliLigne(requeteSelect);
    }catch(exception e){
        qDebug()<<e.what();
    }

    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        if(qlistTemp.size() == 7){
            Robot robotTemp ;
            robotTemp.setId(qlistTemp.at(0).toInt());

            listeRobots->append(robotTemp);
        }
    }

}

Entrepot* Simulation::getEntrepot(){
    return entrepot;
}
