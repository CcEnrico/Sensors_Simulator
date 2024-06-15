#ifndef VIEW_SENSOR_EDITOR_ABSTRACT_SENSOR_EDITOR_H
#define VIEW_SENSOR_EDITOR_ABSTRACT_SENSOR_EDITOR_H

#include <QWidget>
#include <QString>

#include "../../Sensor/AbstractSensor.h"


namespace View::SensorEditor {

class AbstractSensorEditor: public QWidget {
    Q_OBJECT
  public:
    explicit AbstractSensorEditor(QWidget* parent = nullptr);
    ~AbstractSensorEditor() override;
    virtual Sensor::AbstractSensor* create(
        unsigned int identifier,
        const QString& name,
        unsigned int data_number
    ) const = 0;
};

}

#endif  // VIEW_SENSOR_EDITOR_ABSTRACT_SENSOR_EDITOR_H