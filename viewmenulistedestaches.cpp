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

    listeTache = new Listetache();

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
    QWidget::connect(pushSauvegarder, SIGNAL(clicked()), this, SLOT(CliqueSauvegarder()));
    QWidget::connect(pushAnnuler, SIGNAL(clicked()), this, SLOT(close()));

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

   // qDebug()<<this->nouvelleTacheTemp->getPoids();


    QList <QStandardItem*> listItem;

    listItem.append(new QStandardItem (QString::fromUtf8(this->nouveauRobotTemp->nomRobot.c_str())));
    listItem.append(new QStandardItem (QString::number(this->nouvelleTacheTemp->getPoids())));
    QString champDepart(QString::number(this->nouvelleTacheTemp->depart->getX()));
    champDepart.append(" : ");
    champDepart.append(QString::number(this->nouvelleTacheTemp->depart->getY()));

    QString champArrive(QString::number(this->nouvelleTacheTemp->arrive->getX()));
    champArrive.append(" : ");
    champArrive.append(QString::number(this->nouvelleTacheTemp->arrive->getY()));

    listItem.append(new QStandardItem(champDepart));
    listItem.append(new QStandardItem(champArrive));

    model->appendRow(listItem);


    this->listeTache->ajoutNouvelleTacheDansListe(*this->nouvelleTacheTemp);

}



void ViewMenuListeDesTaches::CliqueSauvegarder(){

    enregistrementDansLaTableListetache();
    enregistrementDansLaTableTache();

}

void ViewMenuListeDesTaches::enregistrementDansLaTableListetache(){
   initialisationIDListeTache();

   QString insertListeTable = "INSERT INTO liste_taches (ID_Liste_Taches,ID_Simulation,NomListeTache) VALUES ( ";
    insertListeTable.append(QString::number(this->listeTache->IDListeTache));
    insertListeTable.append(" , ");
    insertListeTable.append(QString::number(this->viewMenuSimulation->simulation->IdSimulation));
    insertListeTable.append(" , ");
    insertListeTable.append(this->champNomTacheListe->text());
    insertListeTable.append(" ); ");

    qDebug()<<insertListeTable;
}

void ViewMenuListeDesTaches::initialisationIDListeTache(){
    QString selectMax = "SELECT MAX(ID_Liste_Taches) FROM liste_taches ;";
    this->listeTache->IDListeTache = 1;
}


void ViewMenuListeDesTaches::enregistrementDansLaTableTache(){

    QString insertDansTache ("INSERT INTO tache (poids_Tache,depart_X,arrive_X,depart_Y, arrive_Y, ID_Liste_Taches) VALUES  ");
    bool firstPlacement = true;

    if(this->listeTache->getListDesTaches.size()>0){
        for(int i = 0;i<listeTache->getListDesTaches.size();i++){
            Tache tacheTemp = listeTache->getListDesTaches.at(i);
            if(firstPlacement){
                insertDansTache.append(" , ");
            }
            insertDansTache.append(" ( ");
            insertDansTache.append(QString::number(tacheTemp.getPoids()));
            insertDansTache.append(" , ");
            insertDansTache.append(QString::number(tacheTemp.depart->getX()));
            insertDansTache.append(" , ");
            insertDansTache.append(QString::number(tacheTemp.depart->getY()));
            insertDansTache.append(" , ");
            insertDansTache.append(QString::number(tacheTemp.arrive->getX()));
            insertDansTache.append(" , ");
            insertDansTache.append(QString::number(tacheTemp.arrive->getY()));
            insertDansTache.append(" , ");
            insertDansTache.append(QString::number(this->listeTache->IDListeTache));
            insertDansTache.append(" ) ");
            firstPlacement = true;
        }
            insertDansTache.append(" ; ");
    }
    qDebug()<<insertDansTache;

}


















