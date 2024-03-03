#include"TemperatureSensor.h"

namespace Sensor {

TemperatureSensor::TemperatureSensor(unsigned int id,
    std::string  n,
    unsigned int dn,
    double v,
    EnviromentalConditions::Temperature mn,
    EnviromentalConditions::Temperature mx,
    EnviromentalConditions::Temperature init,
    EnviromentalConditions::Temperature stddev,
    EnviromentalConditions::Temperature t
):
    AbstractSensor(id,n,dn,v),
    min(mn),
    max(mx),
    initial(init),
    stdDeviation(stddev),
    target(t)
{}

EnviromentalConditions::Temperature TemperatureSensor::getTempMin()const{
    return min;
}
TemperatureSensor& TemperatureSensor::setTempMin(const EnviromentalConditions::Temperature m){
    this->min = m;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getTempMax()const {
    return max;
}
TemperatureSensor& TemperatureSensor::setTempMax(const EnviromentalConditions::Temperature m){
    this->max = m;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getStdDeviation()const {
    return stdDeviation;
}
TemperatureSensor& TemperatureSensor::setStdDeviation(const EnviromentalConditions::Temperature stddev){
    this->stdDeviation = stddev;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getTempInitial()const {
    return initial;
}
TemperatureSensor& TemperatureSensor::setTempInitial(const EnviromentalConditions::Temperature init){
    this->initial = init;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getTempTarget()const{
    return target;
}
TemperatureSensor& TemperatureSensor::setTempTarget(const EnviromentalConditions::Temperature t){
    this->target = t;
    return *this;
}

void TemperatureSensor::accept(SConstVisitor &visitor) const{
    visitor.visit(*this);
}
void TemperatureSensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}

void TemperatureSensor::simulate() {

}
void TemperatureSensor::clear() {

}
void TemperatureSensor::modify() {

}



}
