#ifndef VIEW_SENSOR_EDITOR_TEMPERATURE_EDITOR_H
#define VIEW_SENSOR_EDITOR_TEMPERATURE_EDITOR_H

#include "AbstractSensorEditor.h"
#include "../../Sensor/TemperatureSensor.h"

#include <QDoubleSpinBox>
#include <QComboBox>

namespace View{
namespace SensorEditor{

class TemperatureEditor: public AbstractSensorEditor {
  private:

    QComboBox* unit;
    char unit_char;
    QDoubleSpinBox* min;
    QDoubleSpinBox* max;
    QDoubleSpinBox* initial;
    QDoubleSpinBox* stdDeviation;
    QDoubleSpinBox* target;

    // EnviromentalConditions::Temperature min;
    // EnviromentalConditions::Temperature max;
    // EnviromentalConditions::Temperature initial;
    // EnviromentalConditions::Temperature stdDeviation;
    // EnviromentalConditions::Temperature target;

    public:
    
    TemperatureEditor(QWidget* parent = 0);
    virtual ~TemperatureEditor();

    virtual Sensor::AbstractSensor* create(
        const unsigned int identifier,
        const QString& name,
        const unsigned int data_number,
        const double variance
    ) const;
    
    void setValues(const Sensor::TemperatureSensor& temperature_sensor);

    public slots:
    
    void unitChanged(int index);
};

}
}

#endif