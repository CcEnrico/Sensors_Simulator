//
// Created by enrico on 01/05/24.
//

#ifndef SENSOR_CONVERTER_JSON_READER_H
#define SENSOR_CONVERTER_JSON_READER_H

#include <map>
#include <QJsonObject>
#include "SReader.h"

namespace Sensor {
    namespace Converter {
        namespace Json {

            class Reader : public SReader{
            private:
                std::map<unsigned int, AbstractSensor*> cache;
            public:
                const std::map<unsigned int, AbstractSensor*>& getCache() const;
                Reader& clear();
                AbstractSensor* read(const QJsonObject& object) override;

            private:
                AbstractSensor* readAirQuality(const QJsonObject& object) const;
                AbstractSensor* readHumidity(const QJsonObject& object) const;
                AbstractSensor* readTemperature(const QJsonObject& object) const;


            };

        } // Json
    } // Converter
} // Sensor

#endif //SENSOR_CONVERTER_JSON_READER_H
