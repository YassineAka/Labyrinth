QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = LabyrinthProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    model/case.cpp \
    model/casei.cpp \
    model/casel.cpp \
    model/caset.cpp \
    model/labyrinth.cpp \
    model/plate.cpp \
    model/player.cpp \
    model/position.cpp \
    box.cpp \
    board.cpp \
    window.cpp \
    subject.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    model/case.h \
    model/casei.h \
    model/casel.h \
    model/caset.h \
    model/color.h \
    model/controller.h \
    model/labyrinth.h \
    model/objective.h \
    model/plate.h \
    model/player.h \
    model/position.h \
    model/view.h \
    box.h \
    board.h \
    window.h \
    observer.h \
    subject.h

RESOURCES += \
    images.qrc
