#include "SensorList.h"

namespace Engine{
    SensorList::SensorList()
    :sensors(){}

    SensorList::~SensorList() {
        clear();
    }

    SensorList& SensorList::add(const Sensor::AbstractSensor *s) {
        sensors.push_back(s);
        return *this;
    }

    SensorList& SensorList::remove(const Sensor::AbstractSensor *s) {

        for (auto it = sensors.begin(); it != sensors.end(); ++it) {
            if (*it == s){
                delete *it;
                sensors.erase(it);
            }
        }

        return *this;
    }

    SensorList& SensorList::clear() {
        for (auto it = sensors.begin(); it != sensors.end(); ++it) {
            delete *it;
        }
        sensors.clear();
        return *this;
    }

    std::list<const Sensor::AbstractSensor*>& SensorList::getSensors() {
        return sensors;
    }

    std::list<const Sensor::AbstractSensor*>::const_iterator SensorList::begin() const {
        return sensors.begin();
    }

    std::list<const Sensor::AbstractSensor*>::const_iterator SensorList::end() const {
        return sensors.end();
    }


}