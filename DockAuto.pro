
#-------------------------------------------------
#
# Project created by QtCreator 2014-06-17T19:46:45
#
#-------------------------------------------------

QT += core gui
QT += widgets
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DockAuto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fenetreprincipale.cpp \
    viewgestionequipe.cpp \
    robot.cpp \
    equipe.cpp \
    viewcreationrobot.cpp \
    Tile.cpp \
    Armoire.cpp \
    Cargaison.cpp \
    Entrepot.cpp \
    Map.cpp \
    gestiondb.cpp \
    viewcreationdepot.cpp \
    mapscene.cpp \
    viewmenusimulation.cpp \
    viewmenulistedestaches.cpp \
    tache.cpp \
    listetache.cpp \
    simulation.cpp \
    viewdefinirtache.cpp

HEADERS  += mainwindow.h \
    fenetreprincipale.h \
    viewgestionequipe.h \
    robot.h \
    equipe.h \
    viewcreationrobot.h \
    Tile.h \
    Armoire.h \
    Cargaison.h \
    Entrepot.h \
    Map.h \
    gestiondb.h \
    viewcreationdepot.h \
    mapscene.h \
    viewmenusimulation.h \
    viewmenulistedestaches.h \
    tache.h \
    listetache.h \
    simulation.h \
    viewdefinirtache.h

FORMS    += mainwindow.ui
