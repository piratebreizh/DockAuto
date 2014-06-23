
#include <iostream>
#include "ViewCreationRobot.h"
#include <QtWidgets>

#include <QApplication>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>




/**
 * @brief ViewCreationRobot::ViewCreationRobot
 * Création de la IHM de la création d'un nouveau robot dans une équipe cette IHM est appeler par ViewGestionEquipe
 * @param parent
 * @param a
 */
ViewCreationRobot::ViewCreationRobot(ViewGestionEquipe * _gestionEquipe)
{

    gestionEquipe = &*_gestionEquipe;

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    layout = new QGridLayout;
    layout2 = new QGridLayout;

    confirmationCreationRobot = new QLabel();

    structureRobot = new QGroupBox("Caractéristique du robot");
    cargaisonRobot = new QGroupBox("Valeurs maximales de la cargaison du robot");

    sauvegarde = new QPushButton("Ajouter le robot");
    annuler = new QPushButton("Annuler");
    QWidget::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));

    QWidget::connect(sauvegarde, SIGNAL(clicked()), this, SLOT(s_clicked()));

    QWidget::connect(sauvegarde,SIGNAL(clicked()),gestionEquipe,SLOT(ajouterRobotDansList()));

    champNom = new QLineEdit;
    champLargeur = new QLineEdit;
    champLongueur = new QLineEdit;
    champVitesse = new QLineEdit;

    champCargaisonLargeur = new QLineEdit;
    champCargaisonLongueur = new QLineEdit;
    champCargaisonPoids = new QLineEdit;


    champLargeur->setValidator(new QDoubleValidator(champLargeur));
    champLongueur->setValidator(new QDoubleValidator(champLongueur));
    champVitesse->setValidator(new QDoubleValidator(champVitesse));
    champCargaisonLargeur->setValidator(new QIntValidator(champCargaisonLargeur));
    champCargaisonLongueur->setValidator(new QIntValidator(champCargaisonLongueur));
    champCargaisonPoids->setValidator(new QIntValidator(champCargaisonPoids));

    layout->addWidget(new QLabel("Nom"),1,0);
    layout->addWidget(champNom,1,1);
    layout->addWidget(new QLabel("Largeur"),2,0);
    layout->addWidget(champLargeur,2,1);
    layout->addWidget(new QLabel("Longueur"),3,0);
    layout->addWidget(champLongueur,3,1);
    layout->addWidget(new QLabel("Vitesse"),4,0);
    layout->addWidget(champVitesse,4,1);

    layout2->addWidget(new QLabel("Largeur cargaison"),1,0);
    layout2->addWidget(champCargaisonLargeur,1,1);
    layout2->addWidget(new QLabel("Longueur cargaison"),2,0);
    layout2->addWidget(champCargaisonLongueur,2,1);
    layout2->addWidget(new QLabel("Poids cargaison"),3,0);
    layout2->addWidget(champCargaisonPoids,3,1);

    structureRobot->setLayout(layout);
    cargaisonRobot->setLayout(layout2);


    mainLayout->addWidget(confirmationCreationRobot);
    mainLayout->addWidget(structureRobot);
    mainLayout->addWidget(cargaisonRobot);

    mainLayout->addWidget(sauvegarde);
    mainLayout->addWidget(annuler);

    this->setLayout(mainLayout);
}


void ViewCreationRobot::s_clicked()
{
    gestionEquipe->robotTemp.nomRobot = champNom->text().toStdString();
    gestionEquipe->robotTemp.largeurRobot = champLargeur->text().replace(',','.').toDouble();
    gestionEquipe->robotTemp.longueurRobot = champLongueur->text().replace(',','.').toDouble();
    gestionEquipe->robotTemp.vitesseRobot = champVitesse->text().replace(',','.').toDouble();
    gestionEquipe->robotTemp.largeurCapactiteDeCharge = champCargaisonLargeur->text().replace(',','.').toDouble();
    gestionEquipe->robotTemp.longueurCapaciteDeCharge = champCargaisonLongueur->text().replace(',','.').toDouble();
    gestionEquipe->robotTemp.poidsCapaciteDeCharge = champCargaisonPoids->text().replace(',','.').toDouble();

    if(!gestionEquipe->robotTemp.nomRobot.empty() &&
            gestionEquipe->robotTemp.largeurRobot != 0 &&
            gestionEquipe->robotTemp.longueurRobot != 0 &&
            gestionEquipe->robotTemp.vitesseRobot != 0 &&
            gestionEquipe->robotTemp.largeurCapactiteDeCharge != 0 &&
            gestionEquipe->robotTemp.longueurCapaciteDeCharge != 0 &&
            gestionEquipe->robotTemp.poidsCapaciteDeCharge != 0){
        confirmationCreationRobot->setText("Le nouveau robot est dans l'équipe");
        confirmationCreationRobot->setStyleSheet("QLabel { color : green; }");
        videTousLesChamps();
    }else{
        confirmationCreationRobot->setText("Tous les champs doivent être remplis et différents de 0");
        confirmationCreationRobot->setStyleSheet("QLabel { color : red; }");
    }
    confirmationCreationRobot->setAlignment(Qt::AlignCenter);

}

void  ViewCreationRobot::videTousLesChamps(){
    champNom->setText("");
    champLargeur->setText("");
    champLongueur->setText("");
    champVitesse->setText("");
    champCargaisonLargeur->setText("");
    champCargaisonLongueur->setText("");
    champCargaisonPoids->setText("");
}



