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
