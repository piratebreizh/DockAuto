#ifndef VIEWDEFINIRTACHE_H
#define VIEWDEFINIRTACHE_H

#include <viewmenulistedestaches.h>
#include <QtWidgets>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <tache.h>
#include <listetache.h>
#include <QComboBox>
#include <robot.h>
#include <mapscene.h>

class MapScene;
class ViewMenuListeDesTaches;
class ViewMenuSimulation;

class ViewDefinirTache : public QDialog
{
    Q_OBJECT

public:

    ViewDefinirTache(ViewMenuListeDesTaches * _menuListeDesTaches);
    ViewMenuListeDesTaches * menuListeDesTaches;

    QLabel * labelDepart;
    QLabel * champDepart;
    QPushButton * pushDefinirDepart;
    double valeurDepart;
    bool estDefinitDepart;

    QLabel * labelArrive;
    QLabel * champArrive;
    QPushButton * pushDefinirArrive;
    double valeurArrive;
    bool estDefiniArrive;

    QPushButton * sauvegarder;
    QPushButton * annuler;


    int departX;
    int departY;
    int arriveX;
    int arriveY;

    QLabel * messageConfirmationAjout;

public slots :

    void cliqueAjouterDepart();
    void cliqueAjouterArrive();
    void ajouterNouvelleTacheALaListeDeTache();
    void switchBoutonLabelDefinir();

private :

    QGridLayout * mainLayout;
    QGridLayout * layoutMenuDroiteSelection;

    QLabel * labelRobot;
    QComboBox * listeDeroulanteRobot;


    QLabel * labelPoids;
    QLineEdit * champPoids;

    QList<Robot> * listeRobot;

    QGridLayout * map;
    QGraphicsScene * scene;
    MapScene * lamap;
    QGraphicsView * vue;

    void initialisationComposant();
    void definitonLayout();
    void chargerListeDeroulanteDesRobots();
    void chargerListeRobotEnBase(int ID_Equipe);
    void viderTousLesChamps();
    void positionneFenetre();

};

#endif // VIEWDEFINIRTACHE_H

















