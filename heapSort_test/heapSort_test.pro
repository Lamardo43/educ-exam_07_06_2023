QT += testlib network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_func.cpp \
    ../Server/functions.cpp \
    ../Server/mytcpserver-ex.cpp

HEADERS += \
    ../Server/functions.h \
    ../Server/mytcpserver-ex.h
