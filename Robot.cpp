#include "Robot.h"
#include <string>

Robot::Robot()
{
}

std::string Robot::getNom(){
    return nomRobot;
}

void Robot::setNom(std::string nom){
    nomRobot=nom;
}

int Robot::getId(){
    return idRobot;
}

void Robot::setId(int id){
    idRobot=id;
}
