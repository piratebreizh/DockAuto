#include "viewmenulistedestaches.h"
#include <gestiondb.h>
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


    confirmationEnregistrement = new QLabel();
    confirmationEnregistrement->hide();

    model->setHorizontalHeaderLabels(list);

    tableListeTache->setModel(model);

    listeTache = new Listetache();

    pushAjouterTache = new QPushButton("Nouvelle tâche");
    pushSauvegarder = new QPushButton("Sauvegarder");
    pushAnnuler = new QPushButton("Retour");
}


void ViewMenuListeDesTaches::definitonLayout(){
    layout1->addWidget(confirmationEnregistrement,0,0,1,2);
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

}



void ViewMenuListeDesTaches::CliqueSauvegarder(){

    if(!champNomTacheListe->text().isEmpty() && (listeTache->getListDesTaches()->size() >0)){
        enregistrementDansLaTableListetache();
        enregistrementDansLaTableTache();
        this->viewMenuSimulation->setConfirmationTache(true);
        this->viewMenuSimulation->verificationlabelConfirmation();
        confirmationEnregistrement->setText("La liste de tâche à été enregistrée");
        confirmationEnregistrement->setStyleSheet("QLabel { color : green; }");
        confirmationEnregistrement->show();
    }else{
        confirmationEnregistrement->setText("Tous les champs doivent être remplis");
        confirmationEnregistrement->setStyleSheet("QLabel { color : red; }");
        confirmationEnregistrement->show();
    }
}

void ViewMenuListeDesTaches::enregistrementDansLaTableListetache(){

   QString insertListeTable = "INSERT INTO liste_taches (Nom_Liste_Taches) VALUES ('";
    insertListeTable.append(this->champNomTacheListe->text());
    insertListeTable.append("');");

    qDebug()<<insertListeTable;
    GestionDB * db = GestionDB::getInstance();
    db->Requete(insertListeTable);

    initialisationIDListeTache();


}

void ViewMenuListeDesTaches::initialisationIDListeTache(){
    GestionDB * db = GestionDB::getInstance();
    db->selectMutliLigne("SELECT MAX(ID_Liste_Taches) FROM liste_taches ;");
    this->listeTache->IDListeTache  = db->resultatSelectMultiLignes.at(0).at(0).toInt();
}


void ViewMenuListeDesTaches::enregistrementDansLaTableTache(){

    QString insertDansTache ("INSERT INTO tache (Poids_Tache,Depart_X,Depart_Y,Arrive_X, Arrive_Y, ID_Liste_Taches, ID_Robot) VALUES (");

    bool firstVirgule = true;

    qDebug()<<listeTache->getListDesTaches()->size();
    if(this->listeTache->getListDesTaches()->size()>0){
        for(int i = 0;i<listeTache->getListDesTaches()->size();i++){
            if(!firstVirgule){
                insertDansTache.append(" ),( ");
            }
            Tache tacheTemp = listeTache->getListDesTaches()->at(i);
            insertDansTache.append("'");
            insertDansTache.append(QString::number(tacheTemp.getPoids()));
            insertDansTache.append("',");
            insertDansTache.append(QString::number(tacheTemp.depart->getX()));
            insertDansTache.append( ",");
            insertDansTache.append(QString::number(tacheTemp.depart->getY()));
            insertDansTache .append(",");
            insertDansTache.append(QString::number(tacheTemp.arrive->getX()));
            insertDansTache .append( ",");
            insertDansTache.append(QString::number(tacheTemp.arrive->getY()));
            insertDansTache .append(",");
            insertDansTache.append(QString::number(this->listeTache->IDListeTache));
            insertDansTache .append(",");
            insertDansTache.append(QString::number(this->nouveauRobotTemp->getId()));
            firstVirgule = false;
        }
        insertDansTache.append("); ");
        qDebug()<<insertDansTache;
        GestionDB * db = GestionDB::getInstance();
        db->Requete(insertDansTache);
    }

}


















