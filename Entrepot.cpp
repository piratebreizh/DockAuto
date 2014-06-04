#include "Entrepot.h"

using namespace std;

Entrepot::Entrepot(){

}

Entrepot::~Entrepot(){

}

void Entrepot::AddArmoire(Armoire &arm){
    if(arm!=null && tab[arm.getX()][arm.getY()]==0)
    tab[arm.getX()][arm.getY()]=1;
}

void Entrepot::AddRobot(Robot &rob){
    if(rob!=null && tab[rob.getX()][rob.getY()]==0)
    tab[rob.getX()][rob.getY()]=rob.getId();
}

void Entrepot::RemoveArmoire(Armoire &arm){
    if(arm!=null && tab[arm.getX()][arm.getY()]==1)
    tab[arm.getX()][arm.getY()]=0;
}

void Entrepot::RemoveRobot(Robot &rob){
    if(rob!=null && tab[rob.getX()][rob.getY()]>0)
    tab[rob.getX()][rob.getY()]=0;
}
