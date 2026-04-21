QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# 只保留头文件路径
INCLUDEPATH += $$PWD/../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include

# ========= 删掉原来 -lAirlineDLL 这一行！！！=========

# 把所有飞机业务源码全部加进来，Qt一次性编译
SOURCES += \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/AbstractAircraft.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/AircraftFactory.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/AircraftPrinter.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/Airline.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/AirlineService.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/CargoPlane.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/CargoPlaneFactory.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/CivilAircraft.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/PassengerJet.cpp \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/src/PassengerJetFactory.cpp \
    addeditdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/AbstractAircraft.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/AircraftFactory.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/AircraftPrinter.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/Airline.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/AirlineService.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/CargoPlane.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/CargoPlaneFactory.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/CivilAircraft.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/PassengerJet.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/PassengerJetFactory.h \
    ../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include/dll_export.h \
    addeditdialog.h \
    mainwindow.h

FORMS += \
    addeditdialog.ui \
    mainwindow.ui

# 删掉Windows DLL宏！Linux不需要
# DEFINES += AIRLINEDLL_EXPORTS

