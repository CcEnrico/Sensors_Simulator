//
// Created by enrico on 01/05/24.
//

#ifndef SENSOR_CONVERTER_JSON_JSONVISITOR_H
#define SENSOR_CONVERTER_JSON_JSONVISITOR_H

#include <QJsonObject>
#include "../../SConstVisitor.h"
#include "../../Airqualitysensor.h"
#include "../../Humiditysensor.h"
#include "../../TemperatureSensor.h"


namespace Sensor {
    namespace Converter {
        namespace Json {

            class JsonVisitor : public SConstVisitor{
            private:
                QJsonObject object;
            public:
                QJsonObject getObject() const;
                void visit(const AirQualitySensor& air_quality);
                void visit(const HumiditySensor& humidity);
                void visit(const TemperatureSensor& temperature);

            };

        } // Json
    } // Converter
} // Sensor

#endif //SENSOR_CONVERTER_JSON_JSONVISITOR_H
