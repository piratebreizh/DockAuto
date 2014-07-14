#include "Robot.h"
#include <string>
#include "Entrepot.h"
#include "MapScene.h"
#include "recherchecheminastar.h"

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

int Robot::moveToObjectif(Entrepot *e, Tile objectif)
{

    int moveToX = this->getX();
    int moveToY = this->getY();

    int dx = objectif.getX() - this->getX();
    int dy = objectif.getY() - this->getY();

    RechercheCheminAStar recherche = RechercheCheminAStar(e);

    QString route = recherche.calculChemin(this->getX(), this->getY(), objectif.getX(), objectif.getY());
    qDebug() << "route trouvé pour robot " << this->getId() << " : " << route;
    if(route.length()>0)
    {
        int j;
        QChar c;
        c =route.at(0);
        j=c.digitValue();
        cout << recherche.dx[j] << " " << recherche.dy[j] << endl;

        moveToX += recherche.dx[j];
        moveToY += recherche.dy[j];
    }

/*
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
    */
    this->move(*e, moveToX, moveToY);

    if((abs(dx) == 0 && abs(dy) ==1) || (abs(dx) == 1 && abs(dy) ==0)){
        if(e->tab[objectif.getX()][objectif.getY()] == MapScene::ARMOIREPLEINE)
        {
            e->tab[objectif.getX()][objectif.getY()] = MapScene::ARMOIREVIDE;
            return MapScene::ARMOIREVIDE;
        }
        else if(e->tab[objectif.getX()][objectif.getY()] == MapScene::ARMOIREVIDE)
        {
            e->tab[objectif.getX()][objectif.getY()] = MapScene::ARMOIREPLEINE;
            return MapScene::ARMOIREPLEINE;
        }
    }
    return MapScene::VIDE;
}
