#ifndef SENSOR_ENVIROMENTALCONDITION_HUMIDITY_H
#define SENSOR_ENVIROMENTALCONDITION_HUMIDITY_H




namespace Sensor::EnviromentalConditions{


class Humidity
{
    double relativeHumidity;    // %

public:
    explicit Humidity(double rh);

    explicit operator double()const;

    double getRelativeHumidity()const ;
    Humidity& setRelativeHumidity(const double rh);

};

}



#endif // HUMIDITY_H
