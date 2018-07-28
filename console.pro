TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    src/thread/threadpool.cpp

HEADERS += \
    src/thread/threadpool.h

QMAKE_CXXFLAGS += -std=c++0x
LIBS += -pthread
