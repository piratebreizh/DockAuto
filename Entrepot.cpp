#include "Entrepot.h"

Entrepot::Entrepot(){

}

Entrepot::~Entrepot(){

}

void Entrepot::AddArmoire(Armoire &arm){

    tab[arm.getX()][arm.getY()]=1;
}

void Entrepot::AddRobot(Robot &rob){

    tab[rob.getX()][rob.getY()]=rob.getId();
}

void Entrepot::RemoveArmoire(Armoire &arm){

    tab[arm.getX()][arm.getY()]=0;
}

void Entrepot::RemoveRobot(Robot &rob){

    tab[rob.getX()][rob.getY()]=0;
}
