#include "Full.h"

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

void Full::visit(const Sensor::AirQualitySensor& air_quality){}
void Full::visit(const Sensor::HumiditySensor& humidity){}
void Full::visit(const Sensor::TemperatureSensor& temperature){}
QWidget* Full::getWidget() const{}
QPushButton* Full::getViewButton() const{}
QPushButton* Full::getEditButton() const{}
QPushButton* Full::getDeleteButton() const{}


}
}