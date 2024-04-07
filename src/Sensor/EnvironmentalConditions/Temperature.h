#ifndef SENSOR_ENVIROMENTALCONDITION_TEMPERATURE_H
#define SENSOR_ENVIROMENTALCONDITION_TEMPERATURE_H

namespace Sensor{

namespace EnviromentalConditions{

class Temperature
{
    double kelvin;
    double celsius;
    double fahrenheit;

public:
    Temperature(double temperature, char scale);

    explicit operator double()const;

    Temperature& setKelvin(const double k);
    double getKelvin() const;
    Temperature& setCelsius(const double c);
    double getCelsius() const;
    Temperature& setFahrenheit(const double f);
    double getFahrenheit() const;

private:

    void updateKelvin();
    void updateCelsius();
    void updateFahrenheit();

    static const double minK;
    static const double minC;
    static const double minF;

};

}

}

#endif // TEMPERATURE_H
