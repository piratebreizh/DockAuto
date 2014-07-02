#include "viewmenulistedestaches.h"

ViewMenuListeDesTaches::ViewMenuListeDesTaches(ViewMenuSimulation * _viewMenuSimulation)
{
    viewMenuSimulation = &* _viewMenuSimulation;
    initialisationComposant();
    definitonLayout();
}


void ViewMenuListeDesTaches::initialisationComposant(){
    mainLayout = new QVBoxLayout(this);
    layout1 = new QGridLayout();

    labelNomTacheListe = new QLabel("Nom liste");
    champNomTacheListe = new QLineEdit();

    labelNomTacheListe = new QLabel("Tableau liste tâches");

    model= new QStandardItemModel();
    tableListeTache = new QTableView();
    tableListeTache->setFixedWidth(400);
    QStringList list;
    list.append("Nom robot");
    list.append("Poids");
    list.append("Départ");
    list.append("Arrivé");

    model->setHorizontalHeaderLabels(list);

    tableListeTache->setModel(model);

    pushAjouterTache = new QPushButton("Nouvelle tâche");
    pushSauvegarder = new QPushButton("Sauvegarder");
    pushAnnuler = new QPushButton("Annuler");
}


void ViewMenuListeDesTaches::definitonLayout(){
    layout1->addWidget(labelNomTacheListe,1,0);
    layout1->addWidget(champNomTacheListe,2,0);
    layout1->addWidget(labelNomTacheListe,3,0);
    layout1->addWidget(tableListeTache,4,0);
    layout1->addWidget(pushAjouterTache,5,0);
    layout1->addWidget(pushSauvegarder,6,0);
    layout1->addWidget(pushAnnuler,7,0);

    QWidget::connect(pushAjouterTache, SIGNAL(clicked()), this, SLOT(executerViewDefinirTache()));

    mainLayout->addLayout(layout1);
    this->setLayout(mainLayout);
}


void ViewMenuListeDesTaches::executerViewDefinirTache(){
    nouvelleTacheTemp = new Tache();
    nouveauRobotTemp = new Robot();
    viewDefinirTache = new ViewDefinirTache(this);
    viewDefinirTache->exec();
}



void ViewMenuListeDesTaches::ajouterTacheDansListe(){

    qDebug()<<this->nouvelleTacheTemp->getPoids();


    QList <QStandardItem*> listItem;

    listItem.append(new QStandardItem (QString::fromUtf8(this->nouveauRobotTemp->nomRobot.c_str())));
    listItem.append(new QStandardItem (QString::number(this->nouvelleTacheTemp->getPoids())));
    //listItem.append(new QStandardItem (QString::number(this->nouvelleTacheTemp->getDepart().getX())));
    //listItem.append(new QStandardItem (QString::number(this->nouvelleTacheTemp->getArrive().getY())));


    model->appendRow(listItem);

}























