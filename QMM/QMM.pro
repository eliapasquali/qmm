QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = QMM
template = app

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    Controller/linechartcontroller.cpp \
    Controller/homecontroller.cpp \
    Controller/controller.cpp \
    View/view.cpp \
    View/homeview.cpp \
    View/linechartview.cpp \
    Model/model.cpp \
    Model/linechartmodel.cpp \
    Model/homemodel.cpp \
    transaction.cpp \
    account.cpp \
    json_import.cpp \
    Model/barchartmodel.cpp \
    View/barchartview.cpp \
    Controller/barchartcontroller.cpp \
        View/piechartview.cpp \
    Controller/piechartcontroller.cpp \
    Model/piechartmodel.cpp

HEADERS += \
    Controller/linechartcontroller.h \
    Controller/homecontroller.h \
    Controller/controller.h \
    View/view.h \
    View/homeview.h \
    View/linechartview.h \
    Model/model.h \
    Model/linechartmodel.h \
    Model/homemodel.h \
    transaction.h \
    account.h \
    json_import.h \
    Model/barchartmodel.h \
    View/barchartview.h \
    Controller/barchartcontroller.h \
    View/piechartview.h \
    Controller/piechartcontroller.h \
    Model/piechartmodel.h

RESOURCES += \

QMAKE_LFLAGS += -no-pie
