#include"TemperatureSensor.h"

namespace Sensor {

TemperatureSensor::TemperatureSensor(
    unsigned int id,
    std::string  n,
    unsigned int dn,
    double d,
    double v,
    EnviromentalConditions::Temperature mn,
    EnviromentalConditions::Temperature mx,
    EnviromentalConditions::Temperature init,
    EnviromentalConditions::Temperature t
):
    AbstractSensor(id,n,dn,d,v),
    min(mn),
    max(mx),
    initial(init),
    target(t)
{}

void TemperatureSensor::simulate() {

}
void TemperatureSensor::clear() {

}
void TemperatureSensor::modify() {

}



}
