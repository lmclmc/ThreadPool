TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    src/global.cpp \
    src/strings/String.cpp \
    src/check/md5check.cpp

HEADERS += \
    src/global.h \
    src/strings/String.h \
    src/check/md5check.h
