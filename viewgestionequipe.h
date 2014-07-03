#ifndef VIEWGESTIONEQUIPE_H
#define VIEWGESTIONEQUIPE_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <QDialog>
#include<qgridlayout.h>
#include<Equipe.h>
#include<qlineedit.h>
#include<qtableview.h>
#include<qformlayout.h>
#include <ViewCreationRobot.h>
#include <Robot.h>
#include <stdio.h>
#include <stdio.h>
#include <qstandarditemmodel.h>
#include <qdebug.h>
#include <QCoreApplication>
#include <QtSql>
#include <gestiondb.h>

QT_BEGIN_NAMESPACE
class QLabel;
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE



class ViewCreationRobot;

class ViewGestionEquipe : public QDialog
{
    Q_OBJECT

public:

    QGridLayout nomEquipe();
    ViewGestionEquipe(QWidget *parent = 0);
    void creationTableauRobot();
    void enregistrerEquipe();
    Robot  robotTemp;

public slots:
    void appelAjoutRobot();
    void ajouterRobotDansList();
    void deleteViewAjoutRobot();
    void declanchementSauvegardeCompleteEquipe();

private:
    Equipe *equipe;
    QLineEdit * champNomEquipe;
    QFormLayout *layoutSencondaire;
    QPushButton *ajouterRobot;

    QTableView *resultView;
    QStandardItemModel * model;

    QPushButton *sauvegarde;
    QPushButton *annuler;
    ViewCreationRobot *creationRobot;

    QList <Robot> * tableRobot;

    GestionDB * gestionDB;

    void resetTousLesChamps();
    int dernierIDEquipeEnBase();
    void recuperationAttributEquipe();
    bool sauvegardEquipeEnBase();
    bool sauvegardListeRobotEnBase();
    bool sauvegardLienEquipeRobot();
};

#endif // VIEWGESTIONEQUIPE_H
