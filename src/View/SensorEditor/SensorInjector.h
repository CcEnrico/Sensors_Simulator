#ifndef VIEW_SENSOR_EDITOR_SENSOR_INJECTOR_H
#define VIEW_SENSOR_EDITOR_SENSOR_INJECTOR_H

#include "../../Sensor/SConstVisitor.h"
#include "AirQualityEditor.h"
#include "TemperatureEditor.h"
#include "HumidityEditor.h"

namespace View {
namespace SensorEditor {

class SensorInjector: public Sensor::SConstVisitor {
  private:
    AirQualityEditor& air_quality_editor;
    // HumidityEditor& humidity_editor;
    // TemperatureEditor& temperature_editor;

  public:
    SensorInjector(
        AirQualityEditor& air_quality_editor
        // HumidityEditor& humidity_editor
        // TemperatureEditor& temperature_editor, 
    );
    virtual void visit(const Sensor::AirQualitySensor& air_quality);
    virtual void visit(const Sensor::HumiditySensor& humidity);
    virtual void visit(const Sensor::TemperatureSensor& temperature);
};

}
}

#endif