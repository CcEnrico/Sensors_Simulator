#ifndef SENSOR_CONVERTER_JSON_JSON_H
#define SENSOR_CONVERTER_JSON_JSON_H

#include "SReader.h"

namespace Sensor {
    namespace Converter {
        namespace Json {

            class Json {
            private:
                SReader& reader;
            public:
                Json(SReader& reader);
                const SReader& getReader() const;
                QJsonObject fromObject(const AbstractSensor& item) const;
                AbstractSensor* toObject(const QJsonObject& json) const;
            };

        } // Json
    } // Converter
} // Sensor

#endif //SENSOR_CONVERTER_JSON_JSON_H
