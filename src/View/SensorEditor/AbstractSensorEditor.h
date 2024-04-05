#ifndef VIEW_SENSOR_EDITOR_ABSTRACT_SENSOR_EDITOR_H
#define VIEW_SENSOR_EDITOR_ABSTRACT_SENSOR_EDITOR_H

#include <QWidget>
#include <QString>

#include "../../Sensor/AbstractSensor.h"

namespace View {
namespace SensorEditor {

class AbstractSensorEditor: public QWidget {
    Q_OBJECT
  public:
    AbstractSensorEditor(QWidget* parent = 0);
    virtual ~AbstractSensorEditor();
    virtual Sensor::AbstractSensor* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const = 0;
};

}
}

#endif