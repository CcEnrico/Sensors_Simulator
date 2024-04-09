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
bool ListSensor::hasControls() const{}
void ListSensor::setHasControls(const bool has_controls){}
QWidget* ListSensor::getWidget() const{}
QPushButton* ListSensor::getViewButton() const{}
QPushButton* ListSensor::getEditButton() const{}
QPushButton* ListSensor::getDeleteButton() const{}


}
