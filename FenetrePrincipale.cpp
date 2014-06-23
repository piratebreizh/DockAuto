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


#include "FenetrePrincipale.h"
#include <QtWidgets>
#include "ui_mainwindow.h"



//! [0]
FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QMainWindow(parent)
{

    ui = new Ui::MainWindow;
    ui->setupUi(this);


    //createMenu();
   // createHorizontalGroupBox();
    //createGridGroupBox();
    //createFormGroupBox();

     createBarreDeLancement();

     //viewmap = new ViewMap;

//! [0]

//! [1]
    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                               "in the top-level layout."));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);





    QHBoxLayout *mainLayout = new QHBoxLayout;

 //   mainLayout->setMenuBar(menuBar);


    mainLayout->addWidget(barreLancement);
    //mainLayout->addWidget(viewmap);


//! [4] //! [5]
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);

    //setWindowTitle(tr("Basic Layouts"));*/
}
//! [5]

//! [6]
void FenetrePrincipale::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}
//! [6]

//! [7]
/*void FenetrePrincipale::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
    layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}*/
//! [7]

//! [8]
void FenetrePrincipale::createGridGroupBox()
{

    gridGroupBox = new QGroupBox(tr("Grid layout"));
//! [8]
    QGridLayout *layout = new QGridLayout;

//! [9]
    for (int i = 0; i < NumGridRows; ++i) {
        labels[i] = new QLabel(tr("Line %1:").arg(i + 1));
        lineEdits[i] = new QLineEdit;
        layout->addWidget(labels[i], i + 1, 0);
        layout->addWidget(lineEdits[i], i + 1, 1);
    }

//! [9] //! [10]
    smallEditor = new QTextEdit;
    smallEditor->setPlainText(tr("This widget takes up about two thirds of the "
                                 "grid layout."));
    layout->addWidget(smallEditor, 0, 2, 4, 1);
//! [10]

//! [11]
    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    gridGroupBox->setLayout(layout);
}
//! [11]

//! [12]
void FenetrePrincipale::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);

    QComboBox *a = new QComboBox();

    QStringList *b = new QStringList();
    b->append("Premier");
    b->append("Deuxième");

    a->addItems(*b);

    layout->addRow(new QLabel(tr("Line 2, long text:")), a);
    ;
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
}
//! [12]


void FenetrePrincipale::createBarreDeLancement(){
    barreLancement = new QGroupBox(tr("Barre de lancement"));

    QHBoxLayout *layout = new QHBoxLayout;

    gestionDesEquipe = new QPushButton(tr("&Gestion des équipes"));
    gestionDesEquipe->setFocusPolicy(Qt::NoFocus);
    nouvelleSimulation = new QPushButton(tr("&Nouvelle simulation"));
    nouvelleSimulation->setFocusPolicy(Qt::NoFocus);
    gestionDesDepots = new QPushButton(tr("&Gestion des dépots"));
    demarrerSimulation = new QPushButton(tr("&Start"));
    demarrerSimulation->setFocusPolicy(Qt::NoFocus);
    pauseSimulation = new QPushButton(tr("&Stop"));
    pauseSimulation->setFocusPolicy(Qt::NoFocus);

    layout->addWidget(nouvelleSimulation);
    layout->addWidget(gestionDesEquipe);
    layout->addWidget(gestionDesDepots);
    layout->addWidget(demarrerSimulation);
    layout->addWidget(pauseSimulation);

    //Gestion des evenements sur les boutons
    //Equipe
    viewGestionEquipe = new ViewGestionEquipe;
    QWidget::connect(gestionDesEquipe, SIGNAL(clicked()), viewGestionEquipe, SLOT(exec()));
    //Depot
    viewEntrepot = new ViewEntrepot;
    QWidget::connect(gestionDesDepots, SIGNAL(clicked()), viewEntrepot, SLOT(exec()));

    barreLancement->setLayout(layout);
}
