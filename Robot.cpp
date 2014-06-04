#include "Robot.h"
#include <string>
#include "Entrepot.h"

using namespace std;

Robot::Robot()
{
}

string Robot::getNom(){
    return nomRobot;
}

void Robot::setNom(string nom){
    nomRobot=nom;
}

int Robot::getId(){
    return idRobot;
}

void Robot::setId(int id){
    idRobot=id;
}

/**
 * @brief Robot::move
 * @param e
 * @param x
 * @param y
 * Deplacement du robot si l'emplacement est libre
 */
/*void Robot::move(Entrepot &e, int x, int y){
    if(e!=null && e.tab[x][y]==0){
        e.RemoveRobot(this);
        this->setX(x);
        this->setY(y);
        e.AddRobot(this);
    }
}*/
