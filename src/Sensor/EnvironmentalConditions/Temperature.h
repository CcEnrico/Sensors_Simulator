#ifndef SENSOR_ENVIROMENTALCONDITION_TEMPERATURE_H
#define SENSOR_ENVIROMENTALCONDITION_TEMPERATURE_H

namespace Sensor::EnviromentalConditions{

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

    double getTempscale(const char& scale) const;

private:

    void updateKelvin();
    void updateCelsius();
    void updateFahrenheit();

public:

    static const double minK;
    static const double minC;
    static const double minF;

};

}

#endif // SENSOR_ENVIROMENTALCONDITION_TEMPERATURE_H
