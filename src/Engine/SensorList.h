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
        SensorList& remove(const Sensor::AbstractSensor* sensor);   // dealloca e rimuove
        SensorList& erase(const Sensor::AbstractSensor* sensor);    // rimuove
        SensorList& clean();    // non dealloca memoria pulisce solo il contenitore
        SensorList& clear();    // dealloca memoria e pulisce il contenitore
        bool find(const Sensor::AbstractSensor* sensor);
        SensorList& sort();

        bool isEmpty();

        std::list<const Sensor::AbstractSensor*>& getSensors();
        std::list<const Sensor::AbstractSensor*>::const_iterator begin() const;
        std::list<const Sensor::AbstractSensor*>::const_iterator end() const;

        SensorList* search(const std::string& query) const;


    };
}


#endif //ENGINE_SENSOR_LIST_H
