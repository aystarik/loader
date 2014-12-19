QT += widgets

HEADERS       = hud.h
SOURCES       = main.cpp \
                hud.cpp
RESOURCES     = basicdrawing.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
INSTALLS += target
