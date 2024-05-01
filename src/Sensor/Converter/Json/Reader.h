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
                AbstractSensor* readWebPage(const QJsonObject& object) const;
                AbstractSensor* readSimple(const QJsonObject& object) const;
                AbstractSensor* readVirtual(const QJsonObject& object) const;
                AbstractSensor* readBundle(const QJsonObject& object);


            };

        } // Json
    } // Converter
} // Sensor

#endif //SENSOR_CONVERTER_JSON_READER_H
