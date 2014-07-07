#include "gestiondb.h"
#include <QSqlQuery>
#include<QSqlError>
#include <QSqlRecord>
#include <QString>
#include <iostream>
#include <QDebug>

using namespace std;

GestionDB::GestionDB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
}

GestionDB::GestionDB(const QString &_HostName, const QString& _UserName, const QString& _Password, const QString& _DatabaseName){
    db = QSqlDatabase::addDatabase("QMYSQL");
    HostName= _HostName;
    UserName=_UserName;
    Password=_Password;
    DatabaseName=_DatabaseName;
}

/**
 * @brief GestionDB::Requete
 * @param req
 * Permet d'effectuer une requete INSERT, UPDATE, ALTER, ...
 * Pour les selections, utilisé la fonction Select
 */
void GestionDB::Requete(const QString &req){
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(HostName);
    db.setUserName(UserName);
    db.setPassword(Password);
    db.setDatabaseName(DatabaseName);
    db.open();
    QSqlQuery query(db);
    if(query.exec(req)){
        cout<<"La requete c'est bien passee"<<endl;
    }else{
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
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(HostName);
    db.setUserName(UserName);
    db.setPassword(Password);
    db.setDatabaseName(DatabaseName);
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
    db.setHostName(HostName);
    db.setUserName(UserName);
    db.setPassword(Password);
    db.setDatabaseName(DatabaseName);
    db.open();
    QSqlQuery query(db);
    if(query.size()>0)
    {
        ResultatRequete.push_back(query.value(1));
    }
}

/**
 * @brief GestionDB::AfficheResultatsSelect
 * Affiche les resultat de la requête dans la console
 */
void GestionDB::AfficheResultatsSelect(){
    for(int i=0;i<NbResultatRequete;i++)
        cout<<ResultatRequete[i].toString().toStdString()<<endl;
}

QString GestionDB::getResultat(int i){
    if(ResultatRequete.size()>0){
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
    db.setHostName(HostName);
    db.setUserName(UserName);
    db.setPassword(Password);
    db.setDatabaseName(DatabaseName);
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
          reusltatSelectMultiLignes.append(ligne);

        }
    }
    else{
        NbResultatRequete=0;
        ResultatRequete.clear();
    }
    db.close();
}


void GestionDB::afficherResultatSelectMultiple(){
    for(int i = 0 ; i<reusltatSelectMultiLignes.size();i++){
        QList <QVariant> qlistTemp = reusltatSelectMultiLignes.at(i);
        for(int y=0; y<qlistTemp.size();y++){
            qDebug()<<qlistTemp.at(y).toString();
        }
    }
}












