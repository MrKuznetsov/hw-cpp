TEMPLATE = app
CONFIG += console
QT += \
             testlib\
               core

SOURCES += main.cpp \
    bubblesort.cpp \
    arraysort.cpp

HEADERS += \
    bubblesort.h \
    arraysort.h \
    bubblesortTest.h

