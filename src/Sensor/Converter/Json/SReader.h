#ifndef SENSOR_CONVERTER_JSON_IREADER_H
#define SENSOR_CONVERTER_JSON_IREADER_H

#include <QJsonObject>
#include "../../AbstractSensor.h"

namespace Sensor {
    namespace Converter {
        namespace Json {

            class SReader {
            public:
                virtual ~SReader() = default;
                virtual AbstractSensor* read(const QJsonObject& object) = 0;
            };

        } // Json
    } // Converter
} // Item

#endif //SENSOR_CONVERTER_JSON_IREADER_H
