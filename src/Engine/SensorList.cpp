#include "SensorList.h"

#include <algorithm>

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

    // deletes abstract item mem alloc
    SensorList& SensorList::remove(const Sensor::AbstractSensor *s) {

        for (auto it = sensors.begin(); it != sensors.end(); ++it) {
            if (*it == s){
                sensors.erase(it);
                delete *it;
                return *this;
            }
        }

        return *this;
    }

    SensorList& SensorList::erase(const Sensor::AbstractSensor *s) {

        for (auto it = sensors.begin(); it != sensors.end(); ++it) {
            if (*it == s){
                sensors.erase(it);
                return *this;
            }
        }

        return *this;
    }

    bool SensorList::isEmpty(){
        return sensors.empty();
    }

    SensorList& SensorList::clean() {
        sensors.clear();
        return *this;
    }

    SensorList& SensorList::clear() {
        for (auto it = sensors.begin(); it != sensors.end(); ++it) {
            delete *it;
//            *it = nullptr;
        }
        sensors.clear();
        return *this;
    }

    bool SensorList::find(const Sensor::AbstractSensor* sensor){
        for (std::list<const Sensor::AbstractSensor*>::const_iterator it = sensors.begin(); it != sensors.end(); ++it) {
            const Sensor::AbstractSensor* current = *it;
            if (current->getIdentifier() == sensor->getIdentifier()) return true;
        }
        return false;
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

    SensorList& SensorList::sort() {
        sensors.sort();
        return *this;
    }

    SensorList* SensorList::search(const std::string& query) const{

        // creo un nuovo oggetto sullo heap
        SensorList* result = new SensorList();

        // ricerca fatta su id e nome
        for (std::list<const Sensor::AbstractSensor*>::const_iterator it = sensors.begin(); it != sensors.end(); ++it) {

            std::string id_string = std::to_string((*it)->getIdentifier());
            if (    // ricerca nella stringa di getname se e' presente la sottoringa query,
                    // se non vengono trovati match la funzione ritorna std::string::npos
                    (id_string).find(query) != std::string::npos ||
                    (*it)->getName().find(query) != std::string::npos
                    )
            {
                result->add(*it);
            }
        }
        result->sort();

        return result;
    }


}