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

class ViewMenuListeDesTaches;
class ViewMenuSimulation;

class ViewDefinirTache : public QDialog
{
    Q_OBJECT
public:
    ViewDefinirTache(ViewMenuListeDesTaches * _menuListeDesTaches);

private :
    ViewMenuListeDesTaches * menuListeDesTaches;

    QGridLayout * mainLayout;
    QGridLayout * layoutMenuDroiteSelection;

    QLabel * labelRobot;
    QComboBox * listeDeroulanteRobot;

    QLabel * labelPoids;
    QLineEdit * champPoids;
    QLabel * labelDepart;
    QLabel * champDepart;
    QLabel * labelArrive;
    QLabel * champArrive;

    QPushButton * sauvegarder;
    QPushButton * annuler;

    void initialisationComposant();
    void definitonLayout();

};

#endif // VIEWDEFINIRTACHE_H

















