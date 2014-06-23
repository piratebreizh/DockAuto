QT += widgets
QT += sql
QT -= gui # On enlève la GUI

HEADERS     = FenetrePrincipale.h \
    Equipe.h \
    Robot.h \
    ViewCreationRobot.h \
    ViewGestionEquipe.h \
    viewcreationdepot.h
SOURCES     = FenetrePrincipale.cpp \
              main.cpp \
    Equipe.cpp \
    Robot.cpp \
    ViewCreationRobot.cpp \
    ViewGestionEquipe.cpp \
    viewcreationdepot.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/layouts/basiclayouts
INSTALLS += target
