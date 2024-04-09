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

double AirQualitySensor::getInitialPm10()const{
    return initial.getPm10();
}

double AirQualitySensor::getInitialNO2()const{
    return initial.getNO2();
}

AirQualitySensor& AirQualitySensor::setAQInitial(const EnviromentalConditions::AirQuality init){
    this->initial = init;
    return *this;
}

AirQualitySensor& AirQualitySensor::setInitialPm10(const double pm10){
    this->initial.setPm10(pm10);
    return *this;
}

AirQualitySensor& AirQualitySensor::setInitialNO2(const double no2){
    this->initial.setNO2(no2);
    return *this;
}

EnviromentalConditions::AirQuality AirQualitySensor::getAQStdDeviation()const{
    return stdDeviation;
}

double AirQualitySensor::getStdDeviationPm10()const{
    return stdDeviation.getPm10();
}

double AirQualitySensor::getStdDeviationNO2()const{
    return stdDeviation.getNO2();
}

AirQualitySensor& AirQualitySensor::setAQStdDeviation(const EnviromentalConditions::AirQuality stddev){
    this->stdDeviation = stddev;
    return *this;
}

AirQualitySensor& AirQualitySensor::setStdDeviationPm10(const double pm10){
    this->stdDeviation.setPm10(pm10);
    return *this;
}

AirQualitySensor& AirQualitySensor::setStdDeviationNO2(const double no2){
    this->stdDeviation.setNO2(no2);
    return *this;
}

EnviromentalConditions::AirQuality AirQualitySensor::getAQTarget()const{
    return target;
}

double AirQualitySensor::getTargetPm10()const{
    return target.getPm10();
}

double AirQualitySensor::getTargetNO2()const{
    return target.getNO2();
}

AirQualitySensor& AirQualitySensor::setAQTarget(const EnviromentalConditions::AirQuality t){
    this->target = t;
    return *this;
}

AirQualitySensor& AirQualitySensor::setTargetPm10(const double pm10){
    this->target.setPm10(pm10);
    return *this;
}

AirQualitySensor& AirQualitySensor::setTargetNO2(const double no2){
    this->target.setNO2(no2);
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

