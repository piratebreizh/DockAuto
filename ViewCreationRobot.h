#ifndef VIEWCREATIONROBOT_H
#define VIEWCREATIONROBOT_H

#include <Robot.h>
#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <QDialog>
#include<qgridlayout.h>
#include<Equipe.h>
#include<qlineedit.h>
#include<qtableview.h>
#include<qformlayout.h>
#include<qgroupbox.h>

QT_BEGIN_NAMESPACE
class QLabel;
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE


class ViewCreationRobot : public QDialog
{
    Q_OBJECT
public:
    ViewCreationRobot(Robot & tempRobot);


public slots:
    void s_clicked();

private:

    QGridLayout *layout;
    QGridLayout *layout2;

    QGroupBox * structureRobot;
    QGroupBox * cargaisonRobot;

    QLineEdit * champNom;
    QLineEdit * champLargeur;
    QLineEdit * champLongueur;
    QLineEdit * champVitesse;
    QLineEdit * champCargaisonLargeur;
    QLineEdit * champCargaisonLongueur;
    QLineEdit * champCargaisonPoids;

    QPushButton *sauvegarde;
    QPushButton *annuler;

    Robot robotTemp;

};

#endif // VIEWCREATIONROBOT_H
