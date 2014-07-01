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

class ViewMenuListeDesTaches;
class Equipe;

class ViewMenuSimulation : public QDialog
{
    Q_OBJECT

public:
    ViewMenuSimulation();
    void initialisationComposantFenetreMenuSimulation();
    Equipe * equipeSelectionne;
    ViewMenuListeDesTaches * viewMenuListeDesTaches;


public slots:
    void layoutNouvelleSimulation();
    void executionViewMenuListeDesTaches();
    void bloquerSelectionEquipe();


private:

    QVBoxLayout *mainLayout;

    QGridLayout *layoutMenuChoixSauvegardCharger;


    QPushButton * nouvelleSimulation;
    QPushButton * chargerSimulation;


    QGridLayout *layoutNomSimulation;
    QLabel * labelNomSimulation;
    QLineEdit * champNomSimulation;


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

    QList <Equipe> * listeEquipe;
};

#endif // VIEWMENUSIMULATION_H
