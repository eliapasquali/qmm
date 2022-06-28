QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = QMM
template = app

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    Controller/controller.cpp \
    Controller/homecontroller.cpp \
    Controller/linechartcontroller.cpp \
    View/view.cpp \
    View/homeview.cpp \
    View/linechartview.cpp \
    Model/model.cpp \
    Model/homemodel.cpp \
    Model/linechartmodel.cpp \
    transaction.cpp \
    account.cpp \
    json_import.cpp

HEADERS += \
    Controller/controller.h \
    Controller/homecontroller.h \
    Controller/linechartcontroller.h \
    View/view.h \
    View/homeview.h \
    View/linechartview.h \
    Model/model.h \
    Model/homemodel.h \
    Model/linechartmodel.h \
    transaction.h \
    account.h \
    json_import.h

RESOURCES += \

QMAKE_LFLAGS += -no-pie
