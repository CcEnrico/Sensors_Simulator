#include "AbstractSensor.h"

namespace Sensor{

AbstractSensor::AbstractSensor(unsigned int id,
                              std::string  n,
                              unsigned int dn,
                              double d,
                              double v
                               ): identifier(id), name(n), dataNum(dn), deviation(d), variance(v){}

AbstractSensor::~AbstractSensor(){

}

unsigned int AbstractSensor::getIdentifier() const{
    return identifier;
}
const std::string& AbstractSensor::getName() const{
    return name;
}
AbstractSensor& AbstractSensor::setName(const std::string s){
    this->name = s;
    return *this;
}
unsigned int AbstractSensor::getDataNum() const{
    return dataNum;
}
AbstractSensor& AbstractSensor::setDataNum(const unsigned int dn){
    this->dataNum = dn;
    return *this;
}
double AbstractSensor::getDeviation()const{
    return deviation;
}
AbstractSensor& AbstractSensor::setDeviation(const double d){
    this->deviation = d;
    return *this;
}
double AbstractSensor::getVariance()const{
    return variance;
}
AbstractSensor& AbstractSensor::setVariance(const double v){
    this->variance = v;
    return *this;
}

}

