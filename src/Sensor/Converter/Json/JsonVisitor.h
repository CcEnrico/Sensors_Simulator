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

namespace Sensor::Converter::Json {

    class JsonVisitor : public SConstVisitor{
    private:
        QJsonObject object;
    public:
        QJsonObject getObject() const;
        void visit(const AirQualitySensor& air_quality) override;
        void visit(const HumiditySensor& humidity) override;
        void visit(const TemperatureSensor& temperature) override;

    };

}

#endif //SENSOR_CONVERTER_JSON_JSONVISITOR_H
