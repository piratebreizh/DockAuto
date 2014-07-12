#ifndef VIEWMENULISTEDESTACHES_H
#define VIEWMENULISTEDESTACHES_H
#include <viewmenusimulation.h>
#include <QtWidgets>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <tache.h>
#include <listetache.h>
#include <viewdefinirtache.h>
#include <Robot.h>

class ViewMenuSimulation;
class ViewDefinirTache;
class Robot;
class Listetache;

class ViewMenuListeDesTaches: public QDialog
{
    Q_OBJECT

public:

    ViewMenuListeDesTaches(ViewMenuSimulation * _viewMenuSimulation);
    void initialisationComposant();
    void definitonLayout();
    ViewDefinirTache * viewDefinirTache;
    ViewMenuSimulation * viewMenuSimulation;
    Tache * nouvelleTacheTemp;
    Robot * nouveauRobotTemp;
    Listetache * listeTache;

public slots :

    void executerViewDefinirTache();
    void ajouterTacheDansListe();
    void CliqueSauvegarder();

private :

    QVBoxLayout *mainLayout;
    QGridLayout *layout1;

    QLabel * labelNomTacheListe;
    QLineEdit * champNomTacheListe;

    QLabel * labelListeTache;
    QTableView * tableListeTache;
    QStandardItemModel * model;

    QPushButton * pushAjouterTache;
    QPushButton * pushSauvegarder;
    QPushButton * pushAnnuler;

    QLabel * confirmationEnregistrement;

    void enregistrementDansLaTableListetache();
    void initialisationIDListeTache();
    void enregistrementDansLaTableTache();

};

#endif // VIEWMENULISTEDESTACHES_H
