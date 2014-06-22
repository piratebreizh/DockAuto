
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
    viewcreationrobot.cpp \
    Tile.cpp \
    Cargaison.cpp \
    Entrepot.cpp \
    Map.cpp

HEADERS  += mainwindow.h \
    test.h \
    fenetreprincipale.h \
    viewgestionequipe.h \
    robot.h \
    equipe.h \
    viewcreationrobot.h \
    Tile.h \
    Cargaison.h \
    Entrepot.h \
    Map.h

FORMS    += mainwindow.ui
