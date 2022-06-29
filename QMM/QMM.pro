QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = QMM
template = app

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    Controller/*.cpp \
    View/*.cpp \
    Model/*.cpp \
    transaction.cpp \
    account.cpp \
    json_import.cpp

HEADERS += \
    Controller/*.h \
    View/*.h \
    Model/*.h \
    transaction.h \
    account.h \
    json_import.h

RESOURCES += \

QMAKE_LFLAGS += -no-pie
