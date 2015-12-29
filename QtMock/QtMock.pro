#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T17:34:15
#
#-------------------------------------------------

QT       -= gui

TARGET = QtMock
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11 warn_on rtti exceptions

SOURCES += QtMock.cpp

HEADERS += QtMock.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

macx {
    QMAKE_MAC_SDK = macosx10.11
}

