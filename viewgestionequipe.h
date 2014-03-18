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

QT_BEGIN_NAMESPACE
class QLabel;
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE


class ViewGestionEquipe : public QDialog
{

public:

    QGridLayout nomEquipe();
    ViewGestionEquipe(QWidget *parent = 0);
    void creationTableauRobot();
    void enregistrerEquipe();


private:
    Equipe equipe;
    QLineEdit * champNomEquipe;
    QFormLayout *layoutSencondaire;
    QPushButton *ajouterRobot;
    QTableView *resultView;
    QPushButton *sauvegarde;
    QPushButton *annuler;
};

#endif // VIEWGESTIONEQUIPE_H
