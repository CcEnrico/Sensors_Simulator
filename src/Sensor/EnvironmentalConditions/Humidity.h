#ifndef HUMIDITY_H
#define HUMIDITY_H


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
