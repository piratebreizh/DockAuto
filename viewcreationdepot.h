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

class MapScene;


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

public slots:
    void lancementFenetreCreationMap();
    void SauvegardeMapDb();

private :
    MapScene *lamap;
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
    QGridLayout *layoutpourLaSauvegardeMap;

    QLabel *labelArmoire;
    QLabel *labelZoneDep;
    QLabel *labelMur;
    QLabel *labelRobot;

    QLabel *labelImageArmoire;
    QLabel *labelImageZoneDep;
    QLabel *labelImageMur;
    QLabel *labelImageRobot;

    QPushButton *sauvegardeModifMap;

};

#endif // VIEWCREATIONDEPOT_H



