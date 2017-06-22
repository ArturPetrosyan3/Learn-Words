#-------------------------------------------------
#
# Project created by QtCreator 2015-11-26T03:02:42
#
#-------------------------------------------------

QT       += core gui sql declarative webkitwidgets multimedia axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


include("C:/Users/arturp/Documents/chart/nightcharts-master/nightcharts.pri")

TARGET = LearnWords
TEMPLATE = app
win32:RC_ICONS += Window_ico.ico

SOURCES += main.cpp\
        mainwindow.cpp \
    front.cpp \
    fr.cpp \
    settings.cpp \
    message.cpp \
    chartxy/chartxy.cpp \
    chartxy/chartxyalgoritm.cpp \
    chartxy/chartxyborder.cpp \
    chartxy/chartxyfunction.cpp \
    chartxy/chartxygrid.cpp \
    chartxy/chartxygridtick.cpp \
    chartxy/chartxylimit.cpp \
    chartxy/chartxylimitaxis.cpp \
    chartxy/chartxyrender.cpp \
    chartxy/chartxyscale.cpp \
    chartxy/chartxysetting.cpp \
    frame.cpp \
    charts/axisbase.cpp \
    charts/barchartplotter.cpp \
    charts/plotterbase.cpp \
    drag/draglabel.cpp \
    drag/dragwidget.cpp \
    my_grid_layout.cpp

HEADERS  += mainwindow.h \
    front.h \
    fr.h \
    settings.h \
    message.h \
    chartxy/chartxy.h \
    chartxy/chartxyalgoritm.h \
    chartxy/chartxyborder.h \
    chartxy/chartxyfunction.h \
    chartxy/chartxygrid.h \
    chartxy/chartxygridtick.h \
    chartxy/chartxylimit.h \
    chartxy/chartxylimitaxis.h \
    chartxy/chartxyrender.h \
    chartxy/chartxyscale.h \
    chartxy/chartxysetting.h \
    frame.h \
    charts/axisbase.h \
    charts/barchartplotter.h \
    charts/plotterbase.h \
    drag/draglabel.h \
    drag/dragwidget.h \
    my_grid_layout.h

FORMS    += mainwindow.ui \
    front.ui \
    fr.ui \
    settings.ui \
    message.ui

DISTFILES += \
    main.qml

RESOURCES += \
    resurce.qrc
