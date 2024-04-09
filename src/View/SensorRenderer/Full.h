#ifndef VIEW_ITEM_RENDERER_FULL_H
#define VIEW_ITEM_RENDERER_FULL_H

#include "SSensorRenderer.h"
#include "ListSensor.h"




namespace View::SensorRenderer {

class Full: public SSensorRenderer {
  private:
    ListSensor list_sensor;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    void visit(const Sensor::AirQualitySensor& air_quality) override;
    void visit(const Sensor::HumiditySensor& humidity) override;
    void visit(const Sensor::TemperatureSensor& temperature) override;
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const; 
};

}


#endif