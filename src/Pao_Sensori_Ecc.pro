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
    View/SensorListWidget.cpp \
    View/SearchWidget.cpp \
    View/EditWidget.cpp \
    View/TypeSelector.cpp \
    View/WidgetLookup.cpp \
    View/SensorEditor/AbstractSensorEditor.cpp \
    View/SensorEditor/AirQualityEditor.cpp \
    View/SensorEditor/HumidityEditor.cpp \
    View/SensorEditor/TemperatureEditor.cpp \
    View/SensorEditor/SensorInjector.cpp \
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
    View/SensorListWidget.h \
    View/SearchWidget.h \
    View/EditWidget.h \
    View/TypeSelector.h \
    View/WidgetLookup.h \
    View/SensorEditor/AbstractSensorEditor.h \
    View/SensorEditor/AirQualityEditor.h \
    View/SensorEditor/HumidityEditor.h \
    View/SensorEditor/SensorInjector.h \
    View/SensorEditor/TemperatureEditor.h \
    View/SensorRenderer/SSensorRenderer.h \
    View/SensorRenderer/Full.h \
    View/SensorRenderer/ListSensor.h

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
