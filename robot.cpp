#include "Robot.h"
#include <string>
#include "Entrepot.h"

using namespace std;

Robot::Robot()
{
    idRobot=1;
    nomRobot="";
    this->setX(0);
    this->setY(0);
}

Robot::Robot(int _id, string _nom){
    idRobot=_id;
    nomRobot=_nom;
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
void Robot::move(Entrepot &e, int x, int y){
    //if(e!=NULL && e.tab[x][y]==0){
    if(e.tab[x][y]==0){
        e.RemoveRobot(*this);
        this->setX(x);
        this->setY(y);
        e.AddRobot(*this);
    }
}
