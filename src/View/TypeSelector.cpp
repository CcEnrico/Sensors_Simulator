#include "TypeSelector.h"

namespace View {

TypeSelector::TypeSelector(QComboBox* combo_box)
    : combo_box(combo_box)
{
}
void TypeSelector::visit(const Sensor::AirQualitySensor& air_quality){
    (void) air_quality;
    combo_box->setCurrentText("Air Quality Sensor");
    combo_box->setCurrentIndex(0);
}
void TypeSelector::visit(const Sensor::HumiditySensor& humidity){
    (void) humidity;
    combo_box->setCurrentText("Humidity Sensor");
    combo_box->setCurrentIndex(1);
}
void TypeSelector::visit(const Sensor::TemperatureSensor& temperature){
    (void) temperature;
    combo_box->setCurrentText("Temperature Sensor");
    combo_box->setCurrentIndex(2);
}

QComboBox* TypeSelector::getComboBox() {
    return combo_box;
}

TypeSelector& TypeSelector::setComboBox(QComboBox* combo_box) {
    this->combo_box = combo_box;
    return *this;
}

}