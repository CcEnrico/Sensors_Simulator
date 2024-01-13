#ifndef ABSTRACT_SENSOR_H
#define ABSTRACT_SENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Temperature.h"
#include<vector>

namespace Sensor{

class TemperatureSensor{

    EnviromentalConditions::Temperature min;
    EnviromentalConditions::Temperature max;
    EnviromentalConditions::Temperature initial;
    std::vector<EnviromentalConditions::Temperature> temperatures;

public:

};

}

#endif
