#ifndef VIEW_SENSOR_EDITOR_AIR_QUALITY_EDITOR_H
#define VIEW_SENSOR_EDITOR_AIR_QUALITY_EDITOR_H

#include <QWidget>
#include <QDoubleSpinBox>

#include "AbstractSensorEditor.h"

namespace View {
namespace SensorEditor {

class AirQualityEditor: public AbstractSensorEditor {
  private:
    QDoubleSpinBox* initial;
    QDoubleSpinBox* stdDeviation;
    QDoubleSpinBox* target;

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