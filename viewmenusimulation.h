#ifndef VIEWMENUSIMULATION_H
#define VIEWMENUSIMULATION_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>


class ViewMenuSimulation : public QDialog
{
    Q_OBJECT

public:
    ViewMenuSimulation();
    void initialisationComposantFenetreMenuSimulation();

public slots:
    //void layoutNouvelleSimulation();

private:

    QVBoxLayout *mainLayout;

    QGridLayout *layoutMenuChoixSauvegardCharger;


    QPushButton * nouvelleSimulation;
    QPushButton * chargerSimulation;

    QLabel * labelNomSimulation;
    QLineEdit * champNomSimulation;

    QLabel * labelChoixEquipe;
    QLabel * labelConfirmationEquipe;
    QPushButton * boutonChoisirEquipe;

    QLabel * labelTache;
    QLabel * labelConfirmationTache;
    QPushButton * boutonDefinirTache;

    QPushButton * sauvegarderSimulation;
    QPushButton * definirCommeSimulation;

    void definitionMainLayout();
    void definitionLayoutMenuChoixSauvegardeCharger();
};

#endif // VIEWMENUSIMULATION_H
