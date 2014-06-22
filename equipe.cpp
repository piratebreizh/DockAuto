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
    nomEquipe=_nom;
}

void Equipe::AddEquipe(Robot &r){
    listeRobotEquipe.insert(std::pair<int,Robot>(r.getId(),r));
}

void Equipe::RemoveEquipe(Robot &r){
    listeRobotEquipe.erase(r.getId());
}

void Equipe::AfficheEquipe(){
    std::map<int,Robot>::iterator it = listeRobotEquipe.begin();
    for (it=listeRobotEquipe.begin(); it!=listeRobotEquipe.end(); ++it)
       cout << it->second.getNom()<<"\n";
}

