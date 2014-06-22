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




private:
    Equipe equipe;
    QLineEdit * champNomEquipe;
    QFormLayout *layoutSencondaire;
    QPushButton *ajouterRobot;

    QTableView *resultView;
    QStandardItemModel * model;

    QPushButton *sauvegarde;
    QPushButton *annuler;
    ViewCreationRobot *creationRobot;

    QList <Robot> tableRobot;



    //void resetTousLesChamps();
};

#endif // VIEWGESTIONEQUIPE_H
