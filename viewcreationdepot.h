#ifndef VIEWCREATIONDEPOT_H
#define VIEWCREATIONDEPOT_H

#include <qlineedit.h>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <QLabel>
#include <qdialog.h>
#include <QIntValidator>
#include <QtWidgets>
#include "Map.h"
#include "Entrepot.h"
#include "mapscene.h"



class ViewCreationDepot : public QDialog
{
    Q_OBJECT
public:
    ViewCreationDepot();
    void initialisationConposantFenetreIdentificationDepot();
    void definitionMainLayout();
    void masquerLayout2();
    bool initialisationDeLaMap();
    bool controleTousChampsRempli();
    void mousePressEvent();
    void AfficherMap(int lon, int larg);
    //GESTION DU DRAG AND DROP
    /*void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);*/


public slots:
    void lancementFenetreCreationMap();

private :
    //MapScene *lamap;
    QGraphicsView *vue;

    QVBoxLayout *mainLayout;

    // IDENTIFICATION DEPOT
    QGridLayout *layout2pourFenetreIdentification;
    QGridLayout *layout3PourBoutonSauvegarderAnnuler;

    QLabel * labelNomDepot;
    QLabel * labelLargeurDepot;
    QLabel * labelLongueurDepot;
    QLabel * labelMessageErreur;

    QLineEdit * champNomDepot;
    QLineEdit * champLargeurDepot;
    QLineEdit * champLongueurDepot;

    QPushButton *sauvegardeEtEditerMap;
    QPushButton *annuler;


    // CREATION MAP POUR DEPOT
    QGraphicsScene *scene ;

    QGridLayout *layoutpourLesImages;
    QGridLayout *layoutpourLaVisualisationMap;

    QLabel *labelImageArmoire;
    QLabel *labelImageZoneDep;

    QGraphicsScene *sceneArmoire ;
    QGraphicsScene *sceneDep ;

    QGraphicsView *vueArmoire;
    QGraphicsView *vueDep;

    QPixmap *imageArmoire;
    QPixmap *imageZoneDep;


};

#endif // VIEWCREATIONDEPOT_H



