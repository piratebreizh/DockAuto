#ifndef VIEWMENUSIMULATION_H
#define VIEWMENUSIMULATION_H
#include <QtWidgets>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include<viewmenulistedestaches.h>
#include <equipe.h>
#include <Entrepot.h>
#include <simulation.h>
#include <FenetrePrincipale.h>


class ViewMenuListeDesTaches;
class Equipe;
class Entrepot;
class FenetrePrincipale;

class ViewMenuSimulation : public QDialog
{
    Q_OBJECT

public:
    ViewMenuSimulation(FenetrePrincipale * _fenetrePrincipal);
    void initialisationComposantFenetreMenuSimulation();
    FenetrePrincipale * fenetrePrincipale;
    Equipe * equipeSelectionne;
    Entrepot * depotSelectionne;
    ViewMenuListeDesTaches * viewMenuListeDesTaches;
    Simulation * simulation;
    void setConfirmationTache(bool _tache);
    void verificationlabelConfirmation();
    void initialisationDelaSimulation();



public slots:
    void layoutNouvelleSimulation();
    void executionViewMenuListeDesTaches();
    void bloquerSelectionEquipe();
    void bloquerSelectionDepot();
    void cliqueSauvegarderSimulation();
    void cliqueDefinirSimulation();
    void layoutChargerSimulation();
    void pushBoutonDefinirSimulationCharger();


private:

    QVBoxLayout *mainLayout;

    QGridLayout *layoutMenuChoixSauvegardCharger;


    QPushButton * nouvelleSimulation;
    QPushButton * chargerSimulation;


    QGridLayout *layoutNomSimulation;
    QLabel * labelNomSimulation;
    QLineEdit * champNomSimulation;

    QGridLayout * layoutDepot;
    QLabel * labelDepot;
    bool confirmationDepot;
    QLabel * labelConfirmationDepot;
    QPushButton * boutonDefinirDepot;
    QComboBox * listeDeroulanteChoixDepot;

    QGridLayout * LayoutEquipe;
    QLabel * labelChoixEquipe;
    bool confirmationEquipe;
    QPushButton * pushBloquerChoixEquipe;
    QLabel * labelConfirmationEquipe;
    QComboBox * listeDeroulanteChoixEquipe;



    QGridLayout * LayoutTache;
    QLabel * labelTache;
    bool confirmationTache;
    QLabel * labelConfirmationTache;
    QPushButton * boutonDefinirTache;


    QLabel * labelConfirmationEnregistremetnSimulation;
    QGridLayout * LayoutSauvegarderAnnuler;
    QPushButton * sauvegarderSimulation;
    QPushButton * definirCommeSimulation;
    QPushButton * pushRetour;

    QString * messageControleDesDonneesExistante;


    QGridLayout * LayoutSimulation;
    QComboBox * listeDeroulanteChoixSimulationCharger;
    QPushButton * definirSimulation;
    QLabel * labelSimulationChargerDefinit;
    QPushButton * definirCommeSimualtionCharger;



    void definitionMainLayout();
    void definitionLayoutMenuChoixSauvegardeCharger();
    void initialisationDeLaListeDeroulanteEquipe();
    void chargeToutesLesEquipesDeLaBase();

    void initialisationDeLaListeDeroulanteDepot();
    void chargeToutesLesDepotsDeLaBase();

    void sauvegardeEnBaseDeLaSimulation();
    int derniereIDSimulation();

    void controleEquipeExist();
    void controleDepotExist();
    void controleSimulationExist();
    void chargerListeSimulationDepuisLaBase();

    QList <Equipe> * listeEquipe;
    QList <Entrepot> * listeDepot;
};

#endif // VIEWMENUSIMULATION_H
