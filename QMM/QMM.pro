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
    Controller/barchartcontroller.cpp \
    Controller/piechartcontroller.cpp \
    Controller/scatterchartcontroller.cpp \
    View/view.cpp \
    View/homeview.cpp \
    View/linechartview.cpp \
    View/barchartview.cpp \
    View/piechartview.cpp \
    View/scatterchartview.cpp \
    Model/model.cpp \
    Model/homemodel.cpp \
    Model/linechartmodel.cpp \
    Model/piechartmodel.cpp \
    Model/barchartmodel.cpp \
    Model/scatterchartmodel.cpp \
    transaction.cpp \
    account.cpp \
    json_import.cpp
    
HEADERS += \
    Controller/linechartcontroller.h \
    Controller/homecontroller.h \
    Controller/controller.h \
    Controller/barchartcontroller.h \
    Controller/piechartcontroller.h \
    Controller/scatterchartcontroller.h \
    View/view.h \
    View/homeview.h \
    View/linechartview.h \
    View/barchartview.h \
    View/piechartview.h \
    View/scatterchartview.h \
    Model/model.h \
    Model/linechartmodel.h \
    Model/homemodel.h \
    Model/barchartmodel.h \
    Model/piechartmodel.h \
    Model/scatterchartmodel.h \
    transaction.h \
    account.h \
    json_import.h

RESOURCES += \

QMAKE_LFLAGS += -no-pie
