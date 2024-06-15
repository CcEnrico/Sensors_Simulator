//
// Created by enrico on 01/05/24.
//

#ifndef SENSOR_CONVERTER_JSON_READER_H
#define SENSOR_CONVERTER_JSON_READER_H

#include <map>
#include <QJsonObject>
#include "SReader.h"

namespace Sensor::Converter::Json {

    class Reader : public SReader{
    private:
        std::map<unsigned int, AbstractSensor*> cache;
    public:
        const std::map<unsigned int, AbstractSensor*>& getCache() const;
        Reader& clear();
        AbstractSensor* read(const QJsonObject& object) override;

    private:
        static AbstractSensor* readAirQuality(const QJsonObject& object) ;
        static AbstractSensor* readHumidity(const QJsonObject& object) ;
        static AbstractSensor* readTemperature(const QJsonObject& object) ;


    };

}

#endif //SENSOR_CONVERTER_JSON_READER_H
