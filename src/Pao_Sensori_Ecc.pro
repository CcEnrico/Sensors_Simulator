QT       += core gui
QT += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Engine/SensorList.cpp \
    \
    Sensor/Airqualitysensor.cpp \
    Sensor/EnvironmentalConditions/Airquality.cpp \
    Sensor/EnvironmentalConditions/Humidity.cpp \
    Sensor/Humiditysensor.cpp \
    main.cpp \
    Sensor/Converter/Json/Json.cpp \
    Sensor/Converter/Json/JsonVisitor.cpp \
    Sensor/Converter/Json/Reader.cpp \
    Sensor/DataMapper/JsonFile.cpp \
    Sensor/Repository/JsonRepository.cpp \
    \
    Sensor/AbstractSensor.cpp \
    Sensor/TemperatureSensor.cpp \
    Sensor/EnvironmentalConditions/Temperature.cpp \
    View/mainwindow.cpp \
    View/SensorListWidget.cpp \
    View/SearchWidget.cpp \
    View/EditWidget.cpp \
    View/EditWindow.cpp \
    View/TypeSelector.cpp \
    View/WidgetLookup.cpp \
    View/SensorWidget.cpp \
    View/GraphLookup.cpp \
    View/SensorEditor/AbstractSensorEditor.cpp \
    View/SensorEditor/AirQualityEditor.cpp \
    View/SensorEditor/HumidityEditor.cpp \
    View/SensorEditor/TemperatureEditor.cpp \
    View/SensorEditor/SensorInjector.cpp \
    View/SensorRenderer/ListSensor.cpp \
    View/ListRenderer/List.cpp \
    View/GraphRenderer/StandardSimulator.cpp \
    View/GraphRenderer/SimulationVisitor.cpp \
    View/GraphRenderer/Graph.cpp \
    View/GraphRenderer/Full.cpp

HEADERS += \
    Engine/SensorList.h \
    \
    Sensor/Airqualitysensor.h \
    Sensor/EnvironmentalConditions/Airquality.h \
    Sensor/EnvironmentalConditions/Humidity.h \
    Sensor/EnvironmentalConditions/Temperature.h \
    Sensor/Humiditysensor.h \
    Sensor/SConstVisitor.h \
    Sensor/SVisitor.h \
    \
    Sensor/AbstractSensor.h \
    Sensor/TemperatureSensor.h \
    Sensor/Converter/Json/SReader.h \
    Sensor/Converter/Json/Json.h \
    Sensor/Converter/Json/JsonVisitor.h \
    Sensor/Converter/Json/Reader.h \
    Sensor/DataMapper/JsonFile.h \
    Sensor/Repository/IRepository.h \
    Sensor/Repository/JsonRepository.h \
    \
    View/mainwindow.h \
    View/SensorListWidget.h \
    View/SearchWidget.h \
    View/EditWidget.h \
    View/EditWindow.h \
    View/TypeSelector.h \
    View/WidgetLookup.h \
    View/SensorWidget.h \
    View/GraphLookup.h \
    View/SensorEditor/AbstractSensorEditor.h \
    View/SensorEditor/AirQualityEditor.h \
    View/SensorEditor/HumidityEditor.h \
    View/SensorEditor/SensorInjector.h \
    View/SensorEditor/TemperatureEditor.h \
    View/SensorRenderer/SSensorRenderer.h \
    View/SensorRenderer/ListSensor.h \
    View/ListRenderer/SRendererStrategy.h \
    View/ListRenderer/List.h \
    View/GraphRenderer/SGraphRenderer.h \
    View/GraphRenderer/SGraphSimulator.h \
    View/GraphRenderer/StandardSimulator.h \
    View/GraphRenderer/SimulationVisitor.h \
    View/GraphRenderer/Graph.h \
    View/GraphRenderer/Full.h

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
