#ifndef HUMIDITY_H
#define HUMIDITY_H

#include"Abstractenviromentalcondition.h"
#include"Temperature.h"

namespace Sensor{

namespace EnviromentalConditions{


class Humidity : public AbstractEnviromentalCondition
{
    double absoluteHumidity;    // g/m3
    double relativeHumidity;    // %
    Temperature temperature;

public:
    Humidity(double rh, Temperature t );

    double getRelativeHumidity()const ;
    Humidity& setRelativeHumidity(const double rh);
    Temperature getTemperature()const;
    Humidity& setTemperatureCelsius(const double t);

private:
    static void calculateAh();

};

}

}

#endif // HUMIDITY_H
