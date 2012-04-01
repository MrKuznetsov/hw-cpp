TEMPLATE = app
CONFIG += console
QT += \
             testlib\
               core

SOURCES += main.cpp \
    arraystack.cpp \
    pointstack.cpp \
    calculator.cpp

HEADERS += \
    stack.h \
    arraystack.h \
    pointstack.h \
    calculator.h \
    arraystackTest.h \
    pointstackTest.h

