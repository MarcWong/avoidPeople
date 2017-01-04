#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T15:40:28
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = avoidPeople_module
TEMPLATE = lib

DEFINES += AVOIDPEOPLE_MODULE_LIBRARY

SOURCES += avoidpeople_module.cpp

HEADERS += avoidpeople_module.h\
        avoidpeople_module_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

PROJNAME = avoidPeople_module
INSTTYPE = MOD
include(RobotSDK_Main.pri)