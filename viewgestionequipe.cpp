<<<<<<< HEAD
#include "viewgestionequipe.h"

#include <QtWidgets>


ViewGestionEquipe::ViewGestionEquipe(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(parent);

    QGroupBox *groupeBox = new QGroupBox;

    //resetTousLesChamps();
    layoutSencondaire = new QFormLayout;

    layoutSencondaire->addRow(new QLabel(tr("Nom de l'equipe")));
    champNomEquipe = new QLineEdit();
    layoutSencondaire->addRow(champNomEquipe);

    creationTableauRobot();
    enregistrerEquipe();

    groupeBox->setLayout(layoutSencondaire);

    mainLayout->addWidget(groupeBox);


// VOIR PROJET TABLEMODEL AFIN DE RAJOUTER DES DONNEES DYNAMIQUE D'UNE BASE

    this->setLayout(mainLayout);
}

void ViewGestionEquipe::creationTableauRobot(){


    model= new QStandardItemModel();

    QStringList list;
    list.append("Nom");
    list.append("Largeur");
    list.append("Longueur");
    list.append("Vitesse");
    list.append("Largeur Cargaison");
    list.append("Longueur Cargaison");
    list.append("Poids Cargaison");

    model->setHorizontalHeaderLabels(list);

/*    QStandardItem * newItem = new QStandardItem("dede");
    model->setItem(1, 1, newItem);
    QStandardItem * newItem2 = new QStandardItem("aaaa");

    model->appendRow(newItem2);*/


    resultView = new QTableView();
    resultView->setModel(model);


    resultView->verticalHeader()->hide();
    resultView->horizontalHeader()->setStretchLastSection(true);
    resultView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    resultView->show();
    ajouterRobot = new QPushButton(tr("Ajouter un robot"));
    //robotTemp = new Robot;
    QWidget::connect(ajouterRobot, SIGNAL(clicked()), this, SLOT(appelAjoutRobot()));

    layoutSencondaire->addRow(new QLabel(tr("Liste des robots")));
    layoutSencondaire->addRow(resultView);
    layoutSencondaire->addRow(ajouterRobot);
}


void ViewGestionEquipe::enregistrerEquipe(){
    sauvegarde = new QPushButton(tr("Sauvegarder"));
    annuler = new QPushButton(tr("Annuler"));
    connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    layoutSencondaire->addRow(sauvegarde,annuler);
}


void ViewGestionEquipe::appelAjoutRobot(){
    robotTemp = Robot();
    creationRobot = new ViewCreationRobot(this);
    creationRobot->exec();
}


void ViewGestionEquipe::ajouterRobotDansList(){
    //qDebug() << this->robotTemp.nomRobot ;
    tableRobot.append(this->robotTemp);
    QList <QStandardItem*> listItem;


    if(this->robotTemp.nomRobot != NULL &&
            this->robotTemp.largeurRobot != 0 &&
            this->robotTemp.longueurRobot != 0 &&
            this->robotTemp.vitesseRobot != 0 &&
            this->robotTemp.largeurCapactiteDeCharge != 0 &&
            this->robotTemp.longueurCapaciteDeCharge != 0 &&
            this->robotTemp.poidsCapaciteDeCharge != 0){
        listItem.append(new QStandardItem (this->robotTemp.nomRobot));
        listItem.append(new QStandardItem (QString::number(this->robotTemp.largeurRobot)));
        listItem.append(new QStandardItem (QString::number(this->robotTemp.longueurRobot)));
        listItem.append(new QStandardItem (QString::number(this->robotTemp.vitesseRobot)));
        listItem.append(new QStandardItem (QString::number(this->robotTemp.largeurCapactiteDeCharge)));
        listItem.append(new QStandardItem (QString::number(this->robotTemp.longueurCapaciteDeCharge)));
        listItem.append(new QStandardItem (QString::number(this->robotTemp.poidsCapaciteDeCharge)));

        model->appendRow(listItem);
    }


}



/**
 * Vide tous les champs à l'initialisation de la fenetre création équipe
**/
/*
void ViewGestionEquipe::resetTousLesChamps(){
    this->tableRobot.removeAll();
    delete model;
    this->model = new QStandardItemModel();
}
*/

/*
 *
 * */



/*
 *
 *
 *
 * //setFrameStyle(QFrame::Panel | QFrame::Sunken);
    //setFocusPolicy(Qt::StrongFocus);
    QVBoxLayout *mainLayout = new QVBoxLayout(parent);

    QGroupBox *groupeBox = new QGroupBox;

    QFormLayout *layout = new QFormLayout;

    QLabel *queryLabel = new QLabel(
         QApplication::translate("nestedlayouts", "Nom de l'équipe"));

    QLineEdit *queryEdit = new QLineEdit();

    QTableView *resultView = new QTableView();


    groupeBox->setLayout(layout);
    layout->addWidget(queryLabel);
    layout->addWidget(queryEdit);
    layout->addWidget(resultView);

     mainLayout->addWidget(groupeBox);


 //    resultView = creationTableauRobot(resultView);


     QStandardItemModel model;
     model.setHorizontalHeaderLabels(
         QStringList() << QApplication::translate("nestedlayouts", "Name")
                       << QApplication::translate("nestedlayouts", "Office"));

     QList<QStringList> rows = QList<QStringList>()
         << (QStringList() << "Verne Nilsen" << "123")
         << (QStringList() << "Carlos Tang" << "77")
         << (QStringList() << "Bronwyn Hawcroft" << "119")
         << (QStringList() << "Alessandro Hanssen" << "32")
         << (QStringList() << "Andrew John Bakken" << "54")
         << (QStringList() << "Vanessa Weatherley" << "85")
         << (QStringList() << "Rebecca Dickens" << "17")
         << (QStringList() << "David Bradley" << "42")
         << (QStringList() << "Knut Walters" << "25")
         << (QStringList() << "Andrea Jones" << "34");

     foreach (QStringList row, rows) {
         QList<QStandardItem *> items;
         foreach (QString text, row)
             items.append(new QStandardItem(text));
         model.appendRow(items);
     }

     resultView->setModel(&model);
     resultView->verticalHeader()->hide();
     resultView->horizontalHeader()->setStretchLastSection(true);



    setLayout(mainLayout);*/
=======
#include "viewgestionequipe.h"
#include "Equipe.h"
#include <QtWidgets>


using namespace std;

ViewGestionEquipe::ViewGestionEquipe(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(parent);

    QGroupBox *groupeBox = new QGroupBox;

    layoutSencondaire = new QFormLayout;

    layoutSencondaire->addRow(new QLabel(tr("Nom de l'equipe")));
    champNomEquipe = new QLineEdit();
    layoutSencondaire->addRow(champNomEquipe);

    creationTableauRobot();
    enregistrerEquipe();

    groupeBox->setLayout(layoutSencondaire);

    mainLayout->addWidget(groupeBox);


// VOIR PROJET TABLEMODEL AFIN DE RAJOUTER DES DONNEES DYNAMIQUE D'UNE BASE

    this->setLayout(mainLayout);
}

void ViewGestionEquipe::creationTableauRobot(){
    resultView = new QTableView();
    ajouterRobot = new QPushButton(tr("Ajouter un robot"));
    //robotTemp = new Robot;
    QWidget::connect(ajouterRobot, SIGNAL(clicked()), this, SLOT(appelAjoutRobot()));

    layoutSencondaire->addRow(new QLabel(tr("Liste des robots")));
    layoutSencondaire->addRow(resultView);
    layoutSencondaire->addRow(ajouterRobot);
}


void ViewGestionEquipe::enregistrerEquipe(){
    sauvegarde = new QPushButton(tr("Sauvegarder"));
    annuler = new QPushButton(tr("Annuler"));
    connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    layoutSencondaire->addRow(sauvegarde,annuler);
}

void ViewGestionEquipe::appelAjoutRobot(){

    robotTemp = Robot();
    robotTemp.setNom("NomRobot");
    creationRobot = new ViewCreationRobot(robotTemp);
    creationRobot->exec();
}

/*
 *
 * */



/*
 *
 *
 *
 * //setFrameStyle(QFrame::Panel | QFrame::Sunken);
    //setFocusPolicy(Qt::StrongFocus);
    QVBoxLayout *mainLayout = new QVBoxLayout(parent);

    QGroupBox *groupeBox = new QGroupBox;

    QFormLayout *layout = new QFormLayout;

    QLabel *queryLabel = new QLabel(
         QApplication::translate("nestedlayouts", "Nom de l'équipe"));

    QLineEdit *queryEdit = new QLineEdit();

    QTableView *resultView = new QTableView();


    groupeBox->setLayout(layout);
    layout->addWidget(queryLabel);
    layout->addWidget(queryEdit);
    layout->addWidget(resultView);

     mainLayout->addWidget(groupeBox);


 //    resultView = creationTableauRobot(resultView);


     QStandardItemModel model;
     model.setHorizontalHeaderLabels(
         QStringList() << QApplication::translate("nestedlayouts", "Name")
                       << QApplication::translate("nestedlayouts", "Office"));

     QList<QStringList> rows = QList<QStringList>()
         << (QStringList() << "Verne Nilsen" << "123")
         << (QStringList() << "Carlos Tang" << "77")
         << (QStringList() << "Bronwyn Hawcroft" << "119")
         << (QStringList() << "Alessandro Hanssen" << "32")
         << (QStringList() << "Andrew John Bakken" << "54")
         << (QStringList() << "Vanessa Weatherley" << "85")
         << (QStringList() << "Rebecca Dickens" << "17")
         << (QStringList() << "David Bradley" << "42")
         << (QStringList() << "Knut Walters" << "25")
         << (QStringList() << "Andrea Jones" << "34");

     foreach (QStringList row, rows) {
         QList<QStandardItem *> items;
         foreach (QString text, row)
             items.append(new QStandardItem(text));
         model.appendRow(items);
     }

     resultView->setModel(&model);
     resultView->verticalHeader()->hide();
     resultView->horizontalHeader()->setStretchLastSection(true);



    setLayout(mainLayout);*/
>>>>>>> remotes/origin/antoine
