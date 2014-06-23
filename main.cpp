/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>

#include <FenetrePrincipale.h>

#include "Map.h"
#include "Armoire.h"
#include "Entrepot.h"
#include "Robot.h"
#include <iostream>
#include <QSqlDatabase>

using namespace std;
/*
QSqlDatabase ConnexionDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("DockAutodb");
}*/

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FenetrePrincipale premierVue;


    premierVue.show();

    return app.exec();

    /*//http://fr.openclassrooms.com/informatique/cours/maitrisez-les-bases-de-donnees-avec-qtsql
    QSqlDatabase db = ConnexionDb();
    if(db.open())
    {
        cout<< "Vous êtes maintenant connecté à " << db.hostName().toStdString() << endl;
    }
    else
    {
        cout << "La connexion a échouée, désolé" << endl;
    }
    //db.close();



    /*TEST MAP*/
    /*Entrepot e;
    Armoire a;
    Robot r;
    e.AfficheMap();
    cout<<"MAP 1"<<endl<<endl;
    a.setX(1);
    a.setY(1);
    r.setX(3);
    r.setY(3);
    e.AddArmoire(a);
    e.AddRobot(r);
    e.AfficheMap();
    cout<<"MAP 2"<<endl<<endl;
    r.move(e,2,2);
    e.AfficheMap();
    cout<<"MAP 3"<<endl<<endl;
    r.move(e,1,1);
    e.AfficheMap();
    cout<<"MAP 4"<<endl<<endl;
    */

    /*TEST EQUIPE*/
    /*Robot r1(1,"bob");
    Robot r2(2,"bob2");
    Robot r3(3,"bob3");
    Equipe e(1,"Equipe1");
    e.AddEquipe(r1);
    e.AddEquipe(r2);
    e.AddEquipe(r3);
    e.AfficheEquipe();
    e.RemoveEquipe(r2);
    e.AfficheEquipe();*/
    return 0;
}



