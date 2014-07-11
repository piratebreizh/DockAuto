#include "simulation.h"
#include "MapScene.h"
#include <QThread>

Simulation::Simulation()
{
    entrepot = new Entrepot();

}

/**
 * @brief Lancement de la simulation
 * @return true En cas de succès de la simulation
 */
bool Simulation::LancerSimulation()
{

    for(int i=0; i < listeRobots.size() ; i++) {
        Robot robotTmp = listeRobots.at(i);
        qDebug() << robotTmp.getId() << " (" << robotTmp.getX()<< "," << robotTmp.getY() << ")";
    }


    for(int i=0; i < listeZonesDepart.size() ; i++) {
        Tile zoneDep = listeZonesDepart.at(i);
        qDebug() << i << " ZoneDep (" << zoneDep.getX()<< "," << zoneDep.getY() << ")";
    }


    for(int i=0; i < listeRobots.size() ; i++) {
        Tile zoneDepLibre = getZoneDepartLibre();
        if(zoneDepLibre.getX() == -1)
            return false;
        Robot robotTmp = listeRobots.at(i);
        robotTmp.setCoordonnees(zoneDepLibre);
        entrepot->AddRobot(robotTmp);
    }

    RaffraichirMap();


/*
    robot.setId(10);
    robot.setX(2);
    robot.setY(2);
    entrepot->AddRobot(robot);

    for(int i =0 ; i<5; i++){
        QThread::msleep(200);
        robot.move(*entrepot,robot.getX()+1,robot.getY());
        RaffraichirMap();
    }
*/

    //parcours de la liste des tâches
    //for chaque tache
        //effectue la tache (déplacement ou rangement)
        //tu peux utiliser les fonctions dans robot pour les déplacer
        //tu peux accéder au tableau par e.tab[][] (il est en public)
        //les constantes LONGEUR et LARGEUR définisse la taille max du tableau
    //fin for

    return true;
}

Tile Simulation::getZoneDepartLibre()
{
    Tile zoneDep = Tile(-1,-1);
    for(int i=0; i < listeZonesDepart.size() ; i++) {
        zoneDep = listeZonesDepart.at(i);
        if(entrepot->tab[zoneDep.getX()][zoneDep.getY()] == MapScene::ZONEDEP)
            return zoneDep;
    }
    return zoneDep;
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
            listeZonesDepart.append(Tile(posX,posY));
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

    qDebug()<< "Nb robots : " << db->resultatSelectMultiLignes.size();
    for(int i=0;i<db->resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        if(qlistTemp.size() == 7){
            Robot robotTemp ;
            robotTemp.setId(qlistTemp.at(0).toInt());

            listeRobots.append(robotTemp);
        }
    }

}

Entrepot* Simulation::getEntrepot(){
    return entrepot;
}
