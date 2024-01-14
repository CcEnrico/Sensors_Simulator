#include "Humiditysensor.h"

namespace Sensor{

HumiditySensor::HumiditySensor(
    unsigned int id,
    std::string  n,
    unsigned int dn,
    double d,
    double v,
    const EnviromentalConditions::Humidity init,
    const EnviromentalConditions::Humidity t
    ):
    AbstractSensor(id,n,dn,d,v),
    initial(init),
    target(t)
{}


EnviromentalConditions::Humidity HumiditySensor::getHumInitial()const{
    return initial;
}

HumiditySensor& HumiditySensor::setHumInitial(const EnviromentalConditions::Humidity init){
    this->initial = init;
    return *this;
}

EnviromentalConditions::Humidity HumiditySensor::getHumTarget()const{
    return target;
}

HumiditySensor& HumiditySensor::setHumTargt(const EnviromentalConditions::Humidity t){
    this->target = t;
    return *this;
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

