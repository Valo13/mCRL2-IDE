#-------------------------------------------------
#
# Project created by QtCreator 2018-05-22T14:58:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mCRL2-IDE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    propertiesdock.cpp \
    consoledock.cpp \
    rewritedock.cpp \
    solvedock.cpp \
    addeditpropertydialog.cpp \
    propertywidget.cpp \
    codeeditor.cpp \
    findandreplacedialog.cpp \
    filesystem.cpp \
    processsystem.cpp

HEADERS += \
        mainwindow.h \
    propertiesdock.h \
    consoledock.h \
    rewritedock.h \
    solvedock.h \
    addeditpropertydialog.h \
    propertywidget.h \
    codeeditor.h \
    findandreplacedialog.h \
    filesystem.h \
    processsystem.h

RESOURCES += \
    mcrl2-ide.qrc

FORMS += \
    addeditpropertydialog.ui \
    findandreplacedialog.ui
