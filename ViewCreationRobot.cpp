
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
ViewCreationRobot::ViewCreationRobot(QWidget *parent) : QDialog(parent)
{
    //managerRobot = new managerRobot(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(parent);

    layout = new QGridLayout;
    layout2 = new QGridLayout;

    structureRobot = new QGroupBox("Caractéristique du robot");
    cargaisonRobot = new QGroupBox("Valeurs maximales de la cargaison du robot");

    sauvegarde = new QPushButton("Ajouter le robot");
    annuler = new QPushButton("Annuler");
    QWidget::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));

    ViewCreationRobot::connect(sauvegarde, SIGNAL(clicked()), this, SLOT(s_clicked()));
    QWidget::connect(this, SIGNAL(pseudoclick(QString&)), this, SLOT(s_clicked_texte(QString&)));

    champNom = new QLineEdit;
    champLargeur = new QLineEdit;
    champLongueur = new QLineEdit;
    champVitesse = new QLineEdit;

    champCargaisonLargeur = new QLineEdit;
    champCargaisonLongueur = new QLineEdit;
    champCargaisonPoids = new QLineEdit;


    champLargeur->setValidator(new QIntValidator(champLargeur));
    champLongueur->setValidator(new QIntValidator(champLongueur));
    champVitesse->setValidator(new QIntValidator(champVitesse));
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

    mainLayout->addWidget(structureRobot);
    mainLayout->addWidget(cargaisonRobot);

    mainLayout->addWidget(sauvegarde);
    mainLayout->addWidget(annuler);

    this->setLayout(mainLayout);

}



void ViewCreationRobot::s_clicked()
{
  QString texte = champNom->text();
    std::cout << "deded" + texte.toStdString() << std::endl;
     //emit pseudoclick(texte);
}


void ViewCreationRobot::s_clicked_texte(QString& texte)
{
  QMessageBox message(QMessageBox::Information, "Ceci est un test d'information", "Le texte\n" + texte + "\na été entréé");
  message.exec();
}

