<<<<<<< HEAD
#-------------------------------------------------
#
# Project created by QtCreator 2014-06-17T19:46:45
#
#-------------------------------------------------

QT += core gui
QT += widgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DockAuto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    test.cpp \
    fenetreprincipale.cpp \
    viewgestionequipe.cpp \
    robot.cpp \
    equipe.cpp \
    viewcreationrobot.cpp

HEADERS  += mainwindow.h \
    test.h \
    fenetreprincipale.h \
    viewgestionequipe.h \
    robot.h \
    equipe.h \
    viewcreationrobot.h

FORMS    += mainwindow.ui
=======
QT += widgets

HEADERS     = FenetrePrincipale.h \
    ViewMap.h \
    Equipe.h \
    Robot.h \
    Cargaison.h \
    ViewCreationRobot.h \
    ViewGestionEquipe.h \
    Entrepot.h \
    Armoire.h \
    Viewcreationentrepot.h \
    Tile.h \
    Map.h
SOURCES     = FenetrePrincipale.cpp \
              main.cpp \
    ViewMap.cpp \
    Equipe.cpp \
    Robot.cpp \
    Cargaison.cpp \
    ViewCreationRobot.cpp \
    ViewGestionEquipe.cpp \
    Entrepot.cpp \
    Armoire.cpp \
    Viewcreationentrepot.cpp \
    Tile.cpp \
    Map.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/layouts/basiclayouts
INSTALLS += target
>>>>>>> remotes/origin/antoine
