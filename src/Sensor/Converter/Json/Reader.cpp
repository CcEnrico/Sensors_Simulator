//
// Created by enrico on 01/05/24.
//

#include "Reader.h"

#include "../../Airqualitysensor.h"
#include "../../Humiditysensor.h"
#include "../../TemperatureSensor.h"

namespace Sensor {
    namespace Converter {
        namespace Json {

            const std::map<unsigned int, AbstractSensor*>& Reader::getCache() const{
                return cache;
            }
            Reader& Reader::clear(){
                cache.clear();
                return *this;
            }
            AbstractSensor* Reader::read(const QJsonObject& object) {
                QJsonValue type = object.value("type");
                if (type.isUndefined()) {
                    throw std::invalid_argument("Missing item type.");
                }
                const unsigned int identifier = object.value("id").toInt();
                if (cache.count(identifier) > 0) {
                    return cache[identifier];
                }
                else if (type.toString().compare("air_quality_sensor") == 0) {
                    cache[identifier] = readAirQuality(object);
                }
                else if (type.toString().compare("humidity_sensor") == 0) {
                    cache[identifier] = readHumidity(object);
                }
                else if (type.toString().compare("temperature_sensor") == 0) {
                    cache[identifier] = readTemperature(object);
                }
                else {
                    throw std::invalid_argument("Unknown type.");
                }
                return cache[identifier];
            }

            AbstractSensor* Reader::readAirQuality(const QJsonObject& object) const{
                return new AirQualitySensor(
                        object.value("id").toInt(),
                        object.value("name").toString().toStdString(),
                        object.value("dataNumber").toInt(),
                        0.0,    // variaza da togliere.. ininfluente come Target
                        Sensor::EnviromentalConditions::AirQuality( object.value("initialPm10 micro_g/m3").toDouble(), object.value("initialN02 micro_g/m3").toDouble()),
                        Sensor::EnviromentalConditions::AirQuality( object.value("standardDeviationPm10 micro_g/m3").toDouble(), object.value("standardDeviationN02 micro_g/m3").toDouble()),
                        Sensor::EnviromentalConditions::AirQuality( 0, 0)
                );
            }
            AbstractSensor* Reader::readHumidity(const QJsonObject& object) const{
                return new HumiditySensor(
                        object.value("id").toInt(),
                        object.value("name").toString().toStdString(),
                        object.value("dataNumber").toInt(),
                        0.0,    // variaza da togliere.. ininfluente come Target
                        Sensor::EnviromentalConditions::Humidity( object.value("initial Relative Humidity").toDouble()),
                        Sensor::EnviromentalConditions::Humidity( object.value("initialN02 Relative Humidity").toDouble()),
                        object.value("Rain Probability").toDouble()
                );
            }
            AbstractSensor* Reader::readTemperature(const QJsonObject& object) const{
                char simulation_scale = ' ';

                QString storedString = object["Simulation Scale"].toString();
                if (!storedString.isEmpty()) {
                    simulation_scale = storedString.at(0).toLatin1();
                }

                if (simulation_scale == 'c'){
                    return new TemperatureSensor(
                            object.value("id").toInt(),
                            object.value("name").toString().toStdString(),
                            object.value("dataNumber").toInt(),
                            0.0,    // variaza da togliere.. ininfluente come Target
                            Sensor::EnviromentalConditions::Temperature( object.value("initial Minimum Temp C°").toDouble(), 'c'),
                            Sensor::EnviromentalConditions::Temperature( object.value("initial Maximum Temp C°").toDouble(), 'c'),
                            Sensor::EnviromentalConditions::Temperature( object.value("Initial Temperature C°").toDouble(), 'c'),
                            Sensor::EnviromentalConditions::Temperature( object.value("standardDeviation Temp C°").toDouble(), 'c'),
                            Sensor::EnviromentalConditions::Temperature( 0.0 , 'c'),
                            'c'
                    );
                }
                if (simulation_scale == 'f'){
                    return new TemperatureSensor(
                            object.value("id").toInt(),
                            object.value("name").toString().toStdString(),
                            object.value("dataNumber").toInt(),
                            0.0,    // variaza da togliere.. ininfluente come Target
                            Sensor::EnviromentalConditions::Temperature( object.value("initial Minimum Temp F°").toDouble(), 'f'),
                            Sensor::EnviromentalConditions::Temperature( object.value("initial Maximum Temp F°").toDouble(), 'f'),
                            Sensor::EnviromentalConditions::Temperature( object.value("Initial Temperature F°").toDouble(), 'f'),
                            Sensor::EnviromentalConditions::Temperature( object.value("standardDeviation Temp F°").toDouble(), 'f'),
                            Sensor::EnviromentalConditions::Temperature( 0.0 , 'f'),
                            'f'
                    );
                }
                if (simulation_scale == 'k'){
                    return new TemperatureSensor(
                            object.value("id").toInt(),
                            object.value("name").toString().toStdString(),
                            object.value("dataNumber").toInt(),
                            0.0,    // variaza da togliere.. ininfluente come Target
                            Sensor::EnviromentalConditions::Temperature( object.value("initial Minimum Temp K°").toDouble(), 'k'),
                            Sensor::EnviromentalConditions::Temperature( object.value("initial Maximum Temp K°").toDouble(), 'k'),
                            Sensor::EnviromentalConditions::Temperature( object.value("Initial Temperature K°").toDouble(), 'k'),
                            Sensor::EnviromentalConditions::Temperature( object.value("standardDeviation Temp K°").toDouble(), 'k'),
                            Sensor::EnviromentalConditions::Temperature( 0.0 , 'k'),
                            'k'
                    );
                }
                // altrimenti la scala non e' ben definita
                throw std::invalid_argument("error reading Simulation scale in Json File");

            }
        } // Json
    } // Converter
} // Sensor