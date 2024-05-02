//
// Created by enrico on 01/05/24.
//

#include "JsonVisitor.h"

namespace Sensor {
    namespace Converter {
        namespace Json {
            QJsonObject JsonVisitor::getObject() const {
                return object;
            }
            void JsonVisitor::visit(const AirQualitySensor& air_quality){

                QJsonObject air_quality_sensor_object;
                air_quality_sensor_object.insert("type", QJsonValue::fromVariant("air_quality_sensor"));
                air_quality_sensor_object.insert("id", QJsonValue::fromVariant(air_quality.getIdentifier()));
                air_quality_sensor_object.insert("name", QJsonValue::fromVariant(air_quality.getName().c_str()));
                air_quality_sensor_object.insert("dataNumber", QJsonValue::fromVariant(air_quality.getDataNum()));

                air_quality_sensor_object.insert("initialPm10", QJsonValue::fromVariant(air_quality.getAQInitial().getPm10()));
                air_quality_sensor_object.insert("initialN02", QJsonValue::fromVariant(air_quality.getAQInitial().getNO2()));
                air_quality_sensor_object.insert("standardDeviationPm10", QJsonValue::fromVariant(air_quality.getAQStdDeviation().getPm10()));
                air_quality_sensor_object.insert("standardDeviationN02", QJsonValue::fromVariant(air_quality.getAQStdDeviation().getNO2()));

                object = air_quality_sensor_object;
            }
            void JsonVisitor::visit(const HumiditySensor& humidity){

            }
            void JsonVisitor::visit(const TemperatureSensor& temperature){

            }

        } // Json
    } // Converter
} // Sensor