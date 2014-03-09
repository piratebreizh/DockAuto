QT += widgets

HEADERS     = FenetrePrincipale.h \
    ViewMap.h
SOURCES     = FenetrePrincipale.cpp \
              main.cpp \
    ViewMap.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/layouts/basiclayouts
INSTALLS += target
