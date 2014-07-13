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
    /***********AFFICHAGE DEBUG**************/
    QMap<int, Robot*>::iterator it;
    for (it = listeRobots.begin(); it != listeRobots.end(); ++it){
        Robot * robotTmp = it.value();
        qDebug() << "Robot " << robotTmp->getId() << " (" << robotTmp->getX()<< "," << robotTmp->getY() << ")";
        for(int t=0 ; t < robotTmp->listeTaches.getListeDesTaches()->size() ; t++){
            Tache * tacheTmp = robotTmp->listeTaches.getListeDesTaches()->at(t);
            qDebug() << "TacheRbt " << "Départ : " << tacheTmp->depart->getX() << " " << tacheTmp->depart->getY()
                     << "Arrivée : " << tacheTmp->arrivee->getX() << " " << tacheTmp->arrivee->getY() ;
        }
    }
    qDebug() << "Liste des taches au début";
    for(int t=0 ; t < taches.getListeDesTaches()->size() ; t++){
        Tache * tacheTmp = taches.getListeDesTaches()->at(t);
        qDebug() << "Tache " << "Départ : " << tacheTmp->depart->getX() << ", " << tacheTmp->depart->getY()
                 << "Arrivée : " << tacheTmp->arrivee->getX() << ", " << tacheTmp->arrivee->getY()
                 << "statut : " << tacheTmp->statut;
    }
    qDebug() << "--------------------------";
    /*****************************************/


    int i=0;
    Tache * tache = taches.getTacheNonEffectuee();
    while(tache!=NULL){
        qDebug() << "-----------"<< i++ << "-----------";
        for(int t=0 ; t < taches.getListeDesTaches()->size() ; t++){
            Tache * tacheTmp = taches.getListeDesTaches()->at(t);
            qDebug() << "Tache " << "Départ : " << tacheTmp->depart->getX() << ", " << tacheTmp->depart->getY()
                     << "Arrivée : " << tacheTmp->arrivee->getX() << ", " << tacheTmp->arrivee->getY()
                     << "statut : " << tacheTmp->statut;
        }
        qDebug() << "--------------------------";
        QMap<int, Robot*>::iterator it;
        for (it = listeRobots.begin(); it != listeRobots.end(); ++it){
            Robot * robotTmp = it.value();
            Tache * t = robotTmp->listeTaches.getTacheNonEffectuee();
            if(t!=NULL){
                Tile * objectif;
                if(t->statut == Tache::A_EFFECTUER){
                    objectif = t->depart;
                }else if(t->statut == Tache::CARGAISON_RECUP){
                    objectif = t->arrivee;
                }
                int objType = robotTmp->moveToObjectif(*entrepot, *objectif);
                qDebug() << " objectif type : " << objType;
                switch (objType) {
                    case MapScene::ARMOIREVIDE:
                        t->statut = Tache::CARGAISON_RECUP;
                        break;
                    case MapScene::ARMOIREPLEINE:
                        t->statut = Tache::EFFECTUEE;
                        break;
                    default:
                        break;
                }
                //t->statut = Tache::EFFECTUEE;
            }
            RaffraichirMap();
        }

        tache = taches.getTacheNonEffectuee();
    }

/*

    //Placement des robots sur l'entrepot
    for(int i=0; i < listeRobots.size() ; i++) {
        Robot robotTmp = listeRobots.at(i);
        entrepot->AddRobot(robotTmp);
    }
*/
    RaffraichirMap();


/*
    robot.setId(10);
    robot.setX(2);
    robot.setY(2);
    entrepot->AddRobot(robot);

    for(int i =0 ; i<5; i++){
        robot.move(*entrepot,robot.getX()+1,robot.getY());
        RaffraichirMap();
    }
*/

    /*
     * TantQue taches->getTacheNonEffectuee()!=null
     *      Pour chaque robot
     *          getTacheNonEffectuee()
     *          vitesse =0;
     *          avancerVersObjectif(); vitesse++; //tant que vitesseMax non ateinte
     *      FinPour
     * FinTantQue
     *
     * */

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
    QThread::msleep(20);
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
    db->selectMultiLignes("SELECT X,Y,ID_Type FROM tile WHERE ID_Entrepot=" + QString::number(id));
    for(int i = 0 ; i<db->resultatSelectMultiLignes.size();i++){
        qlistTemp = db->resultatSelectMultiLignes.at(i);
        int posX = qlistTemp.at(0).toInt();
        int posY = qlistTemp.at(1).toInt();
        int type = qlistTemp.at(2).toInt();
        if(type == MapScene::ZONEDEP)
            listeZonesDepart.append(Tile(posX,posY));
        entrepot->tab[posX][posY]=type;
    }
    db->selectMultiLignes("SELECT Nom_Entrepot,Longueur_Entrepot,Largeur_entrepot FROM entrepot WHERE ID_Entrepot=" + QString::number(id));
    for(int i = 0 ; i<db->resultatSelectMultiLignes.size();i++){
        qlistTemp = db->resultatSelectMultiLignes.at(i);
        entrepot->setNom(qlistTemp.at(0).toString());
        entrepot->setLongueur(qlistTemp.at(1).toInt());
        entrepot->setLargeur(qlistTemp.at(2).toInt());
    }

    qDebug()<< "Nb Zones départ : " << listeZonesDepart.size();
}

bool Simulation::ChargerEquipe(int ID_Equipe)
{
    GestionDB * db = GestionDB::getInstance();

    try{
        QString requeteSelect = "SELECT ID_Robot, Longueur_Robot, Largeur_Robot, Vitesse_Robot, Longueur_Capacite_De_Charge_Robot,";
        requeteSelect.append(" Largeur_Capactite_De_Charge_Robot, Poids_Capacite_De_Charge_Robot");
        requeteSelect.append(" FROM robot WHERE ID_Equipe = ");
        requeteSelect.append(QString::number(ID_Equipe));
        requeteSelect.append(";");
        db->selectMultiLignes(requeteSelect);
    }catch(exception e){
        qDebug()<<e.what();
    }

    qDebug()<< "Nb robots : " << db->resultatSelectMultiLignes.size();

    for(int i=0 ; i < db->resultatSelectMultiLignes.size() ; i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        if(qlistTemp.size() == 7){
            Robot * robotTemp = new Robot();
            robotTemp->setId(qlistTemp.at(0).toInt());

            //Placement du robot sur une Zone de Départ
            Tile zoneDepLibre = getZoneDepartLibre();
            if(zoneDepLibre.getX() == -1)
                return false;
            robotTemp->setCoordonnees(zoneDepLibre);
            entrepot->AddRobot(*robotTemp);

            listeRobots[robotTemp->getId()] = robotTemp;
        }
    }

    return true;
}

void Simulation::ChargerListeTaches(int ID_Liste_Taches)
{
    GestionDB * db = GestionDB::getInstance();

    try{
        QString requeteSelect = "SELECT ID_Robot, Poids_Tache, Depart_X, Depart_Y, Arrive_X, Arrive_Y";
        requeteSelect.append(" FROM tache WHERE ID_Liste_Taches = ");
        requeteSelect.append(QString::number(ID_Liste_Taches));
        requeteSelect.append(";");
        db->selectMultiLignes(requeteSelect);
    }catch(exception e){
        qDebug()<<e.what();
    }
    qDebug()<< "Nb taches : " << db->resultatSelectMultiLignes.size();

    for(int i=0 ; i < db->resultatSelectMultiLignes.size() ; i++){
        QList <QVariant> qlistTemp  = db->resultatSelectMultiLignes.at(i);
        if(qlistTemp.size() == 6){
            int ID_Robot = qlistTemp.at(0).toInt();
            double Poids_Tache = qlistTemp.at(2).toDouble();
            int Depart_X = qlistTemp.at(2).toInt();
            int Depart_Y = qlistTemp.at(3).toInt();
            int Arrive_X = qlistTemp.at(4).toInt();
            int Arrive_Y = qlistTemp.at(5).toInt();
            Tache * tacheTmp = new Tache(Poids_Tache, Depart_X, Depart_Y, Arrive_X, Arrive_Y);
            taches.ajoutTache(tacheTmp);
            listeRobots[ID_Robot]->listeTaches.ajoutTache(tacheTmp);
            //On remplit le départ
            entrepot->tab[Depart_X][Depart_Y] = MapScene::ARMOIREPLEINE;
        }
    }
}

Entrepot* Simulation::getEntrepot(){
    return entrepot;
}
