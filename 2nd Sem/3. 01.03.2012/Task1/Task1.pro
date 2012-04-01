TEMPLATE = app
CONFIG += console
QT += \
             testlib\
               core

SOURCES += main.cpp \
    arraysort.cpp \
    bubblesort.cpp \
    quicksort.cpp

HEADERS += \
    arraysort.h \
    bubblesort.h \
    quicksort.h \
    bubblesortTest.h \
    quicksortTest.h

