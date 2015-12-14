#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T20:13:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = skeleton
CONFIG   += console qdbus
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    route_manager.cpp \
    route_manager_adp.cpp \
    route_controls_adp.cpp \
    route_controls.cpp \
    nvsd_data_iface.cpp

HEADERS += \
    ../route_manager_adp.h \
    route_manager.h \
    route_manager_adp.h \
    route_controls.h \
    route_controls_adp.h \
    nvsd_data_iface.h
