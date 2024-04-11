#ifndef ENGINE_SENSOR_LIST_H
#define ENGINE_SENSOR_LIST_H

#include "../Sensor/AbstractSensor.h"

#include <list>

namespace Engine{
    class SensorList {
        std::list<const Sensor::AbstractSensor*> sensors;

    public:
        SensorList();
        ~SensorList();
        SensorList& add(const Sensor::AbstractSensor* sensor);
        SensorList& remove(const Sensor::AbstractSensor* sensor);
        SensorList& clear();

        std::list<const Sensor::AbstractSensor*>& getSensors();
        std::list<const Sensor::AbstractSensor*>::const_iterator begin() const;
        std::list<const Sensor::AbstractSensor*>::const_iterator end() const;
    };
}


#endif //ENGINE_SENSOR_LIST_H
