TEMPLATE = app
CONFIG += console
QT += \
             testlib\
               core

SOURCES += main.cpp \
    stringlist.cpp \
    stringhash.cpp \
    randomfunction.cpp

HEADERS += \
    hash.h \
    hashfunction.h \
    stringlist.h \
    stringhash.h \
    randomfunction.h \
    stringhashTest.h \
    stringlistTest.h \
    hashlist.h

