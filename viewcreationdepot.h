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



class ViewCreationDepot : public QDialog
{
    Q_OBJECT
public:
    ViewCreationDepot();
    void initialisationCoposantFenetreIdentificationDepot();
    void definitionMainLayout();
    void masquerLayout2();
    bool initialisationDeLaMap();
    bool controleTousChampsRempli();
    void AfficherMap(int **tab, int size, QGraphicsScene *scene);


public slots:
    void lancementFenetreCreationMap();

private :

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
};

#endif // VIEWCREATIONDEPOT_H



