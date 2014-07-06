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



class ViewMenuListeDesTaches;
class Equipe;
class Entrepot;

class ViewMenuSimulation : public QDialog
{
    Q_OBJECT

public:
    ViewMenuSimulation();
    void initialisationComposantFenetreMenuSimulation();
    Equipe * equipeSelectionne;
    Entrepot * depotSelectionne;
    ViewMenuListeDesTaches * viewMenuListeDesTaches;
    Simulation * simulation;

public slots:
    void layoutNouvelleSimulation();
    void executionViewMenuListeDesTaches();
    void bloquerSelectionEquipe();
    void bloquerSelectionDepot();

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


    QGridLayout * LayoutSauvegarderAnnuler;
    QPushButton * sauvegarderSimulation;
    QPushButton * definirCommeSimulation;


    void definitionMainLayout();
    void definitionLayoutMenuChoixSauvegardeCharger();
    void verificationlabelConfirmation();
    void initialisationDeLaListeDeroulanteEquipe();
    void chargeToutesLesEquipesDeLaBase();

    void initialisationDeLaListeDeroulanteDepot();
    void chargeToutesLesDepotsDeLaBase();


    QList <Equipe> * listeEquipe;
    QList <Entrepot> * listeDepot;
};

#endif // VIEWMENUSIMULATION_H
