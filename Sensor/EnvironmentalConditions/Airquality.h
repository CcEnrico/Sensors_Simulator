#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include"Abstractenviromentalcondition.h"

namespace Sensor{

namespace EnviromentalConditions{

class AirQuality: public AbstractEnviromentalCondition
{
    double pm2_5;   //  micro_g/m3 (micrograms per cubic meter)
    double pm10;

public:
    AirQuality();

    double getPm2_5();
    AirQuality& setPm2_5(const double pm2_5);
    double getPm10();
    AirQuality& setPm10(const double pm10);
};

}

}

#endif // AIRQUALITY_H
