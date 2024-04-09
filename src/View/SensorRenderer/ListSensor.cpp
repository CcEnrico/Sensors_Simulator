#include "ListSensor.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>

#include "../../Sensor/Airqualitysensor.h"
#include "../../Sensor/Humiditysensor.h"
#include "../../Sensor/TemperatureSensor.h"


namespace View::SensorRenderer {

ListSensor::ListSensor()
    : has_controls(true)
{
}

// da implementare
void ListSensor::visit(const Sensor::AirQualitySensor& air_quality){
    QLabel* label = new QLabel("Air Quality Sensor");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label);
    widget = new QWidget();
    widget->setLayout(layout);

}

void ListSensor::visit(const Sensor::HumiditySensor& humidity){}

void ListSensor::visit(const Sensor::TemperatureSensor& temperature){}

bool ListSensor::hasControls() const{
    return has_controls;
}

void ListSensor::setHasControls(const bool c){
    this->has_controls = c;
}

QWidget* ListSensor::getWidget() const{
    return widget;
}

QPushButton* ListSensor::getViewButton() const{
    return view_button;
}

QPushButton* ListSensor::getEditButton() const{
    return edit_button;
}

QPushButton* ListSensor::getDeleteButton() const{
    return delete_button;
}


}
