#ifndef VIEW_ITEM_RENDERER_FULL_H
#define VIEW_ITEM_RENDERER_FULL_H

#include "SSensorRenderer.h"
#include "ListSensor.h"



namespace View {
namespace SensorRenderer {

class Full: public SSensorRenderer {
  private:
    ListSensor list_sensor;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    virtual void visit(const Sensor::AirQualitySensor& air_quality);
    virtual void visit(const Sensor::HumiditySensor& humidity);
    virtual void visit(const Sensor::TemperatureSensor& temperature);
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const; 
};

}
}

#endif