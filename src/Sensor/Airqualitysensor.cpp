#include "Airqualitysensor.h"

namespace Sensor{

AirQualitySensor::AirQualitySensor(unsigned int id,
    std::string  n,
    unsigned int dn,
    double v,
    EnviromentalConditions::AirQuality init,
    EnviromentalConditions::AirQuality stddev,
    EnviromentalConditions::AirQuality t
    ):
    AbstractSensor(id, n, dn, v),
    initial(init),
    stdDeviation(stddev),
    target(t)
{
}

EnviromentalConditions::AirQuality AirQualitySensor::getAQInitial()const{
    return initial;
}

AirQualitySensor& AirQualitySensor::setAQInitial(const EnviromentalConditions::AirQuality init){
    this->initial = init;
    return *this;
}
EnviromentalConditions::AirQuality AirQualitySensor::getAQStdDeviation()const{
    return stdDeviation;
}
AirQualitySensor& AirQualitySensor::setAQStdDeviation(const EnviromentalConditions::AirQuality stddev){
    this->stdDeviation = stddev;
    return *this;
}
EnviromentalConditions::AirQuality AirQualitySensor::getAQTarget()const{
    return target;
}
AirQualitySensor& AirQualitySensor::setAQTarget(const EnviromentalConditions::AirQuality t){
    this->target = t;
    return *this;
}

void AirQualitySensor::accept(SConstVisitor &visitor) const{
    visitor.visit(*this);
}
void AirQualitySensor::accept(SVisitor &visitor){
    visitor.visit(*this);
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

