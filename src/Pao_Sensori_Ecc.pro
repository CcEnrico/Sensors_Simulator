QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sensor/Airqualitysensor.cpp \
    Sensor/EnvironmentalConditions/Airquality.cpp \
    Sensor/EnvironmentalConditions/Humidity.cpp \
    Sensor/Humiditysensor.cpp \
    main.cpp \
    \
    Sensor/AbstractSensor.cpp \
    Sensor/TemperatureSensor.cpp \
    Sensor/EnvironmentalConditions/Temperature.cpp \
    View/mainwindow.cpp \
    View/ResultWidget.cpp \
    View/SearchWidget.cpp \
    View/EditWidget.cpp \
    View/SensorEditor/AbstractSensorEditor.cpp \
    View/SensorRenderer/Full.cpp \
    View/SensorRenderer/ListSensor.cpp

HEADERS += \
    Sensor/Airqualitysensor.h \
    Sensor/EnvironmentalConditions/Airquality.h \
    Sensor/EnvironmentalConditions/Humidity.h \
    Sensor/Humiditysensor.h \
    Sensor/SConstVisitor.h \
    Sensor/SVisitor.h \
    \
    Sensor/AbstractSensor.h \
    Sensor/TemperatureSensor.h \
    Sensor/EnvironmentalConditions/Temperature.h \
    View/mainwindow.h \
    View/ResultWidget.h \
    View/SearchWidget.h \
    View/EditWidget.h \
    View/SensorEditor/AbstractSensorEditor.h \
    View/SensorRenderer/SSensorRenderer.h \
    View/SensorRenderer/Full.h \
    View/SensorRenderer/ListSensor.h

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
