#include "AbstractSensor.h"

#include <utility>

namespace Sensor{

AbstractSensor::AbstractSensor(unsigned int id,
                              std::string n,
                              unsigned int dn
                               ): identifier(id), name(std::move(n)), dataNum(dn){}

AbstractSensor::~AbstractSensor() = default;

unsigned int AbstractSensor::getIdentifier() const{
    return identifier;
}
const std::string& AbstractSensor::getName() const{
    return name;
}
AbstractSensor& AbstractSensor::setName(const std::string& s){
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

}

