#include "Humidity.h"

namespace Sensor{

namespace EnviromentalConditions{

Humidity::Humidity(double rh): relativeHumidity(rh){}

Humidity::operator double() const {
    return relativeHumidity;
}

double Humidity::getRelativeHumidity()const{
    return relativeHumidity;
}

Humidity& Humidity::setRelativeHumidity(const double rh){
    this->relativeHumidity = rh;
    return *this;
}

}
}


