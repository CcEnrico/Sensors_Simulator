#ifndef SENSOR_CONVERTER_JSON_IREADER_H
#define SENSOR_CONVERTER_JSON_IREADER_H

#include <QJsonObject>
#include "../../AbstractSensor.h"

namespace Sensor::Converter::Json {

    class SReader {
    public:
        virtual ~SReader() = default;
        virtual AbstractSensor* read(const QJsonObject& object) = 0;
    };

}

#endif //SENSOR_CONVERTER_JSON_IREADER_H
