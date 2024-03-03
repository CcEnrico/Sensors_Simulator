#include "Humiditysensor.h"

namespace Sensor{

HumiditySensor::HumiditySensor(unsigned int id,
    std::string  n,
    unsigned int dn,
    double v,
    EnviromentalConditions::Humidity init,
    EnviromentalConditions::Humidity stddev,
    EnviromentalConditions::Humidity t
    ):
    AbstractSensor(id,n,dn,v),
    initial(init),
    stdDeviation(stddev),
    target(t)
{}


EnviromentalConditions::Humidity HumiditySensor::getHumInitial()const{
    return initial;
}

HumiditySensor& HumiditySensor::setHumInitial(const EnviromentalConditions::Humidity init){
    this->initial = init;
    return *this;
}
EnviromentalConditions::Humidity HumiditySensor::getHumStdDeviation()const{
    return stdDeviation;
}
HumiditySensor& HumiditySensor::setHumStdDeviation(const EnviromentalConditions::Humidity stddev){
    this->stdDeviation = stddev;
    return *this;
}

EnviromentalConditions::Humidity HumiditySensor::getHumTarget()const{
    return target;
}

HumiditySensor& HumiditySensor::setHumTargt(const EnviromentalConditions::Humidity t){
    this->target = t;
    return *this;
}

void HumiditySensor::accept(SConstVisitor &visitor) const{
    visitor.visit(*this);
}
void HumiditySensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}

void HumiditySensor::simulate() {

}
void HumiditySensor::clear() {

}
void HumiditySensor::modify() {

}


const EnviromentalConditions::Humidity min = EnviromentalConditions::Humidity(0.0);
const EnviromentalConditions::Humidity max = EnviromentalConditions::Humidity(100.0);

}

