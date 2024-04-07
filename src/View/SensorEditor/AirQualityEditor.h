#ifndef VIEW_SENSOR_EDITOR_AIR_QUALITY_EDITOR_H
#define VIEW_SENSOR_EDITOR_AIR_QUALITY_EDITOR_H

#include <QWidget>
#include <QDoubleSpinBox>

#include "AbstractSensorEditor.h"

namespace View {
namespace SensorEditor {

class AirQualityEditor: public AbstractSensorEditor {
  private:
    QDoubleSpinBox* initial_pm10;
    QDoubleSpinBox* initial_n02;
    QDoubleSpinBox* stdDeviation_pm10;
    QDoubleSpinBox* stdDeviation_n02;
    QDoubleSpinBox* target_pm10;
    QDoubleSpinBox* target_n02;

  public:
    AirQualityEditor(QWidget* parent = 0);
    virtual ~AirQualityEditor();

    virtual Sensor::AbstractSensor* create(
        const unsigned int identifier,
        const QString& name,
        const unsigned int data_number,
        const double variance
    ) const;
    
    void setValues(const Sensor::AirQualitySensor& air_quality_sensor);
};

}
}

#endif