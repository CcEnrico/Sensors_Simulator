QT       += core gui
QT += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    Engine/SensorList.cpp \
    \
    Sensor/AbstractSensor.cpp \
    Sensor/Airqualitysensor.cpp \
    Sensor/Converter/Json/Json.cpp \
    Sensor/Converter/Json/JsonVisitor.cpp \
    Sensor/Converter/Json/Reader.cpp \
    Sensor/DataMapper/JsonFile.cpp \
    Sensor/EnvironmentalConditions/Airquality.cpp \
    Sensor/EnvironmentalConditions/Humidity.cpp \
    Sensor/EnvironmentalConditions/Temperature.cpp \
    Sensor/Humiditysensor.cpp \
    Sensor/Repository/JsonRepository.cpp \
    Sensor/TemperatureSensor.cpp \
    \
    View/EditWidget.cpp \
    View/EditWindow.cpp \
    View/GraphRenderer/Full.cpp \
    View/GraphRenderer/Graph.cpp \
    View/GraphSimulator/SimulationVisitor.cpp \
    View/GraphSimulator/StandardSimulator.cpp \
    View/ListRenderer/List.cpp \
    View/ListRenderer/ListRenderer.cpp \
    View/mainwindow.cpp \
    View/SearchWidget.cpp \
    View/SensorEditor/AbstractSensorEditor.cpp \
    View/SensorEditor/AirQualityEditor.cpp \
    View/SensorEditor/HumidityEditor.cpp \
    View/SensorEditor/SensorInjector.cpp \
    View/SensorEditor/TemperatureEditor.cpp \
    View/SensorEditor/TypeSelector.cpp \
    View/SensorListWidget.cpp \
    View/SensorLookup/GraphLookup.cpp \
    View/SensorLookup/WidgetLookup.cpp \
    View/SensorWidget.cpp

HEADERS += \
    Engine/SensorList.h \
    \
    Sensor/AbstractSensor.h \
    Sensor/Airqualitysensor.h \
    Sensor/Converter/Json/Json.h \
    Sensor/Converter/Json/JsonVisitor.h \
    Sensor/Converter/Json/Reader.h \
    Sensor/Converter/Json/SReader.h \
    Sensor/DataMapper/JsonFile.h \
    Sensor/EnvironmentalConditions/Airquality.h \
    Sensor/EnvironmentalConditions/Humidity.h \
    Sensor/EnvironmentalConditions/Temperature.h \
    Sensor/Humiditysensor.h \
    Sensor/Repository/IRepository.h \
    Sensor/Repository/JsonRepository.h \
    Sensor/SConstVisitor.h \
    Sensor/SVisitor.h \
    Sensor/TemperatureSensor.h \
    \
    View/EditWidget.h \
    View/EditWindow.h \
    View/GraphRenderer/Full.h \
    View/GraphRenderer/Graph.h \
    View/GraphRenderer/SGraphRenderer.h \
    View/GraphSimulator/SGraphSimulator.h \
    View/GraphSimulator/SimulationVisitor.h \
    View/ListRenderer/List.h \
    View/ListRenderer/ListRenderer.h \
    View/ListRenderer/SRendererStrategy.h \
    View/ListRenderer/SSensorRenderer.h \
    View/mainwindow.h \
    View/SearchWidget.h \
    View/SensorEditor/AbstractSensorEditor.h \
    View/SensorEditor/AirQualityEditor.h \
    View/SensorEditor/HumidityEditor.h \
    View/SensorEditor/SensorInjector.h \
    View/SensorEditor/TemperatureEditor.h \
    View/SensorEditor/TypeSelector.h \
    View/SensorListWidget.h \
    View/SensorLookup/GraphLookup.h \
    View/SensorLookup/WidgetLookup.h \
    View/SensorWidget.h

RESOURCES += \
    resources.qrc \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
