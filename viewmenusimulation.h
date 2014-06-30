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

public slots:
    void layoutNouvelleSimulation();
    void executionViewMenuListeDesTaches();

private:

    QVBoxLayout *mainLayout;

    QGridLayout *layoutMenuChoixSauvegardCharger;


    QPushButton * nouvelleSimulation;
    QPushButton * chargerSimulation;

    QLabel * labelNomSimulation;
    QLineEdit * champNomSimulation;

    QLabel * labelChoixEquipe;
    bool confirmationEquipe;
    QLabel * labelConfirmationEquipe;
    QComboBox * listeDeroulanteChoixEquipe;

    QLabel * labelTache;
    bool confirmationTache;
    QLabel * labelConfirmationTache;
    QPushButton * boutonDefinirTache;

    QPushButton * sauvegarderSimulation;
    QPushButton * definirCommeSimulation;

    ViewMenuListeDesTaches * viewMenuListeDesTaches;

    void definitionMainLayout();
    void definitionLayoutMenuChoixSauvegardeCharger();
    void verificationlabelConfirmation();
    void initialisationDeLaListeDeroulanteEquipe();

    QList <Equipe> * listeEquipe;
};

#endif // VIEWMENUSIMULATION_H
