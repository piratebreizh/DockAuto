#ifndef VIEWMENULISTEDESTACHES_H
#define VIEWMENULISTEDESTACHES_H
#include <viewmenusimulation.h>
#include <QtWidgets>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <tache.h>
#include <listetache.h>
#include <viewdefinirtache.h>

class ViewMenuSimulation;
class ViewDefinirTache;


class ViewMenuListeDesTaches: public QDialog
{
    Q_OBJECT
public:
    ViewMenuListeDesTaches(ViewMenuSimulation * _viewMenuSimulation);
    void initialisationComposant();
    void definitonLayout();
    ViewDefinirTache * viewDefinirTache;
    ViewMenuSimulation * viewMenuSimulation;


public slots :
    void executerViewDefinirTache();


private :

    QVBoxLayout *mainLayout;
    QGridLayout *layout1;

    QLabel * labelNomTacheListe;
    QLineEdit * champNomTacheListe;

    QLabel * labelListeTache;
    QTableView * tableListeTache;
    QStandardItemModel * model;

    QPushButton * pushAjouterTache;
    QPushButton * pushSauvegarder;
    QPushButton * pushAnnuler;

    Listetache * listeTache;


};

#endif // VIEWMENULISTEDESTACHES_H
