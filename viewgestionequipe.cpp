#include "viewgestionequipe.h"

#include <QtWidgets>


ViewGestionEquipe::ViewGestionEquipe(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(parent);


    QGroupBox *groupeBox = new QGroupBox;
    tableRobot = new QList <Robot>;
    resultView = new QTableView();
    resultView->setFixedWidth(400);

    resetTousLesChamps();
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


    resultView->setModel(model);


    resultView->verticalHeader()->hide();
    resultView->horizontalHeader()->setStretchLastSection(true);
    resultView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    resultView->show();
    ajouterRobot = new QPushButton(tr("Ajouter un robot"));
    QWidget::connect(ajouterRobot, SIGNAL(clicked()), this, SLOT(appelAjoutRobot()));

    layoutSencondaire->addRow(new QLabel(tr("Liste des robots")));
    layoutSencondaire->addRow(resultView);
    layoutSencondaire->addRow(ajouterRobot);
}


void ViewGestionEquipe::enregistrerEquipe(){
    sauvegarde = new QPushButton(tr("Sauvegarder"));
    annuler = new QPushButton(tr("Annuler"));
    connect(annuler, SIGNAL(clicked()), this, SLOT(deleteViewAjoutRobot()));
    connect(sauvegarde, SIGNAL(clicked()), this, SLOT(sauvegardeEnBaseEquipe()));
    layoutSencondaire->addRow(sauvegarde,annuler);
}


void ViewGestionEquipe::appelAjoutRobot(){
    robotTemp = Robot();
    creationRobot = new ViewCreationRobot(this);
    creationRobot->exec();
}


void ViewGestionEquipe::deleteViewAjoutRobot(){
    delete creationRobot;
    this->close();
}


void ViewGestionEquipe::ajouterRobotDansList(){
    //qDebug() << this->robotTemp.nomRobot ;
    tableRobot->append(this->robotTemp);
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

void ViewGestionEquipe::resetTousLesChamps(){

    this->model = new QStandardItemModel();
    this->resultView->setModel(model);
    this->resultView->show();

}


/**
 * Enregistrement de toutes l'équipe robot y compris dans la base de données
 * */


void ViewGestionEquipe::sauvegardeEnBaseEquipe(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("DockAuto");
    if(db.open())
    {
        qDebug() << "Vous êtes maintenant connecté à " << db.hostName() ;
        db.close();
    }
    else
    {
       qDebug() << "La connexion a échouée, désolé";
    }

}
