#include "ListSensor.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>

#include "../../Sensor/Airqualitysensor.h"
#include "../../Sensor/Humiditysensor.h"
#include "../../Sensor/TemperatureSensor.h"

namespace View {
namespace SensorRenderer {

ListSensor::ListSensor()
    : has_controls(true)
{
}

// da implementare
void ListSensor::visit(const Sensor::AirQualitySensor& air_quality){}
void ListSensor::visit(const Sensor::HumiditySensor& humidity){}
void ListSensor::visit(const Sensor::TemperatureSensor& temperature){}
bool ListSensor::hasControls() const{}
void ListSensor::setHasControls(const bool has_controls){}
QWidget* ListSensor::getWidget() const{}
QPushButton* ListSensor::getViewButton() const{}
QPushButton* ListSensor::getEditButton() const{}
QPushButton* ListSensor::getDeleteButton() const{}


}
}