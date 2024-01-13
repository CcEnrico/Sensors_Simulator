#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include"Abstractenviromentalcondition.h"

namespace Sensor{

namespace EnviromentalConditions{

class Temperature: public AbstractEnviromentalCondition
{
    double kelvin;
    double celsius;
    double fahrenheit;

public:
    Temperature(double kelvin);
    Temperature(double celsius);
    Temperature(double fahrenheit);

    EnviromentalConditions& setKelvin(const double k);
    double getKelvin() const;
    EnviromentalConditions& setCelsius(const double c);
    double getCelsius() const;
    EnviromentalConditions& setFahrenheit(const double f);
    double getFahrenheit() const;

private:
    // update functions to keep coerence over data
    static void updateKelvin();
    static void updateCelsius();
    static void updateFahrenheit();

};

    static const unsigned int minK = 0;
    static const double minC = -273.15 ;
    static const double minF = -459.67;

}

}

#endif // TEMPERATURE_H
