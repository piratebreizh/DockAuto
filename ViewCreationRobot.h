#ifndef VIEWCREATIONROBOT_H
#define VIEWCREATIONROBOT_H

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
public:
    ViewCreationRobot(QWidget *parent = 0);

private:

    QGroupBox * structureRobot;
    QFormLayout * cargaisonRobot;

    QLineEdit * champLargeur;
    QLineEdit * champLongueur;
    QLineEdit * champVitesse;
    QLineEdit * champCargaisonLargeur;
    QLineEdit * champCargaisonLongueur;
    QLineEdit * champCargaisonPoids;

    QPushButton *sauvegarde;
    QPushButton *annuler;


};

#endif // VIEWCREATIONROBOT_H
