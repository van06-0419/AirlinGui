QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

INCLUDEPATH += $$PWD/../下载/AirlineFactory-main/AirlineFactory/AirlineDLL/include

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
    
