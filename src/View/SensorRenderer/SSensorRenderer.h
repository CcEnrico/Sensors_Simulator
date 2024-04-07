#ifndef VIEW_SENSOR_RENDERER_SSENSORRENDERER_H
#define VIEW_SENSOR_RENDERER_SSENSORRENDERER_H

#include <QWidget>
#include <QPushButton>

#include "../../Sensor/AbstractSensor.h"
#include "../../Sensor/SConstVisitor.h"

namespace View {
namespace SensorRenderer {

class SSensorRenderer: public Sensor::SConstVisitor {
  public:
    virtual QWidget* getWidget() const = 0;
    virtual QPushButton* getViewButton() const = 0;
    virtual QPushButton* getEditButton() const = 0;
    virtual QPushButton* getDeleteButton() const = 0;
};

}
}

#endif