#-------------------------------------------------
#
# Project created by QtCreator 2013-08-29T19:10:41
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = qt_osg
TEMPLATE = app

DESTDIR=./bin
OBJECTS_DIR=.obj
MOC_DIR=.obj

SOURCES += \
    kee/config.cpp \
    kee/Math.cpp \
    kee/timer.cpp \
    kee/ViewWidget.cpp \
    kee/SceneMange.cpp \
    src/mainwindow.cpp \
    src/main.cpp

HEADERS  += \
    kee/config.h \
    kee/Math.h \
    kee/timer.h \
    kee/ViewWidget.h \
    kee/SceneMange.h \
    src/mainwindow.h

FORMS    += \
    src/mainwindow.ui

INCLUDEPATH+=./include ./kee

LIBS+=-L/usr/local/lib64 -losg -losgQt -losgGA -losgText -losgShadow -losgViewer -losgDB -losgUtil -losgSim -losgTerrain -losgManipulator -losgWidget
