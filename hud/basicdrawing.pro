QT += widgets

HEADERS       = hud.h
SOURCES       = main.cpp \
                hud.cpp
RESOURCES     = basicdrawing.qrc
QMAKE_CXXFLAGS  += -std=c++11

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
INSTALLS += target
