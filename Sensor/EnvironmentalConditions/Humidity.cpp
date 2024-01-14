#include "Humidity.h"

namespace Sensor{

namespace EnviromentalConditions{

Humidity::Humidity(double rh): relativeHumidity(rh){}

double Humidity::getRelativeHumidity()const{
    return relativeHumidity;
}

Humidity& Humidity::setRelativeHumidity(const double rh){
    this->relativeHumidity = rh;
    return *this;
}

}
}


