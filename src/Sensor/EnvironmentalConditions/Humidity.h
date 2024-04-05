#ifndef SENSOR_ENVIROMENTALCONDITION_HUMIDITY_H
#define SENSOR_ENVIROMENTALCONDITION_HUMIDITY_H


namespace Sensor{

namespace EnviromentalConditions{


class Humidity
{
    double relativeHumidity;    // %

public:
    Humidity(double rh);

    double getRelativeHumidity()const ;
    Humidity& setRelativeHumidity(const double rh);

};

}

}

#endif // HUMIDITY_H
