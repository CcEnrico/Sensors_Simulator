#ifndef SENSOR_CONVERTER_JSON_JSON_H
#define SENSOR_CONVERTER_JSON_JSON_H

#include "SReader.h"

namespace Sensor::Converter::Json {

    class Json {
    private:
        SReader& reader;
    public:
        explicit Json(SReader& reader);
        const SReader& getReader() const;
        static QJsonObject fromObject(const AbstractSensor& item) ;
        AbstractSensor* toObject(const QJsonObject& json) const;
    };

}

#endif //SENSOR_CONVERTER_JSON_JSON_H
