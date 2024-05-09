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

                air_quality_sensor_object.insert("initialPm10 micro_g/m3", QJsonValue::fromVariant(air_quality.getAQInitial().getPm10()));
                air_quality_sensor_object.insert("initialN02 micro_g/m3", QJsonValue::fromVariant(air_quality.getAQInitial().getNO2()));
                air_quality_sensor_object.insert("standardDeviationPm10 micro_g/m3", QJsonValue::fromVariant(air_quality.getAQStdDeviation().getPm10()));
                air_quality_sensor_object.insert("standardDeviationN02 micro_g/m3", QJsonValue::fromVariant(air_quality.getAQStdDeviation().getNO2()));

                object = air_quality_sensor_object;
            }
            void JsonVisitor::visit(const HumiditySensor& humidity){

                QJsonObject humidity_sensor_object;
                humidity_sensor_object.insert("type", QJsonValue::fromVariant("humidity_sensor"));
                humidity_sensor_object.insert("id", QJsonValue::fromVariant(humidity.getIdentifier()));
                humidity_sensor_object.insert("name", QJsonValue::fromVariant(humidity.getName().c_str()));
                humidity_sensor_object.insert("dataNumber", QJsonValue::fromVariant(humidity.getDataNum()));

                humidity_sensor_object.insert("initial Relative Humidity", QJsonValue::fromVariant(humidity.getHumInitial().getRelativeHumidity()));
                humidity_sensor_object.insert("initialN02 Relative Humidity", QJsonValue::fromVariant(humidity.getHumStdDeviation().getRelativeHumidity()));
                humidity_sensor_object.insert("Rain Probability", QJsonValue::fromVariant(humidity.getRainProbability()));

                object = humidity_sensor_object;

            }
            void JsonVisitor::visit(const TemperatureSensor& temperature){
                QJsonObject temperature_sensor_object;
                temperature_sensor_object.insert("type", QJsonValue::fromVariant("temperature_sensor"));
                temperature_sensor_object.insert("id", QJsonValue::fromVariant(temperature.getIdentifier()));
                temperature_sensor_object.insert("name", QJsonValue::fromVariant(temperature.getName().c_str()));
                temperature_sensor_object.insert("dataNumber", QJsonValue::fromVariant(temperature.getDataNum()));

                temperature_sensor_object.insert("initial Minimum Temp C°", QJsonValue::fromVariant(temperature.getTempMin().getCelsius()));
                temperature_sensor_object.insert("initial Maximum Temp C°", QJsonValue::fromVariant(temperature.getTempMax().getCelsius()));
                temperature_sensor_object.insert("Initial Temperature C°", QJsonValue::fromVariant(temperature.getTempInitial().getCelsius()));
                temperature_sensor_object.insert("standardDeviation Temp C°", QJsonValue::fromVariant(temperature.getStdDeviation().getCelsius()));

                object = temperature_sensor_object;
            }

        } // Json
    } // Converter
} // Sensor