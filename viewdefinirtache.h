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

class ViewMenuListeDesTaches;
class ViewMenuSimulation;

class ViewDefinirTache : public QDialog
{
    Q_OBJECT
public:
    ViewDefinirTache(ViewMenuListeDesTaches * _menuListeDesTaches);
    ViewMenuListeDesTaches * menuListeDesTaches;


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


    QLabel * messageConfirmationAjout;

    QLabel * labelPoids;
    QLineEdit * champPoids;

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

    QList<Robot> * listeRobot;

    void initialisationComposant();
    void definitonLayout();
    void chargerListeDeroulanteDesRobot();
    void chargerListeRobotEnBase(int ID_Equipe);
    void  viderTousLesChamps();



};

#endif // VIEWDEFINIRTACHE_H

















