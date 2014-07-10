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
 * @brief Permet d'effectuer une requête INSERT, UPDATE, ALTER, ...
 *      Pour les selections, utilisé la fonction Select
 * @param req
 *
 */
void GestionDB::Requete(const QString &req)
{
    db.open();
    QSqlQuery query(db);
    if(!query.exec(req)){
       cout<<"Erreur lors de l'exécution de la requête : " << query.lastError().text().toStdString()<<endl;
    }

    db.close();
}

/**
 * @brief Permet de récupérer les résultats pour la requête envoyée en paramètre
 *      et le stocke dans ResultatRequete
 * @param sel
 *
 */
void GestionDB::Select(const QString &sel)
{
    db.open();
    ResultatRequete.clear();
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
 * @brief Récupère la première valeur de la requête
 */
void GestionDB::SelectFirst(const QString &)
{
    db.open();
    QSqlQuery query(db);
    if(query.size()>0)
    {
        ResultatRequete.push_back(query.value(1));
    }
    db.close();
}

/**
 * @brief Affiche les resultat de la requête dans la console
 */
void GestionDB::AfficheResultatsSelect()
{
    for(int i=0;i<NbResultatRequete;i++)
        cout<<ResultatRequete[i].toString().toStdString()<<endl;
}

QString GestionDB::getResultat(unsigned int i)
{
    if(ResultatRequete.size()>=i){
        return ResultatRequete[i].toString();
    }else{
        return "";
    }
}

GestionDB::~GestionDB()
{
    NbResultatRequete=0;
    ResultatRequete.clear();
    resultatSelectMultiLignes.clear();
    db.close();
}

/**
 * @brief Retourne un QSqlQuery d'un select avec plusieurs lignes
 * @param sel
 * @return QSqlQuery
 */
void GestionDB::selectMutliLigne(const QString &sel){
    db.open();
    resultatSelectMultiLignes.clear();
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

void GestionDB::afficherResultatSelectMultiple()
{
    for(int i = 0 ; i<resultatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp = resultatSelectMultiLignes.at(i);
        for(int y=0; y<qlistTemp.size();y++){
            qDebug()<<qlistTemp.at(y).toString();
        }
    }
}

int GestionDB::getNbResultat()
{
    return NbResultatRequete;
}
