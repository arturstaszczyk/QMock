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

CONFIG(debug, debug|release):{
    DESTDIR = $$PWD/lib/debug
}
else:CONFIG(release, debug|release):{
    DESTDIR = $$PWD/lib/release
}

SOURCES += \
    QtMock.cpp

HEADERS += QtMock.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

macx {
    QMAKE_MAC_SDK = macosx10.11
}

