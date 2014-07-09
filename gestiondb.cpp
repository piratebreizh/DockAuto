#include "gestiondb.h"
#include <QSqlQuery>
#include<QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QDebug>
#include <QSettings>


using namespace std;


GestionDB *GestionDB::_singleton = NULL;

GestionDB::GestionDB()
{
      db = QSqlDatabase::addDatabase("QMYSQL");

      QSettings settings(":/res/configDB.ini", QSettings::IniFormat);
      HostName =settings.value("CONFIGDATABASE/hostname").toString();
      UserName =settings.value("CONFIGDATABASE/username").toString();
      Password =settings.value("CONFIGDATABASE/password").toString();
      DatabaseName =settings.value("CONFIGDATABASE/databasename").toString();
      db.setHostName(HostName);
      db.setUserName(UserName);
      db.setPassword(Password);
      db.setDatabaseName(DatabaseName);

}

/**
 * @brief GestionDB::Requete
 * @param req
 * Permet d'effectuer une requete INSERT, UPDATE, ALTER, ...
 * Pour les selections, utilisé la fonction Select
 */
void GestionDB::Requete(const QString &req){
    db.open();
    QSqlQuery query(db);
    if(!query.exec(req)){
       cout<<"Erreur lors de l'execution de la requete " << query.lastError().text().toStdString()<<endl;
    }

    db.close();
}

/**
 * @brief GestionDB::Select
 * @param sel
 * Permet de récupérer les résultats pour la requête envoyé en paramètre
 * et le stocke dans ResultatRequete
 */
void GestionDB::Select(const QString &sel){
    db.open();
    QSqlQuery query(db);
    if(query.exec(sel) && query.size()>0)
    {
        NbResultatRequete=query.record().count();
        while(query.next())
        {
            for(int x=0; x < query.record().count(); ++x)
            {
                ResultatRequete.push_back(query.value(x));
            }
        }
    }
    else{
        NbResultatRequete=0;
        ResultatRequete.clear();
    }
    db.close();
}

/**
 * @brief GestionDB::SelectFirst
 * Récupère la première valeur de la requête
 */

void GestionDB::SelectFirst(const QString &){
    db.open();
    QSqlQuery query(db);
    if(query.size()>0)
    {
        ResultatRequete.push_back(query.value(1));
    }
    db.close();
}

/**
 * @brief GestionDB::AfficheResultatsSelect
 * Affiche les resultat de la requête dans la console
 */
void GestionDB::AfficheResultatsSelect(){
    for(int i=0;i<NbResultatRequete;i++)
        cout<<ResultatRequete[i].toString().toStdString()<<endl;
}

QString GestionDB::getResultat(unsigned int i){
    if(ResultatRequete.size()>=i){
        return ResultatRequete[i].toString();
    }else{
        return "";
    }
}

GestionDB::~GestionDB(){
    NbResultatRequete=0;
    ResultatRequete.clear();
    db.close();
}

/**
 * @brief GestionDB::SelectWithQsqlQuery
 * @param sel
 * @return QSqlQuery
 * retourn un QSqlQuery d'un select avec plusieurs lignes
 */
void GestionDB::selectMutliLigne(const QString &sel){
    db.open();
    QSqlQuery query(db);
    if(query.exec(sel) && query.size()>0)
    {

        NbResultatRequete=query.record().count();
        while(query.next())
        {
            QList <QVariant> ligne;
            for(int x=0; x < NbResultatRequete; ++x)
            {

                ligne.append(QVariant (query.value(x)));
            }
          resultatSelectMultiLignes.append(ligne);

        }
    }
    else{
        NbResultatRequete=0;
        ResultatRequete.clear();
    }
    db.close();
}


void GestionDB::afficherResultatSelectMultiple(){
    for(int i = 0 ; i<resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp = resultatSelectMultiLignes.at(i);
        for(int y=0; y<qlistTemp.size();y++){
            qDebug()<<qlistTemp.at(y).toString();
        }
    }
}

int GestionDB::getNbResultat(){
    return NbResultatRequete;
}











