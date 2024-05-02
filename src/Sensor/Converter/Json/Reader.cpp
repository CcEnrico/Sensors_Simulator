//
// Created by enrico on 01/05/24.
//

#include "Reader.h"

namespace Sensor {
    namespace Converter {
        namespace Json {

            const std::map<unsigned int, AbstractSensor*>& Reader::getCache() const{

            }
            Reader& Reader::clear(){

            }
            AbstractSensor* Reader::read(const QJsonObject& object) {

            }

            AbstractSensor* Reader::readAirQuality(const QJsonObject& object) const{

            }
            AbstractSensor* Reader::readHumidity(const QJsonObject& object) const{

            }
            AbstractSensor* Reader::readTemperature(const QJsonObject& object) const{

            }
        } // Json
    } // Converter
} // Sensor