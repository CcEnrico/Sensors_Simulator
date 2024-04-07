#ifndef VIEW_SENSOR_RENDERER_LISTSENSOR_H
#define VIEW_SENSOR_RENDERER_LISTSENSOR_H

#include"SSensorRenderer.h"

#include "../SensorListWidget.h"

namespace View {
namespace SensorRenderer {

class ListSensor : public SSensorRenderer
{
  private:
    bool has_controls;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    ListSensor();
    virtual void visit(const Sensor::AirQualitySensor& air_quality);
    virtual void visit(const Sensor::HumiditySensor& humidity);
    virtual void visit(const Sensor::TemperatureSensor& temperature);
    bool hasControls() const;
    void setHasControls(const bool has_controls);
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const;

};
}
}

#endif