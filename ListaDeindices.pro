TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    leerentero.h \
    ListaDoble.h \
    Nododoble.h \
    Programa.h \
    Indice.h \
    Secundario.h \
    Nodosecundario.h

