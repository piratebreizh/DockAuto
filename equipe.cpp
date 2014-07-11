#include "Equipe.h"
#include <iostream>

using namespace std;

Equipe::Equipe()
{
    idEquipe=0;
    nomEquipe="";
}

Equipe::Equipe(int _id, string _nom)
{
    idEquipe=_id;
    nomEquipe=QString::fromStdString(_nom);
}


Equipe::Equipe(int _id, QString _nom)
{
    idEquipe=_id;
    nomEquipe=_nom;
}

void Equipe::AddRobot(Robot &r){
    listeRobotEquipe.insert(std::pair<int,Robot>(r.getId(),r));
}

void Equipe::RemoveEquipe(Robot &r){
    listeRobotEquipe.erase(r.getId());
}

