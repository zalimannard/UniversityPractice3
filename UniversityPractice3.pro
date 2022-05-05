QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpuparameter.cpp \
    diskparameter.cpp \
    fanparameter.cpp \
    fuzziparameter.cpp \
    gpuparameter.cpp \
    main.cpp \
    mainwindow.cpp \
    powerparameter.cpp \
    resultwindow.cpp \
    rule.cpp \
    temperatureparameter.cpp

HEADERS += \
    cpuparameter.h \
    diskparameter.h \
    fanparameter.h \
    fuzziparameter.h \
    gpuparameter.h \
    mainwindow.h \
    powerparameter.h \
    resultwindow.h \
    rule.h \
    temperatureparameter.h

FORMS += \
    mainwindow.ui \
    resultwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
