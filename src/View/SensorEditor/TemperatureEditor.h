#ifndef VIEW_SENSOR_EDITOR_TEMPERATURE_EDITOR_H
#define VIEW_SENSOR_EDITOR_TEMPERATURE_EDITOR_H

#include "AbstractSensorEditor.h"
#include "../../Sensor/TemperatureSensor.h"

#include <QDoubleSpinBox>
#include <QComboBox>


namespace View::SensorEditor{

class TemperatureEditor: public AbstractSensorEditor {
  private:

    QComboBox* unit;
    char unit_char;
    QDoubleSpinBox* min;
    QDoubleSpinBox* max;
    QDoubleSpinBox* initial;
    QDoubleSpinBox* stdDeviation;
    QDoubleSpinBox* target;
    Sensor::EnviromentalConditions::Temperature min_temp;
    Sensor::EnviromentalConditions::Temperature max_temp;
    Sensor::EnviromentalConditions::Temperature initial_temp;
    Sensor::EnviromentalConditions::Temperature stdDeviation_temp;
    Sensor::EnviromentalConditions::Temperature target_temp;


    void setTemperatureValues(char u);

    public:
    
    explicit TemperatureEditor(QWidget* parent = 0);
    ~TemperatureEditor() override;

    Sensor::AbstractSensor* create(
        const unsigned int identifier,
        const QString& name,
        const unsigned int data_number
    ) const override;
    
    void setValues(const Sensor::TemperatureSensor& temperature_sensor);

    public slots:
    
    void unitChangedIndex(int index);
    void unitChangedChar(char u);


};

}


#endif