#ifndef VIEW_SENSOR_EDITOR_HUMIDITY_EDITOR_H
#define VIEW_SENSOR_EDITOR_HUMIDITY_EDITOR_H

#include "AbstractSensorEditor.h"
#include "../../Sensor/Humiditysensor.h"

#include <QDoubleSpinBox>


namespace View::SensorEditor{

class HumidityEditor: public AbstractSensorEditor {
  private:
    QDoubleSpinBox* initial;
    QDoubleSpinBox* stdDeviation;
    QDoubleSpinBox* rain_probability;

  public:
    explicit HumidityEditor(QWidget* parent = 0);
    ~HumidityEditor() override;

    Sensor::AbstractSensor* create(
        const unsigned int identifier,
        const QString& name,
        const unsigned int data_number,
        const double variance
    ) const override;
    
    void setValues(const Sensor::HumiditySensor& humidity_sensor);
};

}


#endif