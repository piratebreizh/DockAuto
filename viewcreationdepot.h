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
    void AfficherMap(int lon, int larg);
    void SaveDepotDb();


public slots:
    void lancementFenetreCreationMap();

private :

    Entrepot e;

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
    QGraphicsView *vue;

    QGridLayout *layoutpourLesImages;
    QGridLayout *layoutpourLaVisualisationMap;

    QLabel *labelImageArmoire;
    QLabel *labelImageZoneDep;

    QPixmap *imageArmoire;
    QPixmap *imageZoneDep;
};

#endif // VIEWCREATIONDEPOT_H



