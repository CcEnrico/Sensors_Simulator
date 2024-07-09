//
// Created by enrico on 01/05/24.
//

#include "Json.h"
#include "JsonVisitor.h"

namespace Sensor::Converter::Json {

    Json::Json(SReader& reader)
        : reader(reader)
    {

    }

    const SReader& Json::getReader() const{
        return reader;
    }
    QJsonObject Json::fromObject(const AbstractSensor& item) {
        JsonVisitor json_visitor;
        item.accept(json_visitor);
        return json_visitor.getObject();
    }
    AbstractSensor* Json::toObject(const QJsonObject& json) const{
        return reader.read(json);
    }

}