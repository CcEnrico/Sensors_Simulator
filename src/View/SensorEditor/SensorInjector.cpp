#include "SensorInjector.h"

namespace View {
namespace SensorEditor {



SensorInjector::SensorInjector (
    AirQualityEditor& air_quality_editor,
    HumidityEditor& humidity_editor,
    TemperatureEditor& temperature_editor
)
    : air_quality_editor(air_quality_editor),
    humidity_editor(humidity_editor),
    temperature_editor(temperature_editor)
{
}

void SensorInjector::visit(const Sensor::AirQualitySensor& air_quality_sensor) {
    air_quality_editor.setValues(air_quality_sensor);
}

void SensorInjector::visit(const Sensor::HumiditySensor& humidity_sensor) {
    humidity_editor.setValues(humidity_sensor);
}

void SensorInjector::visit(const Sensor::TemperatureSensor& temperature_sensor) {
    temperature_editor.setValues(temperature_sensor);
}


}
}