#include <QApplication>
#include <FenetrePrincipale.h>


// A nettoyer lors du rendu
//*************************
#include "Map.h"
#include "Armoire.h"
#include "Entrepot.h"
#include "Robot.h"
#include <iostream>
#include <QSqlDatabase>
#include "gestiondb.h"
#include <QString>
#include "simulation.h"
//*************************

using namespace std;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FenetrePrincipale premierVue;

    premierVue.show();

    return app.exec();

    //TEST SIMULATION
    //Simulation *s;
    //s->IdSimulation=1;
    //s.ChargerDepot(2);

/*
    //TEST BDD
     db = GestionDB::getInstance();
    QString qs;
    //db.Requete("INSERT INTO Robot (Longueur, Largeur, Capacite, Vitesse, ID_Equipe) VALUES (3,3,3,3,3)");
    db->Select("SELECT ID_Entrepot FROM entrepot ORDER BY ID_Entrepot DESC");
    db->AfficheResultatsSelect();

    cout<<"debut"<<endl;
    qs = db->getResultat(0);
    cout<<"result : "<<qs.toStdString()<<endl;
    cout<<"fin"<<endl;
    */
    /*GestionDB db("localhost","root","","dockautodb");
    //db.Requete("INSERT INTO Robot (Longueur, Largeur, Capacite, Vitesse, ID_Equipe) VALUES (1,1,1,1,1)");
    db.selectMutliLigne("SELECT * FROM tile;");
    db.afficherResultatSelectMultiple();*/



    /*
    //TEST MAP
    Entrepot e;
    Armoire a;
    Robot r;
    e.AfficheMap();
    cout<<"MAP 1"<<endl<<endl;
    a.setX(1);
    a.setY(1);
    r.setX(3);
    r.setY(3);
    e.AddArmoire(a);
    e.AddRobot(r);
    e.AfficheMap();
    cout<<"MAP 2"<<endl<<endl;
    r.move(e,2,2);
    e.AfficheMap();
    cout<<"MAP 3"<<endl<<endl;
    r.move(e,1,1);
    e.AfficheMap();
    cout<<"MAP 4"<<endl<<endl;
    */


    /*TEST EQUIPE*/
    /*Robot r1(1,"bob");
    Robot r2(2,"bob2");
    Robot r3(3,"bob3");
    Equipe e(1,"Equipe1");
    e.AddEquipe(r1);
    e.AddEquipe(r2);
    e.AddEquipe(r3);
    e.AfficheEquipe();
    e.RemoveEquipe(r2);
    e.AfficheEquipe();*/

    //return 0;
}
