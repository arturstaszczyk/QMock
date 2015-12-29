#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T17:34:42
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_QtMockTestTest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11 warn_on rtti exceptions

TEMPLATE = app

macx {
    QMAKE_MAC_SDK = macosx10.11
}

SOURCES += tst_QtMockTestTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    MockTester.h

unix|win32: LIBS += -L$$OUT_PWD/../QtMock/ -lQtMock

INCLUDEPATH += $$PWD/../QtMock
DEPENDPATH += $$PWD/../QtMock

win32:!win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../QtMock/QtMock.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../QtMock/libQtMock.a
