QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = QMM
TEMPLATE = app

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Controller/areachartcontroller.cpp \
    Model/areachartmodel.cpp \
    View/areachartview.cpp \
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
    json_export.cpp \
    json_import.cpp

HEADERS += \
    Controller/areachartcontroller.h \
    Controller/linechartcontroller.h \
    Controller/homecontroller.h \
    Controller/controller.h \
    Controller/barchartcontroller.h \
    Controller/piechartcontroller.h \
    Controller/scatterchartcontroller.h \
    Model/areachartmodel.h \
    View/areachartview.h \
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
    json_import.h \
    json_export.h

RESOURCES = \
    resources.qrc

ICON = Resources/qmm_icon.ico

QMAKE_LFLAGS += -no-pie
