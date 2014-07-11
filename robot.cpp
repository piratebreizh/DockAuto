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

Robot::Robot(int _id, QString _nom){
    idRobot=_id;
    nomRobot = _nom;
}

QString Robot::getNom(){
    return nomRobot;
}

void Robot::setNom(string nom){
    nomRobot=QString::fromStdString(nom);
}

int Robot::getId(){
    return idRobot;
}

void Robot::setId(int id){
    idRobot=id;
}

/**
 * @brief Deplacement du robot si l'emplacement est libre
 * @param e
 * @param x
 * @param y
 */
void Robot::move(Entrepot &e, int x, int y)
{
    if(e.isTileDisponible(x,y)){
        e.RemoveRobot(*this);
        this->setX(x);
        this->setY(y);
        e.AddRobot(*this);
    }
}

void Robot::moveToObjectif(Entrepot &e, Tile objectif)
{
    int moveToX = this->getX();
    int moveToY = this->getY();
    int dx = objectif.getX() - this->getX();
    int dy = objectif.getY() - this->getY();

    if(dx>0){
        moveToX++;
    }else if(dx<0){
        moveToX--;
    }else{
        if(dy>0){
            moveToY++;
        }else if(dy<0){
            moveToY--;
        }
    }
    this->move(e, moveToX, moveToY);
}
