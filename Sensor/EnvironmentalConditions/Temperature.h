#ifndef TEMPERATURE_H
#define TEMPERATURE_H

namespace Sensor{

namespace EnviromentalConditions{

class Temperature
{
    double kelvin;
    double celsius;
    double fahrenheit;

public:
    Temperature(double temperature, const char scale);

    Temperature& setKelvin(const double k);
    double getKelvin() const;
    Temperature& setCelsius(const double c);
    double getCelsius() const;
    Temperature& setFahrenheit(const double f);
    double getFahrenheit() const;

private:
    // update functions to keep coerence over data
    void updateKelvin();
    void updateCelsius();
    void updateFahrenheit();

    // absolute zeros T 3 scale

    static const double minK;
    static const double minC;
    static const double minF;

};

}

}

#endif // TEMPERATURE_H
