#include "Airqualitysensor.h"

namespace Sensor{

AirQualitySensor::AirQualitySensor(
    unsigned int id,
    std::string  n,
    unsigned int dn,
    double d,
    double v,
    EnviromentalConditions::AirQuality init,
    EnviromentalConditions::AirQuality t
    ):
    AbstractSensor(id, n, dn, d, v),
    initial(init),
    target(t)
{
}

EnviromentalConditions::AirQuality AirQualitySensor::getHumInitial()const{
    return initial;
}

AirQualitySensor& AirQualitySensor::setHumInitial(const EnviromentalConditions::AirQuality init){
    this->initial = init;
    return *this;
}
EnviromentalConditions::AirQuality AirQualitySensor::getHumTarget()const{
    return target;
}
AirQualitySensor& AirQualitySensor::setHumTargt(const EnviromentalConditions::AirQuality t){
    this->target = t;
    return *this;
}


void AirQualitySensor::simulate(){

}
void AirQualitySensor::clear(){

}
void AirQualitySensor::modify(){

}

const EnviromentalConditions::AirQuality optimal = EnviromentalConditions::AirQuality(0.0);
const EnviromentalConditions::AirQuality good = EnviromentalConditions::AirQuality(50.0);
const EnviromentalConditions::AirQuality acceptable = EnviromentalConditions::AirQuality(70.0);
const EnviromentalConditions::AirQuality mediocre = EnviromentalConditions::AirQuality(100.0);
const EnviromentalConditions::AirQuality poor = EnviromentalConditions::AirQuality(150.0);
const EnviromentalConditions::AirQuality veryBad = EnviromentalConditions::AirQuality(200.0);


}

