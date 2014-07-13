#include "viewgestionequipe.h"

#include <QtWidgets>
#include <QDebug>


ViewGestionEquipe::ViewGestionEquipe(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(parent);

    QGroupBox *groupeBox = new QGroupBox;
    tableRobot = new QList <Robot>;
    resultView = new QTableView();
    resultView->setFixedWidth(400);

    resetTousLesChamps();
    layoutSencondaire = new QFormLayout;

    labelConfirmation = new QLabel();
    labelConfirmation->hide();

    layoutSencondaire->addRow(labelConfirmation);

    layoutSencondaire->addRow(new QLabel(tr("Nom de l'equipe")));
    champNomEquipe = new QLineEdit();
    layoutSencondaire->addRow(champNomEquipe);

    creationTableauRobot();
    enregistrerEquipe();

    groupeBox->setLayout(layoutSencondaire);

    mainLayout->addWidget(groupeBox);

    this->setLayout(mainLayout);
}

void ViewGestionEquipe::creationTableauRobot()
{
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

void ViewGestionEquipe::enregistrerEquipe()
{
    sauvegarde = new QPushButton(tr("Sauvegarder"));
    annuler = new QPushButton(tr("Retour"));
    connect(annuler, SIGNAL(clicked()), this, SLOT(deleteViewAjoutRobot()));
    connect(sauvegarde, SIGNAL(clicked()), this, SLOT(declanchementSauvegardeCompleteEquipe()));

    QGridLayout *layoutBottom = new QGridLayout();
    layoutBottom->addWidget(sauvegarde,0,0);
    layoutBottom->addWidget(annuler,0,1);
    layoutSencondaire->addRow(layoutBottom);
}


void ViewGestionEquipe::appelAjoutRobot()
{
    robotTemp = Robot();
    creationRobot = new ViewCreationRobot(this);
    creationRobot->exec();
}


void ViewGestionEquipe::deleteViewAjoutRobot()
{

    /* A REVOIR CAR SI ON ANNULE DIRECTEMENT CA PLANTE
         creationRobot->deleteLater();
    */
    this->close();
}


void ViewGestionEquipe::ajouterRobotDansList()
{
    tableRobot->append(this->robotTemp);
    QList <QStandardItem*> listItem;

    if(!this->robotTemp.nomRobot.isEmpty() &&
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
 * @brief Vide tous les champs à l'initialisation de la fenetre création équipe
 */
void ViewGestionEquipe::resetTousLesChamps(){

    this->model = new QStandardItemModel();
    this->resultView->setModel(model);
    this->resultView->show();
}

/**
 * @brief Enregistrement de toutes l'équipe robot y compris dans la base de données
 */
void ViewGestionEquipe::declanchementSauvegardeCompleteEquipe()
{
    if(messageConfimationCreationEquipe()){
        sauvegardeEquipeEnBase();
        sauvegardeListeRobotsEnBase();
        reinitialisationChamps();
    }
}

/**
 * @brief Construction de l'équipe grâce à tout les parramétres de l'IHM
 */
void ViewGestionEquipe::recuperationAttributEquipe()
{
    equipe = new Equipe();
    equipe->nomEquipe = champNomEquipe->text();
}

/**
 * @brief Récupere le dernier ID d'équipe pour la création d'une nouvelle équipe
 * @return Dernier ID Equipe créé
 */
int ViewGestionEquipe::dernierIDEquipeEnBase()
{
    GestionDB * db = GestionDB::getInstance();
    db->selectMultiLignes("SELECT MAX(ID_Equipe) FROM equipe;");
    return db->resultatSelectMultiLignes.at(0).at(0).toInt();
}

/**
 * @brief Sauvegarde en base d'une nouvelle équipe
 * @return true si succès
 */
bool ViewGestionEquipe::sauvegardeEquipeEnBase()
{
    recuperationAttributEquipe();
    GestionDB * db = GestionDB::getInstance();
    QString requeteInsert = ("INSERT INTO EQUIPE (Nom_Equipe) VALUES (");
    requeteInsert.append(" '");
    requeteInsert.append(equipe->nomEquipe);
    requeteInsert.append("');");

    db->Requete(requeteInsert);

    return true ;
}

/**
 * @brief Sauvegarde en base d'une nouvelle liste de robot
 * @return true si succès
 */
bool ViewGestionEquipe::sauvegardeListeRobotsEnBase()
{
    equipe->idEquipe = dernierIDEquipeEnBase();
    bool firstVirgule = true;
    if(tableRobot->size()>0){
        QString requeteSQLInsert = " INSERT INTO ROBOT (`Nom_Robot` , `Longueur_Robot`, `Largeur_Robot`, `Vitesse_Robot`, `Longueur_Capacite_De_Charge_Robot`, `Largeur_Capactite_De_Charge_Robot`, `Poids_Capacite_De_Charge_Robot`, `ID_Equipe`) VALUES (" ;
        for (int i = 0; i<tableRobot->size();i++){
            if(!firstVirgule){
                requeteSQLInsert.append(" ),( ");
            }
            Robot robotTemp = tableRobot->at(i);
            requeteSQLInsert.append("'");
            requeteSQLInsert.append(robotTemp.nomRobot);
            requeteSQLInsert.append("',");
            requeteSQLInsert.append(QString::number(robotTemp.longueurRobot));
            requeteSQLInsert.append( ",");
            requeteSQLInsert.append(QString::number( robotTemp.largeurRobot));
            requeteSQLInsert.append(",");
            requeteSQLInsert.append(QString::number(robotTemp.vitesseRobot));
            requeteSQLInsert.append( ",");
            requeteSQLInsert.append(QString::number( robotTemp.longueurCapaciteDeCharge));
            requeteSQLInsert.append(",");
            requeteSQLInsert.append(QString::number( robotTemp.largeurCapactiteDeCharge));
            requeteSQLInsert.append(",");
            requeteSQLInsert.append(QString::number( robotTemp.poidsCapaciteDeCharge));
            requeteSQLInsert.append(",");
            requeteSQLInsert.append(QString::number( equipe->idEquipe));
            firstVirgule = false;
        }
        requeteSQLInsert.append("); ");
        GestionDB * db = GestionDB::getInstance();
        db->Requete(requeteSQLInsert);
    }
    return true ;
}


void ViewGestionEquipe::reinitialisationChamps()
{
    champNomEquipe->setText("");
    equipe = new Equipe();
    tableRobot->clear();
    resetTousLesChamps();
}

bool ViewGestionEquipe::messageConfimationCreationEquipe()
{
    if(!champNomEquipe->text().isEmpty() && tableRobot->size() > 0){
        labelConfirmation->setText("La nouvelle équipe vient d'être enregistrée");
        labelConfirmation->setStyleSheet("QLabel { color : green; }");
        labelConfirmation->show();
        return true ;
    }else{
        labelConfirmation->setText("Tous les champs doivent être remplis");
        labelConfirmation->setStyleSheet("QLabel { color : red; }");
        labelConfirmation->show();
     }
    return false;
}
