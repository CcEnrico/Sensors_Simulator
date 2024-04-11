#ifndef VIEW_SENSOR_EDITOR_ABSTRACT_SENSOR_EDITOR_H
#define VIEW_SENSOR_EDITOR_ABSTRACT_SENSOR_EDITOR_H

#include <QWidget>
#include <QString>

#include "../../Sensor/AbstractSensor.h"


namespace View::SensorEditor {

class AbstractSensorEditor: public QWidget {
    Q_OBJECT
  public:
    AbstractSensorEditor(QWidget* parent = 0);
    ~AbstractSensorEditor() override;
    virtual Sensor::AbstractSensor* create(
        const unsigned int identifier,
        const QString& name,
        const unsigned int data_number,
        const double variance
    ) const = 0;
};

}


#endif