#include "simulation.h"
#include "gestiondb.h"

Simulation::Simulation()
{
    e = new Entrepot();
}

/**
 * @brief Simulation::LancerSimulation
 * Lancement de la simulation
 */
void Simulation::LancerSimulation(){

    //parcours de la liste des tâches
    //for chaque tache
        //effectue la tache (déplacement ou rangement)
        //tu peux utiliser les fonctions dans robot pour les déplacer
        //tu peux accéder au tableau par e.tab[][] (il est en public)
        //les constantes LONGEUR et LARGEUR définisse la taille max du tableau
    //fin for
}
/**
 * @brief Simulation::ChargerDepot
 * @param id
 * Charge l'entrepot choisi
 */
void Simulation::ChargerDepot(int id){
QList <QVariant> qlistTemp;
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT X,Y,ID_Type FROM tile WHERE ID_Entrepot=" + QString::number(id));
    for(int i = 0 ; i<db->resultatSelectMultiLignes.size();i++){
        qlistTemp = db->resultatSelectMultiLignes.at(i);
        e->tab[qlistTemp.at(0).toInt()][qlistTemp.at(1).toInt()]=qlistTemp.at(2).toInt();
    }
    db->selectMutliLigne("SELECT Nom_Entrepot,Longueur_Entrepot,Largeur_entrepot FROM entrepot WHERE ID_Entrepot=" + QString::number(id));
    for(int i = 0 ; i<db->resultatSelectMultiLignes.size();i++){
        qlistTemp = db->resultatSelectMultiLignes.at(i);
        e->setNom(qlistTemp.at(0).toString());
        e->setLongueur(qlistTemp.at(1).toInt());
        e->setLargeur(qlistTemp.at(2).toInt());
    }
}

Entrepot* Simulation::getEntrepot(){
    return e;
}
