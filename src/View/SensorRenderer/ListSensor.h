#ifndef VIEW_SENSOR_RENDERER_LISTSENSOR_H
#define VIEW_SENSOR_RENDERER_LISTSENSOR_H

#include"SSensorRenderer.h"

#include "../SensorListWidget.h"


namespace View::SensorRenderer {

class ListSensor : public SSensorRenderer {
  private:
    bool has_controls;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    ListSensor();
    void visit(const Sensor::AirQualitySensor& air_quality) override;
    void visit(const Sensor::HumiditySensor& humidity) override;
    void visit(const Sensor::TemperatureSensor& temperature) override;
    bool hasControls() const;
    void setHasControls(const bool c);
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const;

};
}


#endif