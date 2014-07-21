#ifndef TETRIXWINDOW_H
#define TETRIXWINDOW_H

#include <QFrame>
#include <QMainWindow>
#include <viewgestionequipe.h>
#include <viewcreationdepot.h>
#include <viewmenusimulation.h>
#include "mapscene.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "simulation.h"

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
class QPushButton;
class ViewMenuSimulation;
class MapScene;
class ViewCreationDepot;

QT_END_NAMESPACE

//! [0]
class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:

    FenetrePrincipale(QWidget *parent = 0);
    void definirSimulation(Simulation * _simulation);
    void createMap();
    void verificationConnexionBaseDeDonnees();

public slots:

    void lancementViewCreationDepot();
    void lancementViewCreationEquipe();
    void lancementViewMenuSimulation();

    void lancerSimulation();
    void arretSimulation();

private:

    void positionne();
    void createBarreDeLancement();
    void resetSimulation();

    enum { NumGridRows = 3, NumButtons = 5 };

    QHBoxLayout *mainLayout;

    QGridLayout *map;
    QGridLayout *barreLancement;

    MapScene *lamap;
    QGraphicsView *vue;
    QGraphicsScene *scene ;

    Simulation * simulation;

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];

    QMenu *fileMenu;
    QAction *exitAction;

    QPushButton *nouvelleSimulation;
    QPushButton *gestionDesEquipe;
    QPushButton *gestionDesDepots;
    QPushButton *demarrerSimulation;
    QPushButton *pauseSimulation;

    ViewGestionEquipe * viewGestionEquipe;
    ViewCreationDepot * viewCreationDepot;
    ViewMenuSimulation * viewMenuSimulation;

    QLabel * messageControl;
};


#endif // DIALOG_H
