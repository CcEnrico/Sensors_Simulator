//
// Created by enrico on 01/05/24.
//

#include "Json.h"
#include "JsonVisitor.h"

namespace Sensor {
    namespace Converter {
        namespace Json {

            Json::Json(SReader& reader)
                : reader(reader)
            {

            }

            const SReader& Json::getReader() const{
                return reader;
            }
            QJsonObject Json::fromObject(const AbstractSensor& item) const{
                JsonVisitor json_visitor;
                item.accept(json_visitor);
                return json_visitor.getObject();
            }
            AbstractSensor* Json::toObject(const QJsonObject& json) const{
                return reader.read(json);
            }

        } // Json
    } // Converter
} // Sensor